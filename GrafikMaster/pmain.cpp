
#include "pmain.h"
#include "uimainwindow.h"
#include "pedycjabazydyzurantow.h"
#include "pdodawanienowegografiku.h"
#include "pprzegladaniegrafikowroboczych.h"
#include "pprzegladaniegrafikowostatecznych.h"

PMain::PMain()
    : uiMainWindow(nullptr), pEdycjaBazyDyzurantow(nullptr), pDodawanieNowegoGrafiku(nullptr),
    pPrzegladanieGrafikowRoboczych(nullptr), pPrzegladanieGrafikowOstatecznych(nullptr) {
    uiMainWindow = new UIMainWindow(this, nullptr);
    uiMainWindow -> show();
}


void PMain::wybranoEdycjeBazyDyzurantow() {
    if (pPrzegladanieGrafikowRoboczych != nullptr) {
        delete pPrzegladanieGrafikowRoboczych;
        pPrzegladanieGrafikowRoboczych = nullptr;
    }
    if (pDodawanieNowegoGrafiku != nullptr) {
        delete pDodawanieNowegoGrafiku;
        pDodawanieNowegoGrafiku = nullptr;
    }        
    if (pPrzegladanieGrafikowOstatecznych != nullptr) {
        delete pPrzegladanieGrafikowOstatecznych;
        pPrzegladanieGrafikowOstatecznych = nullptr;
    }       
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
    if (pPrzegladanieGrafikowRoboczych != nullptr) {
        delete pPrzegladanieGrafikowRoboczych;
        pPrzegladanieGrafikowRoboczych = nullptr;
    }
    if (pPrzegladanieGrafikowOstatecznych != nullptr) {
        delete pPrzegladanieGrafikowOstatecznych;
        pPrzegladanieGrafikowOstatecznych = nullptr;
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
    if (pEdycjaBazyDyzurantow != nullptr) {
        delete pEdycjaBazyDyzurantow;
        pEdycjaBazyDyzurantow = nullptr;
    }    
    if (pPrzegladanieGrafikowRoboczych != nullptr) {
        delete pPrzegladanieGrafikowRoboczych;
        pPrzegladanieGrafikowRoboczych = nullptr;
    }
    if (pPrzegladanieGrafikowOstatecznych != nullptr) {
        delete pPrzegladanieGrafikowOstatecznych;
        pPrzegladanieGrafikowOstatecznych = nullptr;
    }       
    if (pDodawanieNowegoGrafiku != nullptr) {
        delete pDodawanieNowegoGrafiku;
        pDodawanieNowegoGrafiku = nullptr;
    }    
    pPrzegladanieGrafikowRoboczych = new PPrzegladanieGrafikowRoboczych();
    pPrzegladanieGrafikowRoboczych->pokazOknoPrzegladaniaGrafikow();
}

void PMain::wybranoPrzegladanieGrafikowOstatecznych() {
    if (pEdycjaBazyDyzurantow != nullptr) {
        delete pEdycjaBazyDyzurantow;
        pEdycjaBazyDyzurantow = nullptr;
    }    
    if (pPrzegladanieGrafikowRoboczych != nullptr) {
        delete pPrzegladanieGrafikowRoboczych;
        pPrzegladanieGrafikowRoboczych = nullptr;
    }
    if (pPrzegladanieGrafikowOstatecznych != nullptr) {
        delete pPrzegladanieGrafikowOstatecznych;
        pPrzegladanieGrafikowOstatecznych = nullptr;
    }    
    if (pDodawanieNowegoGrafiku != nullptr) {
        delete pDodawanieNowegoGrafiku;
        pDodawanieNowegoGrafiku = nullptr;
    }    
    pPrzegladanieGrafikowOstatecznych = new PPrzegladanieGrafikowOstatecznych();
    pPrzegladanieGrafikowOstatecznych->pokazOknoPrzegladaniaGrafikow();
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
    if (pPrzegladanieGrafikowOstatecznych != nullptr) {
        delete pPrzegladanieGrafikowOstatecznych;
        pPrzegladanieGrafikowOstatecznych = nullptr;
    }       
}
