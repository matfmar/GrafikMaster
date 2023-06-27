
#include "pedycjabazydyzurantow.h"
#include "uiedycjabazydyzurantow.h"

PEdycjaBazyDyzurantow::PEdycjaBazyDyzurantow()
    : uiEdycjaBazyDyzurantow(nullptr) {
    uiEdycjaBazyDyzurantow = new UIEdycjaBazyDyzurantow(this, nullptr);
    uiEdycjaBazyDyzurantow -> show();
}

void PEdycjaBazyDyzurantow::wybranoDodanieNowegoDyzuranta() {

}

void PEdycjaBazyDyzurantow::wybranoUpdateDyzuranta() {

}

void PEdycjaBazyDyzurantow::wybranoUsuniecieDyzuranta() {

}

PEdycjaBazyDyzurantow::~PEdycjaBazyDyzurantow() {
    if (uiEdycjaBazyDyzurantow != nullptr) {
        delete uiEdycjaBazyDyzurantow;
        uiEdycjaBazyDyzurantow = nullptr;
    }
}
