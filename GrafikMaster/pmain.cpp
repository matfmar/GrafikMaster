
#include "pmain.h"
#include "uimainwindow.h"
#include "pedycjabazydyzurantow.h"

PMain::PMain()
    : uiMainWindow(nullptr), pEdycjaBazyDyzurantow(nullptr) {
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

}

void PMain::wybranoPrzegladanieGrafikowRoboczych() {

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
}
