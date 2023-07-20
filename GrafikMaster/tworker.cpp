
#include "tworker.h"
#include "dto.h"

TWorker::TWorker(XGrafik* g, std::vector<XDyzurantTworzacy*>* tdt, int ile, QSemaphore* sem, QSemaphore* sem2, QObject* parent)
    : QObject(parent), grafikBazowy(g), tablicaDyzurantowTworzacych(tdt), ileIteracji(ile), semafor(sem), semafor2(sem2) {
    result = new int(-1);
}

void TWorker::process() {
    //uruchamiamy liczenie grafików
    grafikBazowy -> wypelnijGrafikDyzurantami(tablicaDyzurantowTworzacych, ileIteracji, this);
    //niszczymy okienko z progresem
    emit killProgressWindow();
}

void TWorker::pokazLiczbeInteracji(int a) {
    emit sendInt(a);
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
}

