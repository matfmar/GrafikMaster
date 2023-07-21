
#include "tworker.h"
#include "dto.h"
#include "ttimerclass.h"

TWorker::TWorker(XGrafik* g, std::vector<XDyzurantTworzacy*>* tdt, int ile, QSemaphore* sem, QSemaphore* sem2, QSemaphore* sem3, int sz, QObject* parent)
    : QObject(parent), grafikBazowy(g), tablicaDyzurantowTworzacych(tdt), ileIteracji(ile), semafor(sem), semafor2(sem2),
    semaforLabel(sem3), szybkosc(sz), timerClass(nullptr), subThreadForTimer(nullptr), decyzjaOSkroceniu(nullptr), licznikSkrocen(nullptr) {
    result = new int(-1);
    if (szybkosc != 0) {
        //jeśli uwzględniamy szybkość, trzeba stworzyć klasę dla timera i przełożyć ją do nowego wątku, który potem uruchamiamy
        timerClass = new TTimerClass();
        subThreadForTimer = new QThread();
        timerClass->moveToThread(subThreadForTimer);
        //s-s dla QThread
        QObject::connect(subThreadForTimer, SIGNAL(started()), timerClass, SLOT(process()));
        QObject::connect(timerClass, SIGNAL(finished()), subThreadForTimer, SLOT(quit()));
        QObject::connect(timerClass, SIGNAL(finished()), timerClass, SLOT(deleteLater()));
        QObject::connect(timerClass, SIGNAL(finished()), subThreadForTimer, SLOT(deleteLater()));
        //s-s dla komunikacji z TWorker
        QObject::connect(timerClass, SIGNAL(timeFinishedSignal()), this, SLOT(timePassed()));
        //zaczynamy działanie wątku dla timera
        subThreadForTimer->start();
    }
}

void TWorker::process() {
    bool czyPrzyspieszenie(false);
    if (szybkosc != 0) {
        czyPrzyspieszenie = true;
        decyzjaOSkroceniu = new bool(false);
        licznikSkrocen = new int(0);
    }
    //uruchamiamy liczenie grafików
    grafikBazowy -> wypelnijGrafikDyzurantami(tablicaDyzurantowTworzacych, ileIteracji, this, czyPrzyspieszenie, decyzjaOSkroceniu, licznikSkrocen);
    //niszczymy okienko z progresem
    emit killProgressWindow();
}

void TWorker::startTimer() {
    timerClass->startTimer();       //docelowo - na 3 sekundy, to też restartuje w razie czego
}

void TWorker::timePassed() {
    timerClass->stopTimer();

}

void TWorker::pokazLiczbeInteracji(int a) {
    /*
    if (a % 5 != 0) {
        return;
    }
    */
    emit sendInt(a);
    //a teraz czekamy aż zwolni się semafor - czyli komunikat został wyświetlony, więc można jechać dalej
    semaforLabel->acquire(1);
}

void TWorker::pokazLiczbeObrotow(int a) {

    if (a % 5 != 0) {
        return;
    }

    emit sendIntObroty(a);
    //a teraz czekamy jw.
    semaforLabel->acquire(1);
    //QThread::msleep(200);   //for debugging
}

void TWorker::pokazOknoProgresu() {
    emit showProgressWindow();
}

void TWorker::przymknijOknoProgresu() {
    emit hideProgressWindow();
}

int TWorker::zapytajOKontynuacje() {
    emit showAskWindow(result);
    //a teraz czekamy aż się zwolni semafor - czyli zmienna result będzie gotowa
    semafor->acquire(1);
    //zmienna result jest gotowa, więc...
    return *result;
}

void TWorker::pokazKomunikatZakonczeniaSzukania(bool wynikTworzeniaGrafikow, int ileGrafikow) {
    emit showEndCommunicate(wynikTworzeniaGrafikow, ileGrafikow);
    //a teraz czekamy aż user zaakceptuje koniec tworzenia grafików
    semafor2->acquire(1);
}

TWorker::~TWorker() {
    if (result != nullptr) {
        delete result;
        result = nullptr;
    }
    if (timerClass != nullptr) {
        delete timerClass;
        timerClass = nullptr;
    }
    if (subThreadForTimer != nullptr) {
        if (subThreadForTimer->isRunning()) {
            subThreadForTimer->terminate();
        }
        delete subThreadForTimer;
        subThreadForTimer = nullptr;
    }

}

