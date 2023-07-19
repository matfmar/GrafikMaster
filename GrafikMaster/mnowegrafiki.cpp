
#include "mnowegrafiki.h"
#include "dto.h"
#include "dbobslugiwaczbazydanych.h"
#include <QDebug>

MNoweGrafiki::MNoweGrafiki()
    : nowyGrafik(nullptr), tablicaDyzurantowTworzacych(nullptr), db(nullptr) {
    wypelnijTabliceEnumeracyjne();
}

void MNoweGrafiki::wypelnijTabliceEnumeracyjne() {
    tablicaMiesiecy = {STYCZEN, LUTY, MARZEC, KWIECIEN, MAJ, CZERWIEC, LIPIEC, SIERPIEN, WRZESIEN, PAZDZIERNIK, LISTOPAD, GRUDZIEN};
    tablicaDniTygodnia = {PONIEDZIALEK, WTOREK, SRODA, CZWARTEK, PIATEK, SOBOTA, NIEDZIELA};

}

void MNoweGrafiki::wyciagnijTabliceMiesiecyIDniTygodnia(std::vector<Miesiac>& tabM, std::vector<DzienTygodnia>& tabDT) {
    tabM = tablicaMiesiecy;
    tabDT = tablicaDniTygodnia;
}

XGrafik* MNoweGrafiki::utworzNowyGrafik(int r, int ld, Miesiac m, DzienTygodnia dt) {
    nowyGrafik = new XGrafik(r, m, ROBOCZY, ld, dt);
    tablicaDyzurantowTworzacych = new std::vector<XDyzurantTworzacy*>();
    return nowyGrafik;
}

std::string MNoweGrafiki::utworzDyzurantaTworzacego(XDyzurant* dyzurant) {
    XDyzurantTworzacy* nowyDyzurantTworzacy = new XDyzurantTworzacy(dyzurant);
    tablicaDyzurantowTworzacych -> push_back(nowyDyzurantTworzacy);
    return (nowyDyzurantTworzacy->getNick());
}

void MNoweGrafiki::usunDyzurantaTworzacego(std::string nick) {
    XDyzurantTworzacy* dyzurantDoUsuniecia(nullptr);
    for (auto it = tablicaDyzurantowTworzacych->begin(); it<tablicaDyzurantowTworzacych->end(); ++it) {
        if ((*it)->getNick() == nick) {
            dyzurantDoUsuniecia = *it;
            delete dyzurantDoUsuniecia;
            tablicaDyzurantowTworzacych->erase(it);
            break;
        }
    }
    return;
}

XDyzurantTworzacy* MNoweGrafiki::pobierzDaneDyzurantaTworzacego(std::string nick) {
    for (auto it = tablicaDyzurantowTworzacych->begin(); it<tablicaDyzurantowTworzacych->end(); ++it) {
        if ((*it)->getNick() == nick) {
            return (*it);
        }
    }
    return nullptr;
}

bool MNoweGrafiki::updateDyzurantaTworzacego(std::string nick, bool czyM, std::string m, std::string nm, std::string u, std::string ch, int maks, int min, int maksS, int maksN, int maksW, int c, int maksP, int wyborT) {
    XDyzurantTworzacy* dyzurant(nullptr);
    for (auto it = tablicaDyzurantowTworzacych->begin(); it<tablicaDyzurantowTworzacych->end(); ++it) {
        if ((*it)->getNick() == nick) {
            dyzurant = *it;
            break;
        }
    }
    if (dyzurant == nullptr) return false;
    dyzurant->setWpisywanieCzyMoze(czyM);
    dyzurant->setMaksymalnie(maks);
    dyzurant->setMinimalnie(min);
    dyzurant->setMaksymalnieNiedziele(maksN);
    dyzurant->setMaksymalnieSoboty(maksS);
    dyzurant->setMaksymalnieWeekendy(maksW);
    dyzurant->setMaksymalniePiatki(maksP);
    dyzurant->setUnikaniePodRzad(c);
    dyzurant->setUnikanieTrojek(wyborT);
    bool result(false);
    if (czyM) {
        dyzurant->setKiedyMoze(m, result);
    }
    else {
        dyzurant->setKiedyNieMoze(nm, result);
    }
    if (!result) return result;
    dyzurant->setKiedyChce(ch, result);
    if (!result) return result;
    dyzurant->setKiedyUnika(u, result);
    if (!result) return result;
    return true;
}

bool MNoweGrafiki::zapiszUstawieniaDoPliku() {
    db = new DBObslugiwaczBazyDanych();
    std::vector<std::string> dane;
    std::vector<std::string> nicki;
    std::string s("");
    for (auto it=tablicaDyzurantowTworzacych->begin(); it<tablicaDyzurantowTworzacych->end(); ++it) {
        if ((*it)->getCzyWpisywanieGdzieMoze()) {
            dane.push_back("1");    //1. wers - czy moze czy nie moze
            s = (*it)->getKiedyMoze();
        }
        else {
            dane.push_back("0");    //1. wers
            s = (*it)->getKiedyNieMoze();
        }
        dane.push_back(s);        //2. wers - kiedy moze lub kiedy nie moze
        dane.push_back((*it)->getKiedyChce());    //3. wers - kiedy chce
        dane.push_back((*it)->getKiedyUnika());    //4. wers - kiedy unika
        dane.push_back(std::to_string((*it)->getMaksymalnie()));    //5. wers - maksymalnie
        dane.push_back(std::to_string((*it)->getMinimalnie()));       //6. wers - minimalnie
        dane.push_back(std::to_string((*it)->getMaksymelnieSoboty()));    //7. wers- maks soboty
        dane.push_back(std::to_string((*it)->getMaksymalnieNiedziele()));    //8. wers - maks niedziele
        dane.push_back(std::to_string((*it)->getMaksymalnieWeekendy()));    //9. wers - maks weekendy
        dane.push_back(std::to_string((*it)->getUnikaniePodRzad()));        //10. wers - unikanie pod rząd
        dane.push_back(std::to_string((*it)->getMaksymalniePiatki()));      //11. wers - maks piatki
        int unikanieTrojeczek = (*it)->getUnikanieTrojek();             //12. wers - unikanie trójek
        if (unikanieTrojeczek == 1) {
            dane.push_back("1");
        }
        else {
            dane.push_back("0");
        }
        
        if (!(db->zapiszUstawieniaDyzurantaTworzacego(dane, (*it)->getNick()))) {
            if (db != nullptr) {
                delete db;
                db = nullptr;
            }
            return false;
        }
        nicki.push_back((*it)->getNick());
        dane.clear();
    }
    if (!(db->zapiszNicki(nicki))) {
        if (db != nullptr) {
            delete db;
            db = nullptr;
        }
        return false;
    }
    if (db != nullptr) {
        delete db;
        db = nullptr;
    }
    return true;
}

bool MNoweGrafiki::usunWszystkieUstawieniaZPlikow() {
    if (db == nullptr) {
        db = new DBObslugiwaczBazyDanych();
    }
    bool result = db->usunWszystkiePlikiZUstawieniami();
    if (db != nullptr) {
        delete db;
        db = nullptr;
    }
    return result;
}

std::vector<std::string> MNoweGrafiki::wczytajUstawienia(std::vector<XDyzurant*>* tablicaDyzurantow) {
    //czyszczenie tablicy dyżurantow tworzących
    for (auto it=tablicaDyzurantowTworzacych->begin(); it<tablicaDyzurantowTworzacych->end(); ++it) {
        if ((*it) != nullptr) {
            delete (*it);
            *it = nullptr;
        }
    }
    tablicaDyzurantowTworzacych->clear();
    //teraz przechodzimy do ładowania
    if (db == nullptr) {
        db = new DBObslugiwaczBazyDanych();
    }
    bool result(false);
    std::vector<std::string> nicki = db->wczytajNicki(result);
    if (!result) {
        return nicki;
    }
    std::vector<std::string> daneDyzurantaTworzacego;
    XDyzurant* dyzurantMaster(nullptr);
    XDyzurantTworzacy* nowyDyzurantTworzacy(nullptr);
    bool resultX(false);
    for (auto it=nicki.begin(); it<nicki.end(); ++it) {
        daneDyzurantaTworzacego = db->wczytajDyzurantaTworzacego(*it, result);
        //start przerabiania tablicy wierszy na obiekt XDyzurantTworzacy
        //znajdz obiekt XDyzurant
        for (auto it2=tablicaDyzurantow->begin(); it2<tablicaDyzurantow->end(); ++it2) {
            if ((*it) == (*it2)->getNick()) {
                dyzurantMaster = *it2;
                break;
            }
        }
        //stworz nowy XDyzurantTworzacy
        nowyDyzurantTworzacy = new XDyzurantTworzacy(dyzurantMaster);
        if (daneDyzurantaTworzacego[0] == "0") {
            nowyDyzurantTworzacy->setWpisywanieCzyMoze(false);
            nowyDyzurantTworzacy->setKiedyNieMoze(daneDyzurantaTworzacego[1], resultX);
        }
        else {
            nowyDyzurantTworzacy->setWpisywanieCzyMoze(true);
            nowyDyzurantTworzacy->setKiedyMoze(daneDyzurantaTworzacego[1], resultX);
        }
        nowyDyzurantTworzacy->setKiedyChce(daneDyzurantaTworzacego[2], resultX);
        nowyDyzurantTworzacy->setKiedyUnika(daneDyzurantaTworzacego[3], resultX);
        nowyDyzurantTworzacy->setMaksymalnie(std::stoi(daneDyzurantaTworzacego[4]));
        nowyDyzurantTworzacy->setMinimalnie(std::stoi(daneDyzurantaTworzacego[5]));
        nowyDyzurantTworzacy->setMaksymalnieSoboty(std::stoi(daneDyzurantaTworzacego[6]));
        nowyDyzurantTworzacy->setMaksymalnieNiedziele(std::stoi(daneDyzurantaTworzacego[7]));
        nowyDyzurantTworzacy->setMaksymalnieWeekendy(std::stoi(daneDyzurantaTworzacego[8]));
        nowyDyzurantTworzacy->setUnikaniePodRzad(std::stoi(daneDyzurantaTworzacego[9]));
        nowyDyzurantTworzacy->setMaksymalniePiatki(std::stoi(daneDyzurantaTworzacego[10]));
        nowyDyzurantTworzacy->setUnikanieTrojek(std::stoi(daneDyzurantaTworzacego[11]));
        tablicaDyzurantowTworzacych -> push_back(nowyDyzurantTworzacy);
        daneDyzurantaTworzacego.clear();
        nowyDyzurantTworzacy = nullptr;
    }
    //teraz jest juz nowa tablicaDyzurantowTworzacych stworzona
    //wiec wystarczy do interfejsu zwrocic tablice nickow
    return nicki;
}

XGrafik* MNoweGrafiki::wypelnijGrafikPierwszymiDanymi() {
    nowyGrafik->stworzPodstawyGrafiku();
    for (auto it=tablicaDyzurantowTworzacych->begin(); it<tablicaDyzurantowTworzacych->end(); ++it) {
        nowyGrafik->dodajPierwszeDaneDyzurantaMozeUnika(*it);
    }
    nowyGrafik->dodajPierwszeDaneDyzurantowKiedyChca(tablicaDyzurantowTworzacych);
    nowyGrafik->przeliczMozliwiNieUnikajacyDyzuranciDlaKazdegoDnia();
    return nowyGrafik;
}

bool MNoweGrafiki::sprawdzWstepnieZgodnosc() {
    for (auto it=tablicaDyzurantowTworzacych->begin(); it<tablicaDyzurantowTworzacych->end(); ++it) {
        if (!((*it)->liczniki->sprawdzZgodnoscLiczbySobotINiedzielIWeekendow() && (*it)->liczniki->sprawdzZgodnoscMaksymalnejLiczbyDyzurow())) {
            return false;
        }
        if (!((*it)->liczniki->sprawdzZgodnoscLiczbyPiatkow())) {
            return false;
        }
    }
    return true;
}

void MNoweGrafiki::wypelnijGrafikDyzurantami(bool& immediateResult, int ileIteracji) {
    immediateResult = sprawdzWstepnieZgodnosc();
    if (!immediateResult) {
        return;
    }
    nowyGrafik -> wypelnijGrafikDyzurantami(tablicaDyzurantowTworzacych, ileIteracji);
}

MNoweGrafiki::~MNoweGrafiki() {
    if (nowyGrafik != nullptr) {
        delete nowyGrafik;
        nowyGrafik = nullptr;
    }
    if (tablicaDyzurantowTworzacych != nullptr) {
        for (auto it = tablicaDyzurantowTworzacych->begin(); it<tablicaDyzurantowTworzacych->end(); ++it) {
            if (*it != nullptr) {
                delete *it;
                *it = nullptr;
            }
        }
        delete tablicaDyzurantowTworzacych;
        tablicaDyzurantowTworzacych = nullptr;
    }
    if (db != nullptr) {
        delete db;
        db = nullptr;
    }
}
