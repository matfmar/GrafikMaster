
#include "pmain.h"
#include "uimainwindow.h"
#include "pedycjabazydyzurantow.h"
#include "pdodawanienowegografiku.h"
#include "pprzegladaniegrafikowroboczych"

PMain::PMain()
    : uiMainWindow(nullptr), pEdycjaBazyDyzurantow(nullptr), pDodawanieNowegoGrafiku(nullptr),
    pPrzegladanieGrafikowRoboczych(nullptr) {
    uiMainWindow = new UIMainWindow(this, nullptr);
    uiMainWindow -> show();
}


void PMain::wybranoEdycjeBazyDyzurantow() {
    if (pEdycjaBazyDyzurantow == nullptr) {
        pEdycjaBazyDyzurantow = new PEdycjaBazyDyzurantow();
    }
    else {
        delete pEdycjaBazyDyzurantow;
        pEdycjaBazyDyzurantow = nullptr;
        pEdycjaBazyDyzurantow = new PEdycjaBazyDyzurantow();
    }
}

void PMain::wybranoDodanieNowegoGrafiku() {
    //kończymy jakiekolwiek modyfikacje bazy dyżurantów...
    if (pEdycjaBazyDyzurantow != nullptr) {
        delete pEdycjaBazyDyzurantow;
        pEdycjaBazyDyzurantow = nullptr;
    }
    //...i tworzymy klasę prezentującą do tworzenia nowego grafiku
    if (pDodawanieNowegoGrafiku == nullptr) {
        pDodawanieNowegoGrafiku = new PDodawanieNowegoGrafiku();
    }
    else {
        delete pDodawanieNowegoGrafiku;
        pDodawanieNowegoGrafiku = nullptr;
        pDodawanieNowegoGrafiku = new PDodawanieNowegoGrafiku();
    }
}

void PMain::wybranoZakonczenieTworzeniaGrafikow() {
    if (pDodawanieNowegoGrafiku != nullptr) {
        delete pDodawanieNowegoGrafiku;
        pDodawanieNowegoGrafiku = nullptr;
    }
}

void PMain::wybranoPrzegladanieGrafikowRoboczych() {
    pPrzegladanieGrafikowRoboczych = new PPrzegladanieGrafikowRoboczych();
    pPrzegladanieGrafikowRoboczych->pokazOknoWyswietlaniaGrafikow();
}

void PMain::wybranoPrzegladanieGrafikowOstatecznych() {

}


PMain::~PMain() {
    if (uiMainWindow != nullptr) {
        delete uiMainWindow;
        uiMainWindow = nullptr;
    }
    if (pEdycjaBazyDyzurantow != nullptr) {
        delete pEdycjaBazyDyzurantow;
        pEdycjaBazyDyzurantow = nullptr;
    }
    if (pDodawanieNowegoGrafiku != nullptr) {
        delete pDodawanieNowegoGrafiku;
        pDodawanieNowegoGrafiku = nullptr;
    }
    if (pPrzegladanieGrafikowRoboczych != nullptr) {
        delete pPrzegladanieGrafikowRoboczych;
        pPrzegladanieGrafikowRoboczych = nullptr;
    }
}
