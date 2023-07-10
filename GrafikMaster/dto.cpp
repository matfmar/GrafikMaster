#include "dto.h"
#include <algorithm>
#include <QDebug>
#include "dbobslugiwaczbazydanych.h"

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

void XDyzurantTworzacy::incLiczbaDyzurow(DzienTygodnia dt) {    //zwieksza licznik dyzurow oraz odpowiednio liczniki sobot niedziel i weekendow jesli trzeba
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

void XDyzurantTworzacy::usunDyzurPrzedPopBack() {
    dyzury.pop_back();
}

void XDyzurantTworzacy::dodajDyzur(int dzien) { //zwieksza wylacznie tabelke z dyzurami
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

bool XDyzurantTworzacy::sprawdzZgodnoscLiczbyDyzurow() {
    return (liczbaDyzurow >= minimalnie && liczbaDyzurow <= maksymalnie);
}

bool XDyzurantTworzacy::sprawdzZgodnoscLiczbySobotINiedzielIWeekendow() {
    return (liczbaSobot < maksymalnieSoboty && (liczbaNiedziel < maksymalnieNiedziele && liczbaWeekendow < maksymalnieWeekendy));
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

XDzien::XDzien(XDzien& xd) {
    dzienTygodnia = xd.dzienTygodnia;
    liczbaDnia = xd.liczbaDnia;
    czySwieto = xd.czySwieto;
    statusUstawiania = xd.statusUstawiania;
    mozliwiDyzuranci = xd.mozliwiDyzuranci;
    unikajacyDyzuranci = xd.unikajacyDyzuranci;
    mozliwiNieUnikajacyDyzuranci = xd.mozliwiNieUnikajacyDyzuranci;
    dyzurantWybrany = xd.dyzurantWybrany;
}

XDzien::XDzien(XDzien* xd) {
    dzienTygodnia = xd->dzienTygodnia;
    liczbaDnia = xd->liczbaDnia;
    czySwieto = xd->czySwieto;
    statusUstawiania = xd->statusUstawiania;
    mozliwiDyzuranci = xd->mozliwiDyzuranci;
    unikajacyDyzuranci = xd->unikajacyDyzuranci;
    mozliwiNieUnikajacyDyzuranci = xd->mozliwiNieUnikajacyDyzuranci;
    dyzurantWybrany = xd->dyzurantWybrany;
}

//XGrafik==============================================================================================================================
XGrafik::XGrafik()
    : rok(0), miesiac(NIEZNANY_MIESIAC), status(NIEZNANY_STATUS_GRAFIKU), liczbaDni(0), pierwszyDzien(NIEZNANY_DZIEN), db(nullptr) {}

XGrafik::XGrafik(int r, Miesiac m, StatusGrafiku st, int ld, DzienTygodnia pd)
    : rok(r), miesiac(m), status(st), liczbaDni(ld), pierwszyDzien(pd), db(nullptr) {}

XGrafik::XGrafik(XGrafik& gr) {
    rok = gr.rok;
    miesiac = gr.miesiac;
    status = gr.status;
    liczbaDni = gr.liczbaDni;
    pierwszyDzien = gr.pierwszyDzien;
    XDzien* nowyDzien(nullptr);
    for (auto it=gr.tablicaDni.begin(); it<gr.tablicaDni.end(); ++it) {
        nowyDzien = new XDzien(*it);
        tablicaDni.push_back(nowyDzien);
    }
    db = gr.db;     //trzeba na to uważać - przekazywany jest potencjalnie pusty, a potencjalnie pełny wskaźnik
}

XGrafik::XGrafik(XGrafik* gr) {
    rok = gr->rok;
    miesiac = gr->miesiac;
    status = gr->status;
    liczbaDni = gr->liczbaDni;
    pierwszyDzien = gr->pierwszyDzien;
    XDzien* nowyDzien(nullptr);
    for (auto it=gr->tablicaDni.begin(); it<gr->tablicaDni.end(); ++it) {
        nowyDzien = new XDzien(*it);
        tablicaDni.push_back(nowyDzien);
    }
    db = gr->db;    //trzeba na to uważać - przekazywany jest potencjalnie pusty, a potencjalnie pełny wskaźnik
}

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

bool XGrafik::sprawdzPustoscZbioruMozliwiNieUnikajacy(int dzien) {  //true gdy pusty
    return (tablicaDni[dzien]->mozliwiNieUnikajacyDyzuranci.empty());
}

std::vector<XDzien*> XGrafik::udostepnijTabliceDni() {
    return tablicaDni;
}

void XGrafik::wypelnijGrafikDyzurantami() {
    srand(time(0));
    bool result = wypelnijDzien(1);
}

void XGrafik::dodajUnikanie(XDyzurantTworzacy* dt, int klucz, int unikanieKrotnosc, bool& result) {   //dodaje unikanie i od razu przelicza tablicę MOZLIWI_NIE_UNIKAJACY
    dt->sortujDyzury();
    result = true;
    std::vector<int> tablicaPar;
    int lewy(0), prawy(0);
    tablicaPar = dt->znajdzSekwencje(unikanieKrotnosc);
    for (auto it3 = tablicaPar.begin(); it3 < tablicaPar.end(); it3 += 2) {
        lewy = *it3;
        prawy = *(it3+1);
        if (lewy-2 > 0) {
            if (tablicaDni[lewy-2]->dyzurantWybrany != dt) {
                tablicaDni[lewy-2]->unikajacyDyzuranci.insert(std::pair<int,XDyzurantTworzacy*>(klucz, dt));
                przeliczMozliwiNieUnikajacyDyzuranciDlaJednegoDnia(lewy-2);
                if (sprawdzPustoscZbioruMozliwiNieUnikajacy(lewy-2)) {
                    result = false;
                    return;
                }
            }
        }
        if (prawy < liczbaDni) {
            if (tablicaDni[prawy+2]->dyzurantWybrany != dt) {
                tablicaDni[prawy+2]->unikajacyDyzuranci.insert(std::pair<int,XDyzurantTworzacy*>(klucz, dt));
                przeliczMozliwiNieUnikajacyDyzuranciDlaJednegoDnia(prawy+2);
                if (sprawdzPustoscZbioruMozliwiNieUnikajacy(prawy+2)) {
                    result = false;
                    return;
                }
            }
        }
    }
}

bool XGrafik::losujDyzurantaDoDyzuruPoKluczu(int dzien, std::map<int, XDyzurantTworzacy*>* m, int& kluczWybranegoDyzuranta) {
    auto it = m->begin();
    std::advance(it, rand() % (m->size()));
    XDyzurantTworzacy* dt = it->second;
    int klucz = it->first;
    kluczWybranegoDyzuranta = klucz;
    //przypisanie do dnia
    tablicaDni[dzien]->dyzurantWybrany = dt;
    //wyrzucenie z tablic MOZLIWY i MOZLIWY_NIE_UNIKAJACY
    tablicaDni[dzien]->mozliwiDyzuranci.erase(klucz);
    tablicaDni[dzien]->mozliwiNieUnikajacyDyzuranci.erase(klucz);
    //usuniecie z tablic MOZLIWY I MOZLIWY_NIE_UNIKAJACY z dni sasiednich
    tablicaDni[dzien-1]->mozliwiDyzuranci.erase(klucz);
    tablicaDni[dzien-1]->mozliwiNieUnikajacyDyzuranci.erase(klucz);
    tablicaDni[dzien+1]->mozliwiDyzuranci.erase(klucz);
    tablicaDni[dzien+1]->mozliwiNieUnikajacyDyzuranci.erase(klucz);
    //dodaj ten nowy dyzur do listy dyzurow dla danego dyzuranta
    dt->incLiczbaDyzurow(tablicaDni[dzien]->dzienTygodnia);
    dt->dodajDyzur(dzien);
    //posprawdzaj limity i ewentualnie cofnij zmiany
    if (!(dt->sprawdzZgodnoscLiczbyDyzurow() && dt->sprawdzZgodnoscLiczbySobotINiedzielIWeekendow())) {
        dt->decLiczbaDyzurow(tablicaDni[dzien]->dzienTygodnia);
        dt->usunDyzurPrzedPopBack();
        return false;
    }
    //dodawanie unikania w razie włączonej opcji unikania ciągów
    int krotnoscUnikanie = dt->getUnikaniePodRzad();
    bool resultDodaniaUnikania(false);
    if (krotnoscUnikanie != 0) {
        dodajUnikanie(dt, klucz, krotnoscUnikanie,resultDodaniaUnikania);     //dodaje unikanie i od razu przelicza tablicę MOZLIWI_NIE_UNIKAJACY
        if (!resultDodaniaUnikania) {
            dt->decLiczbaDyzurow(tablicaDni[dzien]->dzienTygodnia);     //trzeba cofnąć zmiany w tablicy dyżurantów
            dt->usunDyzur(dzien);       //nie mogę przez pop_back, bo dokonano sortowania przed szukaniem sekwencji
            return false;
        }
    }
    //przeszliśmy wszystkie etapy - jest OK.
    return true;
}

bool XGrafik::setLosowoNowyDzien(int dzien, int& kluczWybranegoDyzuranta) {
    bool result = (losujDyzurantaDoDyzuruPoKluczu(dzien, &(tablicaDni[dzien]->mozliwiNieUnikajacyDyzuranci), kluczWybranegoDyzuranta));
    return result;
}

bool XGrafik::wypelnijDzien(int dzien) {        //glowna funkcja wywolywana rekurencyjnie
    if (dzien > liczbaDni) {
        //czyli ułożyliśmy cały grafik !!!!!
        if (db == nullptr) {
            db = new DBObslugiwaczBazyDanych();
        }
        //więc zapisujemy do pliku...
        db->zapiszUlozonyGrafikDoPliku(this);
        //...i spadamy.
        return true;
    }
    XGrafik* nowyGrafik(nullptr);
    bool resultDodania(false);
    int kluczWybranegoDyzuranta(-1);
    do {
        do {
            if (nowyGrafik != nullptr){         //robi się tylko gdy warunek pętli się schrzanił i trzeba liczyć jeszcze raz
                //wyrzucamy z tablicy MOZLIWE dla DANEGO DNIA - UWAGA: AKTUALNEGO GRAFIKU!!! - dyzuranta, którego wstawienie zakończyło się klęską
                tablicaDni[dzien]->mozliwiDyzuranci.erase(kluczWybranegoDyzuranta);
                tablicaDni[dzien]->mozliwiNieUnikajacyDyzuranci.erase(kluczWybranegoDyzuranta);
                //usuwamy stworzony do celów byłego dodawania grafik - tam jest za duży rozpierdol żeby cofać zmiany, trzeba zrekonstruować cały obiekt na nowo
                delete nowyGrafik;
                nowyGrafik = nullptr;
                //a teraz BARDZO WAŻNE: tablica MOŻLIWI NIE UNIKAJĄCY mogła się właśnie wyczyścić, więc trzeba ZAKOŃCZYĆ DZIAŁANIE TEJ INSTANCJI
                if (tablicaDni[dzien]->mozliwiNieUnikajacyDyzuranci.empty()) {
                    return false;
                }
            }
            nowyGrafik = new XGrafik(this);
            resultDodania = nowyGrafik->setLosowoNowyDzien(dzien, kluczWybranegoDyzuranta);
        } while(!resultDodania);
        //a teraz mamy nowy grafik z dodanym prawidłowo nowym dyżurantem dla dnia, więc.....
        //...wywołujemy rekurencyjnie ową procedurę, ale dla kolejnego dnia
    } while (!nowyGrafik->wypelnijDzien(dzien+1)); //PATRZ NIŻEJ
    //jeśli zakończy się klęską, wracamy do góry -> wyrzucamy z tablicy MOŻLIWE felernego dyżuranta i z powrotem próbujemy szczęścia

    //a jeśli zakończyła sie sukcesem i grafik się znalazł -> i tak niszczymy obiekt (zwalniamy pamięć)...
    if (nowyGrafik != nullptr) {
        delete nowyGrafik;
        nowyGrafik = nullptr;
    }
    //i spadamy.
    return true;
}

XGrafik::~XGrafik() {
    for (auto it=tablicaDni.begin(); it<tablicaDni.end(); ++it) {
        if ((*it) != nullptr) {
            delete (*it);
            (*it) = nullptr;
        }
    }
    if (db != nullptr) {
        delete db;
        db = nullptr;
    }
}


