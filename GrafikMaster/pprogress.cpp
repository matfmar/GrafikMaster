
#include "pprogress.h"
#include "uitworzenieprogress.h"
#include "pdecydowanieokontynuacjiszukaniagrafikow.h"

PProgress::PProgress(QSemaphore* sem, QSemaphore* sem2, QObject *parent)
    : QObject{parent}, semafor(sem), semafor2(sem2)
{
    uiTworzenieProgress = new UITworzenieProgress(this);
    pDecydowanieOKontynuacjiSzukaniaGrafikow = new PDecydowanieOKontynuacjiSzukaniaGrafikow();
}

void PProgress::pokazOknoProgress() {
    if (uiTworzenieProgress != nullptr) {
        uiTworzenieProgress->show();
    }
    else {
        uiTworzenieProgress = new UITworzenieProgress(this);
        uiTworzenieProgress->show();
    }
}

void PProgress::setLabelOknoProgress(int ileGrafikow) {
    uiTworzenieProgress->setLabelIleGrafikow(ileGrafikow);
}

void PProgress::przymknijOknoProgress() {
    if (uiTworzenieProgress != nullptr) {
        uiTworzenieProgress->hide();
    }
    else {
        uiTworzenieProgress = new UITworzenieProgress(this);
    }
}

void PProgress::showOknoProgress() {
    if (uiTworzenieProgress != nullptr) {
        uiTworzenieProgress->show();
    }
    else {
        uiTworzenieProgress = new UITworzenieProgress(this);
        uiTworzenieProgress->show();
    }
}

void PProgress::killOknoProgress() {
    if (uiTworzenieProgress != nullptr) {
        delete uiTworzenieProgress;
        uiTworzenieProgress = nullptr;
    }
}

void PProgress::showAskWindow(int* result) {
    if (result == nullptr) {
        return;
    }
    int wynik = pDecydowanieOKontynuacjiSzukaniaGrafikow->pokazOknoWyboruOpcji();
    *result = wynik;
    semafor->release(1);    //tym sposobem wynik będzie gotowy do zjedzenia
}

void PProgress::showEndCommunicate(bool result, int ile) {
    pDecydowanieOKontynuacjiSzukaniaGrafikow->pokazKomunikatZakonczeniaSzukania(result, ile);
    delete pDecydowanieOKontynuacjiSzukaniaGrafikow;
    pDecydowanieOKontynuacjiSzukaniaGrafikow = nullptr;
    semafor2->release(1);
}

PProgress::~PProgress() {
    if (uiTworzenieProgress != nullptr) {
        delete uiTworzenieProgress;
        uiTworzenieProgress = nullptr;
    }
    if (pDecydowanieOKontynuacjiSzukaniaGrafikow != nullptr) {
        delete pDecydowanieOKontynuacjiSzukaniaGrafikow;
        pDecydowanieOKontynuacjiSzukaniaGrafikow = nullptr;
    }
}
