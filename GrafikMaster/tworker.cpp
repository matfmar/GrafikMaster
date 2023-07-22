
#include "tworker.h"
#include "dto.h"
#include "ttimerclass.h"
#include <QDebug>
#include "ttimerthread.h"

TWorker::TWorker(XGrafik* g, std::vector<XDyzurantTworzacy*>* tdt, int ile, QSemaphore* sem, QSemaphore* sem2, QSemaphore* sem3, int sz, QObject* parent)
    : QObject(parent), grafikBazowy(g), tablicaDyzurantowTworzacych(tdt), ileIteracji(ile), semafor(sem), semafor2(sem2),
    semaforLabel(sem3), szybkosc(sz), timerClass(nullptr), subThreadForTimer(nullptr), decyzjaOSkroceniu(nullptr), licznikSkrocen(nullptr),
    mutex(nullptr), timer(nullptr), aktualneSkrocenie(sz), licznikPowtorzenDanegoSkrocenia(0), licznikPetliSkrocen(0) {

    result = new int(-1);
    if (szybkosc != 0) {
        //jeśli uwzględniamy szybkość, trzeba stworzyć klasę dla timera i przełożyć ją do nowego wątku, który potem uruchamiamy
        timerClass = new TTimerClass();
        subThreadForTimer = new TTimerThread();
        timerClass->moveToThread(subThreadForTimer);
        //s-s dla QThread
        QObject::connect(subThreadForTimer, SIGNAL(started()), timerClass, SLOT(process()));
        QObject::connect(timerClass, SIGNAL(finished()), subThreadForTimer, SLOT(quit()));
        QObject::connect(timerClass, SIGNAL(finished()), timerClass, SLOT(deleteLater()));
        QObject::connect(timerClass, SIGNAL(finished()), subThreadForTimer, SLOT(deleteLater()));
        //s-s dla komunikacji z TTimerClass
        QObject::connect(timerClass, SIGNAL(timeFinishedSignal()), this, SLOT(timePassed()), Qt::DirectConnection); //zeby slot uruchamiał się w wątku timera
        QObject::connect(this, SIGNAL(startTheTimer()), timerClass, SLOT(startTheTimerFromOutside()));
        //tworzymy mutex dla grafików
        mutex = new QMutex();
        //zaczynamy działanie wątku dla timera
        subThreadForTimer->start();
        switch (szybkosc) {
            case 3: licznikPetliSkrocen = 3; break;
            case 5: licznikPetliSkrocen = 2; break;
            case 10: licznikPetliSkrocen = 1; break;
            default: licznikPetliSkrocen = 3; break;
        }
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
    grafikBazowy -> wypelnijGrafikDyzurantami(tablicaDyzurantowTworzacych, ileIteracji, this, czyPrzyspieszenie, decyzjaOSkroceniu, licznikSkrocen, mutex);

    //teraz jesteśmy już po zakończeniu tworzenia grafików
    //w razie działania z przyspieszaczem niszczymy TimerClass (czyli też i zegar) oraz zatrzymujemy wątek
    if (szybkosc != 0) {
        timerClass->stopTimerTC();
        delete timerClass;
        timerClass = nullptr;
        subThreadForTimer->quit();
    }
    //niszczymy okienko z progresem
    emit killProgressWindow();
}

void TWorker::startTimerX() {
    emit startTheTimer();       //docelowo na 3 sekundy
}

void TWorker::obliczIloscSkrocen() {
//algorytm działa następująco: dla szybkosci 3,5,10 dane skrócenie powtarzane jest odp. 3,2,1 razy,
//a następnie wielkość skrócenia jest zwiększana o odp. 3,5,10.
//jeśli skrót przekracza 27, z powrotem zaczynamy od pierwszej wersji.
    if (aktualneSkrocenie > 27) {
        aktualneSkrocenie = szybkosc;
        return aktualneSkrocenie;
    }
    if (licznikPowtorzenDanegoSkrocenia < licznikPetliSkrocen) {
        licznikPowtorzenDanegoSkrocenia++;
        return aktualneSkrocenie;
    }
    else {
        licznikPowtorzenDanegoSkrocenia = 0;
        aktualneSkrocenie += szybkosc;
        return aktualneSkrocenie;
    }
}

void TWorker::timePassed() {
    //blokujemy dostęp do danych
    mutex->lock();
    //ustawiamy odpowiednio zmienne sterujace
    *decyzjaOSkroceniu = true;
    *licznikSkrocen = obliczIloscSkrocen();     //czyli 3, 5 lub 10
    //odblokowujemy dostęp
    mutex->unlock();
}

void TWorker::pokazLiczbeInteracji(int a) {
    emit sendInt(a);
    //a teraz czekamy aż zwolni się semafor - czyli komunikat został wyświetlony, więc można jechać dalej
    semaforLabel->acquire(1);
}

void TWorker::pokazLiczbeObrotow(int a) {
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
    if (mutex != nullptr) {
        delete mutex;
        mutex = nullptr;
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
    if (decyzjaOSkroceniu != nullptr) {
        delete decyzjaOSkroceniu;
        decyzjaOSkroceniu = nullptr;
    }
    if (licznikSkrocen != nullptr) {
        delete licznikSkrocen;
        licznikSkrocen = nullptr;
    }
    if (timer != nullptr) {
        if (timer->isActive()) {
            timer->stop();
        }
        delete timer;
        timer = nullptr;
    }

}

