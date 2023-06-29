
#include "mdyzuranci.h"
#include "dbobslugiwaczbazydanych.h"
#include "dto.h"

MDyzuranci::MDyzuranci()
    : dbObslugiwaczBazyDanych(nullptr) {
    dbObslugiwaczBazyDanych = new DBObslugiwaczBazyDanych();

}

std::vector<XDyzurant*>* MDyzuranci::wyciagnijTabliceDyzurantow() {
    tablicaDyzurantow = dbObslugiwaczBazyDanych -> getTablicaDyzurantowFull();
    return tablicaDyzurantow;
}

XDyzurant* MDyzuranci::pokazDaneJednegoDyzuranta(int id) {
    if (tablicaDyzurantow == nullptr) {
        return nullptr;
    }
    return ((*tablicaDyzurantow)[id]);
}

std::vector<XDyzurant*>* MDyzuranci::dodajNowegoDyzuranta(std::string nick, int priorytet, bool& result) {
    int liczbaDyzurantow = tablicaDyzurantow->size();
    XDyzurant* nowyDyzurant = new XDyzurant(liczbaDyzurantow, nick, priorytet);
    tablicaDyzurantow -> push_back(nowyDyzurant);
    result = dbObslugiwaczBazyDanych -> writeListaDyzurantowFull(tablicaDyzurantow);
    if (!result) {
        tablicaDyzurantow->pop_back();
        delete nowyDyzurant;
        nowyDyzurant = nullptr;
    }
    return tablicaDyzurantow;
}

MDyzuranci::~MDyzuranci() {
    if (dbObslugiwaczBazyDanych != nullptr) {
        delete dbObslugiwaczBazyDanych;
        dbObslugiwaczBazyDanych = nullptr;
    }
    if (tablicaDyzurantow != nullptr) {
        delete tablicaDyzurantow;
        tablicaDyzurantow = nullptr;
    }
}
