
#include "pdecydowanieokontynuacjiszukaniagrafikow.h"
#include "uidecydowanieokoniecznosciszukaniagrafikow.h"

#include <QDialog>

PDecydowanieOKontynuacjiSzukaniaGrafikow::PDecydowanieOKontynuacjiSzukaniaGrafikow() {
    if (uiDecydowanieOKoniecznosciSzukaniaGrafikow != nullptr) {
        delete uiDecydowanieOKoniecznosciSzukaniaGrafikow;
        uiDecydowanieOKoniecznosciSzukaniaGrafikow = nullptr;
    }
    uiDecydowanieOKoniecznosciSzukaniaGrafikow = new UIDecydowanieOKoniecznosciSzukaniaGrafikow();
}

void PDecydowanieOKontynuacjiSzukaniaGrafikow::pokazOknoWyboruOpcji() {
    uiDecydowanieOKoniecznosciSzukaniaGrafikow->exec(); //BLOKUJE PROGRAM, dając użytkownikowi czas na decyzję
}

void PDecydowanieOKontynuacjiSzukaniaGrafikow::pokazKomunikatZakonczeniaSzukania() {
    uiDecydowanieOKoniecznosciSzukaniaGrafikow->show();
    uiDecydowanieOKoniecznosciSzukaniaGrafikow->wyswietlKomunikatZakonczeniaSzukania();
}

PDecydowanieOKontynuacjiSzukaniaGrafikow::~PDecydowanieOKontynuacjiSzukaniaGrafikow() {
    if (uiDecydowanieOKoniecznosciSzukaniaGrafikow != nullptr) {
        delete uiDecydowanieOKoniecznosciSzukaniaGrafikow;
        uiDecydowanieOKoniecznosciSzukaniaGrafikow = nullptr;
    }
}
