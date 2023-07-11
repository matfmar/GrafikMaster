
#include "pdecydowanieokontynuacjiszukaniagrafikow.h"
#include "uidecydowanieokoniecznosciszukaniagrafikow.h"

#include <QDialog>

PDecydowanieOKontynuacjiSzukaniaGrafikow::PDecydowanieOKontynuacjiSzukaniaGrafikow()
    : decyzjaUzytkownika(2), uiDecydowanieOKoniecznosciSzukaniaGrafikow(nullptr) {   //domyślnie koniec szukania - gdyby użytkownik zamknął okno zamiast kliknąć odpowiedni przycisk
}

int PDecydowanieOKontynuacjiSzukaniaGrafikow::pokazOknoWyboruOpcji() {
    if (uiDecydowanieOKoniecznosciSzukaniaGrafikow != nullptr) {
        delete uiDecydowanieOKoniecznosciSzukaniaGrafikow;
        uiDecydowanieOKoniecznosciSzukaniaGrafikow = nullptr;
    }
    uiDecydowanieOKoniecznosciSzukaniaGrafikow = new UIDecydowanieOKoniecznosciSzukaniaGrafikow(this);
    uiDecydowanieOKoniecznosciSzukaniaGrafikow->exec(); //BLOKUJE PROGRAM, dając użytkownikowi czas na decyzję
    return decyzjaUzytkownika;
}

void PDecydowanieOKontynuacjiSzukaniaGrafikow::pokazKomunikatZakonczeniaSzukania(bool result) {
    uiDecydowanieOKoniecznosciSzukaniaGrafikow->show();
    uiDecydowanieOKoniecznosciSzukaniaGrafikow->wyswietlKomunikatZakonczeniaSzukania(result);
}

void PDecydowanieOKontynuacjiSzukaniaGrafikow::setDecyzjaUzytkownika(int d) {
    decyzjaUzytkownika = d;
}

PDecydowanieOKontynuacjiSzukaniaGrafikow::~PDecydowanieOKontynuacjiSzukaniaGrafikow() {
    if (uiDecydowanieOKoniecznosciSzukaniaGrafikow != nullptr) {
        delete uiDecydowanieOKoniecznosciSzukaniaGrafikow;
        uiDecydowanieOKoniecznosciSzukaniaGrafikow = nullptr;
    }
}
