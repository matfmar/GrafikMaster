
#include "pedycjabazydyzurantow.h"
#include "uiedycjabazydyzurantow.h"
#include "uidodawanienowegodyzuranta.h"
#include "mdyzuranci.h"
#include "dto.h"

PEdycjaBazyDyzurantow::PEdycjaBazyDyzurantow()
    : uiEdycjaBazyDyzurantow(nullptr), mDyzuranci(nullptr), uiDodawanieNowegoDyzuranta(nullptr) {
    mDyzuranci = new MDyzuranci();
    std::vector<XDyzurant*>* tablicaDyzurantow = mDyzuranci -> wyciagnijTabliceDyzurantow();
    uiEdycjaBazyDyzurantow = new UIEdycjaBazyDyzurantow(tablicaDyzurantow, this, nullptr);
    uiEdycjaBazyDyzurantow -> show();
}

void PEdycjaBazyDyzurantow::wybranoDodanieNowegoDyzuranta() {
    uiDodawanieNowegoDyzuranta = new UIDodawanieNowegoDyzuranta(this);
    uiDodawanieNowegoDyzuranta -> show();
}

void PEdycjaBazyDyzurantow::wybranoPrawdziweDodanieNowegoDyzuranta(QString nick, int priorytet) {
    bool result(false);
    std::vector<XDyzurant*>* tablicaDyzurantow = mDyzuranci -> dodajNowegoDyzuranta(nick.toStdString(), priorytet, result);
    uiEdycjaBazyDyzurantow -> aktualizujTabeleDyzurantow(tablicaDyzurantow, result);
    uiDodawanieNowegoDyzuranta -> close();
}

void PEdycjaBazyDyzurantow::wybranoUpdateDyzuranta() {

}

void PEdycjaBazyDyzurantow::wybranoUsuniecieDyzuranta() {

}

XDyzurant* PEdycjaBazyDyzurantow::wybranoPokazanieSzczegolowDyzuranta(int id) {
    return (mDyzuranci -> pokazDaneJednegoDyzuranta(id));
}

PEdycjaBazyDyzurantow::~PEdycjaBazyDyzurantow() {
    if (uiEdycjaBazyDyzurantow != nullptr) {
        delete uiEdycjaBazyDyzurantow;
        uiEdycjaBazyDyzurantow = nullptr;
    }
    if (mDyzuranci != nullptr) {
        delete mDyzuranci;
        mDyzuranci = nullptr;
    }
    if (uiDodawanieNowegoDyzuranta != nullptr) {
        delete uiDodawanieNowegoDyzuranta;
        uiDodawanieNowegoDyzuranta = nullptr;
    }
}
