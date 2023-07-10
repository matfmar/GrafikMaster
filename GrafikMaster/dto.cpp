#include "dto.h"
#include <algorithm>
#include <QDebug>

//GENERAL===============================================================================================================================
//----------------------------------------------------------------------
DzienTygodnia incDzien(DzienTygodnia dt) {
    DzienTygodnia dt2;
    switch(dt) {
    case PONIEDZIALEK: dt2 = WTOREK; break;
    case WTOREK: dt2 = SRODA; break;
    case SRODA: dt2 = CZWARTEK; break;
    case CZWARTEK: dt2 = PIATEK; break;
    case PIATEK: dt2 = SOBOTA; break;
    case SOBOTA: dt2 = NIEDZIELA; break;
    case NIEDZIELA: dt2 = PONIEDZIALEK; break;
    default: dt2 = PONIEDZIALEK; break;
    }
    return dt2;
}

//XDyzurant==============================================================================================================================
XDyzurant::XDyzurant()
    : id(0), nick(""), priorytet(0) {}

XDyzurant::XDyzurant(int a, std::string s, int b)
    : id(a), nick(s), priorytet(b) {}

XDyzurant::XDyzurant(XDyzurant* d)
    : id(d->getId()), nick(d->getNick()), priorytet(d->getPriorytet()) {}

std::string XDyzurant::getNick() {
    return nick;
}

int XDyzurant::getId() {
    return id;
}

int XDyzurant::getPriorytet() {
    return priorytet;
}

void XDyzurant::setNick(std::string s) {
    nick = s;
}

void XDyzurant::setPriorytet(int a) {
    priorytet = a;
}

//XDyzurantTworzacy==============================================================================================================================
XDyzurantTworzacy::XDyzurantTworzacy()
    : XDyzurant(), maksymalnie(0), minimalnie(0), unikaniePodRzad(0),
    maksymalnieSoboty(0), maksymalnieNiedziele(0), maksymalnieWeekendy(0), wpisywanieGdzieMoze(false),
    liczbaDyzurow(0), liczbaSobot(0), liczbaNiedziel(0), liczbaWeekendow(0) {}

XDyzurantTworzacy::XDyzurantTworzacy(int a, std::string s, int b, int c, int d, int e, int sb, int nd, int wk, bool wgm)
    : XDyzurant(a, s, b), maksymalnie(c), minimalnie(d), unikaniePodRzad(e),
    maksymalnieSoboty(sb), maksymalnieNiedziele(nd), maksymalnieWeekendy(wk), wpisywanieGdzieMoze(wgm),
    liczbaDyzurow(0), liczbaSobot(0), liczbaNiedziel(0), liczbaWeekendow(0) {}

XDyzurantTworzacy::XDyzurantTworzacy(XDyzurant* d)
    : XDyzurant(d), maksymalnie(0), minimalnie(0), unikaniePodRzad(0),
    maksymalnieSoboty(0), maksymalnieNiedziele(0), maksymalnieWeekendy(0), wpisywanieGdzieMoze(false),
    liczbaDyzurow(0), liczbaSobot(0), liczbaNiedziel(0), liczbaWeekendow(0) {}

std::string XDyzurantTworzacy::getKiedyChce() {
    std::string s("");
    for (auto it = kiedyChce.begin(); it<kiedyChce.end(); ++it) {
        s += std::to_string(*it);
        if (it != kiedyChce.end()-1) {
            s += ',';
        }
    }
    return s;
}

std::string XDyzurantTworzacy::getKiedyNieMoze() {
    std::string s("");
    for (auto it = kiedyNieMoze.begin(); it<kiedyNieMoze.end(); ++it) {
        s += std::to_string(*it);
        if (it != kiedyNieMoze.end()-1) {
            s += ',';
        }
    }
    return s;
}

std::string XDyzurantTworzacy::getKiedyMoze() {
    std::string s("");
    for (auto it = kiedyMoze.begin(); it<kiedyMoze.end(); ++it) {
        s += std::to_string(*it);
        if (it != kiedyMoze.end()-1) {
            s += ',';
        }
    }
    return s;
}

std::string XDyzurantTworzacy::getKiedyUnika() {
    std::string s("");
    for (auto it = kiedyUnika.begin(); it<kiedyUnika.end(); ++it) {
        s += std::to_string(*it);
        if (it != kiedyUnika.end()-1) {
            s += ',';
        }
    }
    return s;
}

bool XDyzurantTworzacy::getCzyWpisywanieGdzieMoze() {return wpisywanieGdzieMoze;}

int XDyzurantTworzacy::getMaksymalnie() {return maksymalnie;}

int XDyzurantTworzacy::getMinimalnie() {return minimalnie;}

int XDyzurantTworzacy::getUnikaniePodRzad() {return unikaniePodRzad;}

int XDyzurantTworzacy::getMaksymelnieSoboty() {return maksymalnieSoboty;}

int XDyzurantTworzacy::getMaksymalnieNiedziele() {return maksymalnieNiedziele;}

int XDyzurantTworzacy::getMaksymalnieWeekendy() {return maksymalnieWeekendy;}

std::vector<int> XDyzurantTworzacy::convertStringToVectorOfInts(std::string s, bool& result) {
    std::string temp("");
    std::vector<int> v;
    if (s.empty() || s == "") {
        result = true;
        return v;
    }
    s += ',';
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            temp += c;
        }
        else if (c == ',') {
            v.push_back(std::stoi(temp));
            temp = "";
        }
        else {
            result = false;
            v.clear();
            return v;
        }
    }
    result = true;
    return v;
}

void XDyzurantTworzacy::setKiedyChce(std::string s, bool& result) {
    kiedyChce = convertStringToVectorOfInts(s, result);
}

void XDyzurantTworzacy::setKiedyNieMoze(std::string s, bool& result) {
    kiedyNieMoze = convertStringToVectorOfInts(s, result);
}

void XDyzurantTworzacy::setKiedyMoze(std::string s, bool& result) {
    kiedyMoze = convertStringToVectorOfInts(s, result);
}

void XDyzurantTworzacy::setKiedyUnika(std::string s, bool& result) {
    kiedyUnika = convertStringToVectorOfInts(s, result);
}

void XDyzurantTworzacy::setMaksymalnie(int a) {maksymalnie = a;}

void XDyzurantTworzacy::setMinimalnie(int a) {minimalnie = a;}

void XDyzurantTworzacy::setUnikaniePodRzad(int a) {unikaniePodRzad = a;}

void XDyzurantTworzacy::setMaksymalnieSoboty(int a) {maksymalnieSoboty = a;}

void XDyzurantTworzacy::setMaksymalnieNiedziele(int a) {maksymalnieNiedziele = a;}

void XDyzurantTworzacy::setMaksymalnieWeekendy(int a) {maksymalnieWeekendy = a;}

void XDyzurantTworzacy::setWpisywanieCzyMoze(bool b) {wpisywanieGdzieMoze = b;}

void XDyzurantTworzacy::incLiczbaDyzurow(DzienTygodnia dt) {
    if (dt == SOBOTA) {
        liczbaSobot++;
        liczbaWeekendow++;
    }
    else if (dt == NIEDZIELA) {
        liczbaNiedziel++;
        liczbaWeekendow++;
    }
    liczbaDyzurow++;
}

void XDyzurantTworzacy::decLiczbaDyzurow(DzienTygodnia dt) {
    if (dt == SOBOTA) {
        liczbaSobot--;
        liczbaWeekendow--;
    }
    else if (dt == NIEDZIELA) {
        liczbaNiedziel--;
        liczbaWeekendow--;
    }
    liczbaDyzurow--;
}

bool XDyzurantTworzacy::sprawdzCzyMozeDanegoDnia(int dzien) {
    if (wpisywanieGdzieMoze) {
        for (auto it=kiedyMoze.begin(); it<kiedyMoze.end(); ++it) {
            if (*it == dzien) {
                return true;
            }
        }
        return false;
    }
    else {
        for (auto it=kiedyNieMoze.begin(); it<kiedyNieMoze.end(); ++it) {
            if (*it == dzien) {
                return false;
            }
        }
        return true;
    }
}

bool XDyzurantTworzacy::sprawdzCzyChceDanegoDnia(int dzien) {
    for (auto it=kiedyChce.begin(); it<kiedyChce.end(); ++it) {
        if ((*it) == dzien) {
            return true;
        }
    }
    return false;
}

void XDyzurantTworzacy::usunDyzur(int dzien) {
    for (auto it=dyzury.begin(); it<dyzury.end(); ++it) {
        if (*it == dzien) {
            dyzury.erase(it);
            return;
        }
    }
}

void XDyzurantTworzacy::dodajDyzur(int dzien) {
    dyzury.push_back(dzien);
}

void XDyzurantTworzacy::sortujDyzury() {
    std::sort(dyzury.begin(), dyzury.end());
}

std::vector<int> XDyzurantTworzacy::znajdzSekwencje(int krotnosc) {	//krotnosc 4 - szukam trójek itd.(zeby potem zapobiegac powstaniu czworki)
    std::vector<int> v;
    int i(0), roznica(0), ile(0), lewy(0), prawy(0);
    if (krotnosc == 2) {
        for (auto it = dyzury.begin(); it<dyzury.end(); ++it) {
            lewy = *it;
            prawy = *it;
            v.push_back(lewy);
            v.push_back(prawy);
        }
    }
    else {
        for (auto it = dyzury.begin(); it<dyzury.end(); ++it) {
            if (i == 0) {
                i++;
                continue;
            }
            roznica = (*it) - (*(it-1));
            if (roznica == 2) {
                ile++;
            }
            else {
                ile = 0;
            }
            if (ile == krotnosc-2) {
                lewy = *(it-(krotnosc-2));
                prawy = *it;
                v.push_back(lewy);
                v.push_back(prawy);
                ile = 0;
            }
            i++;
        }
    }
    return v;
}

std::vector<int> XDyzurantTworzacy::getKiedyChce2() {
    return kiedyChce;
}

std::vector<int> XDyzurantTworzacy::getKiedyMoze2() {
    return kiedyMoze;
}

std::vector<int> XDyzurantTworzacy::getKiedyNieMoze2() {
    return kiedyNieMoze;
}

std::vector<int> XDyzurantTworzacy::getKiedyUnika2() {
    return kiedyUnika;
}

//XDzien==============================================================================================================================
XDzien::XDzien()
    : dzienTygodnia(NIEZNANY_DZIEN), liczbaDnia(0), czySwieto(false), statusUstawiania(NIEZNANY_STATUS), dyzurantWybrany(nullptr) {}

XDzien::XDzien(DzienTygodnia dt, int ld, bool czs, StatusDnia sd, XDyzurantTworzacy* dw)
    : dzienTygodnia(dt), liczbaDnia(ld), czySwieto(czs), statusUstawiania(sd), dyzurantWybrany(dw) {}

void XDzien::przeliczMozliwiNieUnikajacyDyzuranci() {
    mozliwiNieUnikajacyDyzuranci = mozliwiDyzuranci;
    auto it = unikajacyDyzuranci.begin();
    while (it != unikajacyDyzuranci.end()) {
        mozliwiNieUnikajacyDyzuranci.erase(it->first);
        ++it;
    }
}

//XGrafik==============================================================================================================================
XGrafik::XGrafik()
    : rok(0), miesiac(NIEZNANY_MIESIAC), status(NIEZNANY_STATUS_GRAFIKU), liczbaDni(0), pierwszyDzien(NIEZNANY_DZIEN) {}

XGrafik::XGrafik(int r, Miesiac m, StatusGrafiku st, int ld, DzienTygodnia pd)
    : rok(r), miesiac(m), status(st), liczbaDni(ld), pierwszyDzien(pd) {}

void XGrafik::stworzPodstawyGrafiku() {
    DzienTygodnia dt;
    bool czySwieto(false);

    XDzien* dzien = new XDzien(NIEZNANY_DZIEN, 0, false, NIEUSTAWIONY_W_TRAKCIE, nullptr);
    tablicaDni.push_back(dzien);	//indeks 0 to pusty dzien - przyda sie potem

    for (int i=0; i<liczbaDni; ++i) {
        if (i==0) {
            dt = pierwszyDzien;
        }
        else {
            dt = incDzien(dt);
        }
        czySwieto = (dt == NIEDZIELA);
        dzien = new XDzien(dt, i+1, czySwieto, NIEUSTAWIONY_W_TRAKCIE, nullptr);
        tablicaDni.push_back(dzien);
    }

    dzien = new XDzien(NIEZNANY_DZIEN, liczbaDni+1, false, NIEUSTAWIONY_W_TRAKCIE, nullptr);
    tablicaDni.push_back(dzien);	//indeks ostatni+1 to pusty dzien - przyda sie potem
}

void XGrafik::dodajPierwszeDaneDyzurantaMozeUnika(XDyzurantTworzacy* dyzurant) {
    bool wpisywanieGdzieMoze = dyzurant->getCzyWpisywanieGdzieMoze();
    int id = dyzurant->getId();
    std::vector<int> kiedyMoze = dyzurant->getKiedyMoze2();
    std::vector<int> kiedyNieMoze = dyzurant->getKiedyNieMoze2();
    std::vector<int> kiedyUnika = dyzurant->getKiedyUnika2();
    //wpisywanie kiedy moze lub kiedy nie moze
    if (wpisywanieGdzieMoze) {
        for (auto it=kiedyMoze.begin(); it<kiedyMoze.end(); ++it) {
            tablicaDni[*it]->mozliwiDyzuranci.insert(std::pair<int,XDyzurantTworzacy*>(id, dyzurant));
        }
    }
    else {
        for (auto it=tablicaDni.begin(); it<tablicaDni.end(); ++it) {
            (*it)->mozliwiDyzuranci.insert(std::pair<int,XDyzurantTworzacy*>(id, dyzurant));
        }
        for (auto it=kiedyNieMoze.begin(); it<kiedyNieMoze.end(); ++it) {
            tablicaDni[*it]->mozliwiDyzuranci.erase(id);
        }
    }
    //unikanie
    for (auto it=kiedyUnika.begin(); it<kiedyUnika.end(); ++it) {
        tablicaDni[*it]->unikajacyDyzuranci.insert(std::pair<int,XDyzurantTworzacy*>(id, dyzurant));
    }

}

void XGrafik::dodajPierwszeDaneDyzurantowKiedyChca(std::vector<XDyzurantTworzacy*>* tablicaDyzurantowTworzacych) {
    if (tablicaDyzurantowTworzacych == nullptr) {
        return;
    }
    XDyzurantTworzacy* lider(nullptr);
    int unikanieKrotnosc(0);
    std::vector<int> tablicaPar;
    int lewy(0), prawy(0);
    for (auto it=tablicaDni.begin(); it<tablicaDni.end(); ++it) {
        tablicaPar.clear();
        //szukanie lidera
        lider = nullptr;
        for (auto it2=tablicaDyzurantowTworzacych->begin(); it2<tablicaDyzurantowTworzacych->end(); ++it2) {
            if ((*it2)->sprawdzCzyChceDanegoDnia((*it)->liczbaDnia)) {
                if (lider == nullptr) {
                    lider = *it2;
                }
                else {
                    if (lider->getPriorytet() > (*it2)->getPriorytet()) {
                        lider = *it2;
                    }
                }
            }
        }
        if (lider == nullptr) {
            continue;
        }
        //lider znaleziony, teraz wstawiamy go do grafiku
        (*it)->dyzurantWybrany = lider;
        (*it)->mozliwiDyzuranci.clear();	//nikt inny tego dnia nie dostanie
        (*it)->mozliwiDyzuranci.insert(std::pair<int,XDyzurantTworzacy*>(lider->getId(), lider));	//jw. cd.
        (*it)->statusUstawiania = USTAWIONY_WSTEPNIE;
        lider->incLiczbaDyzurow((*it)->dzienTygodnia);
        lider->dodajDyzur((*it)->liczbaDnia);
        (*(it-1))->mozliwiDyzuranci.erase(lider->getId());
        (*(it+1))->mozliwiDyzuranci.erase(lider->getId());
        (*it)->unikajacyDyzuranci.erase(lider->getId());	//moglo byc tak ze zostalo wstawione z unikania ciagow
        //dzien ustawiony, teraz patrzymy na unikanie ciągów dla lidera który właśnie dostał nowy dyżur
        unikanieKrotnosc = lider->getUnikaniePodRzad();
        lider->sortujDyzury();		//trzeba posortowac
        if (unikanieKrotnosc != 0) {	//przyspieszy program
            tablicaPar = lider->znajdzSekwencje(unikanieKrotnosc);
            for (auto it3 = tablicaPar.begin(); it3 < tablicaPar.end(); it3 += 2) {
                lewy = *it3;
                prawy = *(it3+1);
                qDebug() << lewy;
                qDebug() << prawy;
                if (lewy-2 > 0) {
                    if (tablicaDni[lewy-2]->dyzurantWybrany != lider) {
                        tablicaDni[lewy-2]->unikajacyDyzuranci.insert(std::pair<int,XDyzurantTworzacy*>(lider->getId(), lider));
                    }
                }
                if (prawy < liczbaDni) {
                    if (tablicaDni[prawy+2]->dyzurantWybrany != lider) {
                        tablicaDni[prawy+2]->unikajacyDyzuranci.insert(std::pair<int,XDyzurantTworzacy*>(lider->getId(), lider));
                    }
                }
            }
        }
    }

}

void XGrafik::przeliczMozliwiNieUnikajacyDyzuranciDlaKazdegoDnia() {
    for (auto it=tablicaDni.begin(); it<tablicaDni.end(); ++it) {
        (*it)->przeliczMozliwiNieUnikajacyDyzuranci();
    }
}

void XGrafik::przeliczMozliwiNieUnikajacyDyzuranciDlaJednegoDnia(int dzien) {
    tablicaDni[dzien]->przeliczMozliwiNieUnikajacyDyzuranci();
}

std::vector<XDzien*> XGrafik::udostepnijTabliceDni() {
    return tablicaDni;
}

XGrafik::~XGrafik() {
    for (auto it=tablicaDni.begin(); it<tablicaDni.end(); ++it) {
        if (*it != nullptr) {
            delete (*it);
            *it = nullptr;
        }
    }
}


