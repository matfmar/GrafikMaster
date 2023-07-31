
#include "pdecydowanieokontynuacjiszukaniagrafikow.h"
#include "uidecydowanieokoniecznosciszukaniagrafikow.h"
#include "pprzegladaniegrafikowroboczych.h"

#include <QDialog>

PDecydowanieOKontynuacjiSzukaniaGrafikow::PDecydowanieOKontynuacjiSzukaniaGrafikow()
    : uiDecydowanieOKoniecznosciSzukaniaGrafikow(nullptr), decyzjaUzytkownika(2),
    pPrzegladanieGrafikowRoboczych(nullptr) {   //domyślnie koniec szukania - gdyby użytkownik zamknął okno zamiast kliknąć odpowiedni przycisk
    uiDecydowanieOKoniecznosciSzukaniaGrafikow = new UIDecydowanieOKoniecznosciSzukaniaGrafikow(this);
}

int PDecydowanieOKontynuacjiSzukaniaGrafikow::pokazOknoWyboruOpcji(int ileGrafikow) {
    if (uiDecydowanieOKoniecznosciSzukaniaGrafikow != nullptr) {
        delete uiDecydowanieOKoniecznosciSzukaniaGrafikow;
        uiDecydowanieOKoniecznosciSzukaniaGrafikow = nullptr;
    }
    uiDecydowanieOKoniecznosciSzukaniaGrafikow = new UIDecydowanieOKoniecznosciSzukaniaGrafikow(this);
    uiDecydowanieOKoniecznosciSzukaniaGrafikow->setLabel(ileGrafikow);
    uiDecydowanieOKoniecznosciSzukaniaGrafikow->exec(); //BLOKUJE PROGRAM, dając użytkownikowi czas na decyzję
    if (pPrzegladanieGrafikowRoboczych != nullptr) {
        delete pPrzegladanieGrafikowRoboczych;
        pPrzegladanieGrafikowRoboczych = nullptr;
    }
    return decyzjaUzytkownika;
}

void PDecydowanieOKontynuacjiSzukaniaGrafikow::pokazKomunikatZakonczeniaSzukania(bool result, int ileGrafikow) {
    if (uiDecydowanieOKoniecznosciSzukaniaGrafikow != nullptr) {
        delete uiDecydowanieOKoniecznosciSzukaniaGrafikow;
        uiDecydowanieOKoniecznosciSzukaniaGrafikow = nullptr;
    }
    uiDecydowanieOKoniecznosciSzukaniaGrafikow = new UIDecydowanieOKoniecznosciSzukaniaGrafikow(this);
    uiDecydowanieOKoniecznosciSzukaniaGrafikow->setLabel(ileGrafikow);
    uiDecydowanieOKoniecznosciSzukaniaGrafikow->show();
    uiDecydowanieOKoniecznosciSzukaniaGrafikow->wyswietlKomunikatZakonczeniaSzukania(result, ileGrafikow);
}

void PDecydowanieOKontynuacjiSzukaniaGrafikow::setDecyzjaUzytkownika(int d) {
    decyzjaUzytkownika = d;
}

/*void PDecydowanieOKontynuacjiSzukaniaGrafikow::przegladajGrafiki() {
    if (pPrzegladanieGrafikowRoboczych != nullptr) {
        delete pPrzegladanieGrafikowRoboczych;
        pPrzegladanieGrafikowRoboczych = nullptr;
    }
    pPrzegladanieGrafikowRoboczych = new PPrzegladanieGrafikowRoboczych();
    pPrzegladanieGrafikowRoboczych->pokazOknoPrzegladaniaGrafikow();
}*/

PDecydowanieOKontynuacjiSzukaniaGrafikow::~PDecydowanieOKontynuacjiSzukaniaGrafikow() {
    if (uiDecydowanieOKoniecznosciSzukaniaGrafikow != nullptr) {
        delete uiDecydowanieOKoniecznosciSzukaniaGrafikow;
        uiDecydowanieOKoniecznosciSzukaniaGrafikow = nullptr;
    }
    if (pPrzegladanieGrafikowRoboczych != nullptr) {
        delete pPrzegladanieGrafikowRoboczych;
        pPrzegladanieGrafikowRoboczych = nullptr;
    }
}
