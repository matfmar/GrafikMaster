
#include "pprogress.h"
#include "uitworzenieprogress.h"
#include "pdecydowanieokontynuacjiszukaniagrafikow.h"

PProgress::PProgress(QSemaphore* sem, QSemaphore* sem2, QSemaphore* sem3, QObject *parent)
    : QObject{parent}, semafor(sem), semafor2(sem2), semaforLabel(sem3)
{
    uiTworzenieProgress = new UITworzenieProgress(this);
    QObject::connect(uiTworzenieProgress, SIGNAL(buttonZakonczClicked()), this, SLOT(zakonczTworzenie()), Qt::QueuedConnection);    //zeby nie blokowac okna progresu
    pDecydowanieOKontynuacjiSzukaniaGrafikow = new PDecydowanieOKontynuacjiSzukaniaGrafikow();
}

void PProgress::pokazOknoProgress() {
    if (uiTworzenieProgress != nullptr) {
        uiTworzenieProgress->show();
    }
    else {
        uiTworzenieProgress = new UITworzenieProgress(this);
        QObject::connect(uiTworzenieProgress, SIGNAL(buttonZakonczClicked()), this, SLOT(zakonczTworzenie()), Qt::QueuedConnection);
        uiTworzenieProgress->show();
    }
}

void PProgress::zakonczTworzenie() {
    emit sygnalizujeWymuszenieZakonczeniaTworzenia();
}

void PProgress::setLabelOknoProgress(int ileGrafikow) {
    uiTworzenieProgress->setLabelIleGrafikow(ileGrafikow);
    semaforLabel->release(1);       //zwalniamy szukanie dalszych grafików
}

void PProgress::setLabelObrotyOknoProgress(int ileObrotow) {
    uiTworzenieProgress->setLabelIleObrotow(ileObrotow);
    semaforLabel->release(1);       //jw.
}

void PProgress::przymknijOknoProgress() {
    if (uiTworzenieProgress != nullptr) {
        uiTworzenieProgress->hide();
    }
    else {
        uiTworzenieProgress = new UITworzenieProgress(this);
        QObject::connect(uiTworzenieProgress, SIGNAL(buttonZakonczClicked()), this, SLOT(zakonczTworzenie()), Qt::QueuedConnection);
    }
}

void PProgress::showOknoProgress() {
    if (uiTworzenieProgress != nullptr) {
        uiTworzenieProgress->show();
    }
    else {
        uiTworzenieProgress = new UITworzenieProgress(this);
        QObject::connect(uiTworzenieProgress, SIGNAL(buttonZakonczClicked()), this, SLOT(zakonczTworzenie()), Qt::QueuedConnection);
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
