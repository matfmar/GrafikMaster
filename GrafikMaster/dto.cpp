#include "dto.h"
#include <algorithm>
#include <QDebug>
#include "dbobslugiwaczbazydanych.h"
#include "tworker.h"

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

std::string przeliczDzienTygodniaNaLancuch(DzienTygodnia dt) {
    switch (dt) {
    case PONIEDZIALEK: return "poniedziałek"; break;
    case WTOREK: return "wtorek"; break;
    case SRODA: return "środa"; break;
    case CZWARTEK: return "czwartek"; break;
    case PIATEK: return "piątek"; break;
    case SOBOTA: return "sobota"; break;
    case NIEDZIELA: return "niedziela"; break;
    default: return "nie_wiadomo"; break;
    }
    return "";
}

std::string przeliczMiesiacNaLiczbe(Miesiac m) {
    switch (m) {
        case STYCZEN: return "1"; break;
        case LUTY: return "2"; break;
        case MARZEC: return "3"; break;
        case KWIECIEN: return "4"; break;
        case MAJ: return "5"; break;
        case CZERWIEC: return "6"; break;
        case LIPIEC: return "7"; break;
        case SIERPIEN: return "8"; break;
        case WRZESIEN: return "9"; break;
        case PAZDZIERNIK: return "10"; break;
        case LISTOPAD: return "11"; break;
        case GRUDZIEN: return "12"; break;
        default: return "0"; break;
    }
    return "";
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
    liczniki(nullptr), maksymalniePiatki(0), unikanieTrojek(0) {
    liczniki = new XDyzurantTworzacy::XLiczniki(this);
}

XDyzurantTworzacy::XDyzurantTworzacy(int a, std::string s, int b, int c, int d, int e, int sb, int nd, int wk, bool wgm, int mp, int ut)
    : XDyzurant(a, s, b), maksymalnie(c), minimalnie(d), unikaniePodRzad(e),
    maksymalnieSoboty(sb), maksymalnieNiedziele(nd), maksymalnieWeekendy(wk), wpisywanieGdzieMoze(wgm),
    liczniki(nullptr), maksymalniePiatki(mp), unikanieTrojek(ut) {
    liczniki = new XDyzurantTworzacy::XLiczniki(this);
}

XDyzurantTworzacy::XDyzurantTworzacy(XDyzurant* d)
    : XDyzurant(d), maksymalnie(0), minimalnie(0), unikaniePodRzad(0),
    maksymalnieSoboty(0), maksymalnieNiedziele(0), maksymalnieWeekendy(0), wpisywanieGdzieMoze(false),
    liczniki(nullptr), maksymalniePiatki(0), unikanieTrojek(0) {
    liczniki = new XDyzurantTworzacy::XLiczniki(this);
}

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

int XDyzurantTworzacy::getMaksymalniePiatki() {return maksymalniePiatki;}

int XDyzurantTworzacy::getUnikanieTrojek() {return unikanieTrojek;}

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

void XDyzurantTworzacy::setMaksymalniePiatki(int a) {maksymalniePiatki = a;}

void XDyzurantTworzacy::setUnikanieTrojek(int a) {unikanieTrojek = a;}

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


XDyzurantTworzacy::~XDyzurantTworzacy() {
    if (liczniki != nullptr) {
        delete liczniki;
        liczniki = nullptr;
    }
}

//XDyzurantTworzacy::XLiczniki===========================================================================================================================

XDyzurantTworzacy::XLiczniki::XLiczniki(XDyzurantTworzacy* p)
    : parent(p), liczbaDyzurow(0), liczbaSobot(0), liczbaNiedziel(0), liczbaWeekendow(0), liczbaPiatkow(0) {}

XDyzurantTworzacy::XLiczniki::XLiczniki(XDyzurantTworzacy::XLiczniki* l) {
    parent = l->parent;
    liczbaDyzurow = l->liczbaDyzurow;
    liczbaSobot = l->liczbaSobot;
    liczbaNiedziel = l->liczbaNiedziel;
    liczbaWeekendow = l->liczbaWeekendow;
    liczbaPiatkow = l->liczbaPiatkow;
    dyzury = l->dyzury;
}

void XDyzurantTworzacy::XLiczniki::incLiczbaDyzurow(DzienTygodnia dt) {    //zwieksza licznik dyzurow oraz odpowiednio liczniki sobot niedziel i weekendow jesli trzeba
    if (dt == SOBOTA) {
        liczbaSobot++;
        liczbaWeekendow++;
    }
    else if (dt == NIEDZIELA) {
        liczbaNiedziel++;
        liczbaWeekendow++;
    }
    else if (dt == PIATEK) {
        liczbaPiatkow++;
    }
    liczbaDyzurow++;
}

void XDyzurantTworzacy::XLiczniki::decLiczbaDyzurow(DzienTygodnia dt) {
    if (dt == SOBOTA) {
        liczbaSobot--;
        liczbaWeekendow--;
    }
    else if (dt == NIEDZIELA) {
        liczbaNiedziel--;
        liczbaWeekendow--;
    }
    else if (dt == PIATEK) {
        liczbaPiatkow--;
    }
    liczbaDyzurow--;
}

void XDyzurantTworzacy::XLiczniki::usunDyzur(int dzien) {
    for (auto it=dyzury.begin(); it<dyzury.end(); ++it) {
        if (*it == dzien) {
            dyzury.erase(it);
            return;
        }
    }
}

void XDyzurantTworzacy::XLiczniki::usunDyzurPrzedPopBack() {
    dyzury.pop_back();
}

void XDyzurantTworzacy::XLiczniki::dodajDyzur(int dzien) { //zwieksza wylacznie tabelke z dyzurami
    dyzury.push_back(dzien);
}

void XDyzurantTworzacy::XLiczniki::sortujDyzury() {
    std::sort(dyzury.begin(), dyzury.end());
}

std::vector<int> XDyzurantTworzacy::XLiczniki::znajdzSekwencje(int krotnosc) {	//krotnosc 4 - szukam trójek itd.(zeby potem zapobiegac powstaniu czworki)
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

std::vector<int> XDyzurantTworzacy::XLiczniki::zwrocDyzury() {
    return dyzury;
}

bool XDyzurantTworzacy::XLiczniki::sprawdzZgodnoscMaksymalnejLiczbyDyzurow() {
    return (liczbaDyzurow <= parent->getMaksymalnie());
}

bool XDyzurantTworzacy::XLiczniki::sprawdzZgodnoscMinimalnejLiczbyDyzurow() {
    return (liczbaDyzurow >= parent->getMinimalnie());
}

bool XDyzurantTworzacy::XLiczniki::sprawdzZgodnoscLiczbySobotINiedzielIWeekendow() {
    return (liczbaSobot <= parent->getMaksymelnieSoboty() && (liczbaNiedziel <= parent->getMaksymalnieNiedziele() && liczbaWeekendow <= parent->getMaksymalnieWeekendy()));
}

bool XDyzurantTworzacy::XLiczniki::sprawdzZgodnoscLiczbyPiatkow() {
    return (liczbaPiatkow <= parent->getMaksymalniePiatki());
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
    : rok(0), miesiac(NIEZNANY_MIESIAC), status(NIEZNANY_STATUS_GRAFIKU), liczbaDni(0), pierwszyDzien(NIEZNANY_DZIEN), db(nullptr),
    tablicaDyzurantowTworzacych(nullptr),
    licznikStworzonychGrafikow(nullptr), zakonczenieSzukania(nullptr), licznikOstatecznyStworzonychGrafikow(nullptr),
    liczbaIteracji(nullptr), parentWorker(nullptr), czyPrzyspieszenie(false), licznikSkrocen(nullptr), decyzjaOSkroceniu(nullptr),
    mutex(nullptr), skracaniePomimoUlozenia(false) {}

XGrafik::XGrafik(int r, Miesiac m, StatusGrafiku st, int ld, DzienTygodnia pd)
    : rok(r), miesiac(m), status(st), liczbaDni(ld), pierwszyDzien(pd), db(nullptr), tablicaDyzurantowTworzacych(nullptr),
    licznikStworzonychGrafikow(nullptr), zakonczenieSzukania(nullptr),
    licznikOstatecznyStworzonychGrafikow(nullptr), liczbaIteracji(nullptr), parentWorker(nullptr),
    licznikSkrocen(nullptr), czyPrzyspieszenie(false), decyzjaOSkroceniu(nullptr),
    mutex(nullptr), skracaniePomimoUlozenia(false) {}

XGrafik::XGrafik(XGrafik& gr) {
    rok = gr.rok;
    miesiac = gr.miesiac;
    status = gr.status;
    liczbaDni = gr.liczbaDni;
    pierwszyDzien = gr.pierwszyDzien;
    XDzien* nowyDzien(nullptr);
    //kopiowanie każdego dnia z osobna
    for (auto it=gr.tablicaDni.begin(); it<gr.tablicaDni.end(); ++it) {
        nowyDzien = new XDzien(*it);
        tablicaDni.push_back(nowyDzien);
    }
    //kopiowanie każdej pozycji z liczników dla dyżurantów tworzących z osobna
    XDyzurantTworzacy::XLiczniki* nowyEl(nullptr);
    int odpowiedniKlucz(-1);
    for (auto el : gr.mapaLicznikowDyzurantow) {    //kopiujac grafik kopiowana jest mapa licznikow dyzurantow tworzacych
        nowyEl = new XDyzurantTworzacy::XLiczniki(el.second);
        odpowiedniKlucz = el.first;
        mapaLicznikowDyzurantow.insert(std::pair<int, XDyzurantTworzacy::XLiczniki*>(odpowiedniKlucz, nowyEl));
    }
    //kopiowanie obiektu do bazy danych
    db = gr.db;     //trzeba na to uważać - przekazywany jest potencjalnie pusty, a potencjalnie pełny wskaźnik
    tablicaDyzurantowTworzacych = gr.tablicaDyzurantowTworzacych;   //uwaga, ten obiekt jest "gdzie indziej"
    licznikStworzonychGrafikow = gr.licznikStworzonychGrafikow; //tylko kopiujemy wskaźnik, obiekt jest już stworzony
    zakonczenieSzukania = gr.zakonczenieSzukania;   //tylko kopiujemy wskaźnik, obiekt jest już stworzony
    licznikOstatecznyStworzonychGrafikow = gr.licznikOstatecznyStworzonychGrafikow; //jw.
    liczbaIteracji = gr.liczbaIteracji; //jw.
    parentWorker = gr.parentWorker;   //jw.
    //zmienne do ew. przyspieszacza (związane z timerem)
    czyPrzyspieszenie = gr.czyPrzyspieszenie;
    licznikSkrocen = gr.licznikSkrocen;
    decyzjaOSkroceniu = gr.decyzjaOSkroceniu;
    mutex = gr.mutex;
    skracaniePomimoUlozenia = gr.skracaniePomimoUlozenia;
}

XGrafik::XGrafik(XGrafik* gr) {
    rok = gr->rok;
    miesiac = gr->miesiac;
    status = gr->status;
    liczbaDni = gr->liczbaDni;
    pierwszyDzien = gr->pierwszyDzien;
    XDzien* nowyDzien(nullptr);
    //kopiowanie każdego dnia z osobna
    for (auto it=gr->tablicaDni.begin(); it<gr->tablicaDni.end(); ++it) {
        nowyDzien = new XDzien(*it);
        tablicaDni.push_back(nowyDzien);
    }
    //kopiowanie każdej pozycji z liczników dla dyżurantów tworzących z osobna
    XDyzurantTworzacy::XLiczniki* nowyEl(nullptr);
    int odpowiedniKlucz(-1);
    for (auto el : gr->mapaLicznikowDyzurantow) {    //kopiujac grafik kopiowana jest mapa licznikow dyzurantow tworzacych
        nowyEl = new XDyzurantTworzacy::XLiczniki(el.second);
        odpowiedniKlucz = el.first;
        mapaLicznikowDyzurantow.insert(std::pair<int, XDyzurantTworzacy::XLiczniki*>(odpowiedniKlucz, nowyEl));
    }
    //kopiowanie obiektu do bazy danych
    db = gr->db;    //trzeba na to uważać - przekazywany jest potencjalnie pusty, a potencjalnie pełny wskaźnik
    tablicaDyzurantowTworzacych = gr->tablicaDyzurantowTworzacych;  //uwaga, ten obiekt jest "gdzie indziej"
    licznikStworzonychGrafikow = gr->licznikStworzonychGrafikow; //tylko kopiujemy wskaźnik, obiekt jest już stworzony
    zakonczenieSzukania = gr->zakonczenieSzukania;   //tylko kopiujemy wskaźnik, obiekt jest już stworzony
    licznikOstatecznyStworzonychGrafikow = gr->licznikOstatecznyStworzonychGrafikow;    //jw.
    liczbaIteracji = gr->liczbaIteracji;    //jw.
    parentWorker = gr->parentWorker;  //jw.
    //zmienne do ew. przyspieszacza (związane z timerem)
    czyPrzyspieszenie = gr->czyPrzyspieszenie;
    licznikSkrocen = gr->licznikSkrocen;
    decyzjaOSkroceniu = gr->decyzjaOSkroceniu;
    mutex = gr->mutex;
    skracaniePomimoUlozenia = gr->skracaniePomimoUlozenia;
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
        (*it)->statusUstawiania = USTAWIONY_NIE_DO_RUSZENIA;
        lider->liczniki->incLiczbaDyzurow((*it)->dzienTygodnia);
        lider->liczniki->dodajDyzur((*it)->liczbaDnia);
        (*(it-1))->mozliwiDyzuranci.erase(lider->getId());  //usuniecie z mozliwosci dnia poprzedniego
        (*(it+1))->mozliwiDyzuranci.erase(lider->getId());  //usuniecie z mozliwosci dnia nastepnego
        (*it)->unikajacyDyzuranci.erase(lider->getId());	//moglo byc tak ze zostalo wstawione z unikania ciagow
        //dzien ustawiony, teraz patrzymy na unikanie ciągów dla lidera który właśnie dostał nowy dyżur
        unikanieKrotnosc = lider->getUnikaniePodRzad();
        lider->liczniki->sortujDyzury();		//trzeba posortowac
        if (unikanieKrotnosc != 0) {	//przyspieszy program
            tablicaPar = lider->liczniki->znajdzSekwencje(unikanieKrotnosc);
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
        //a teraz patrzymy na unikanie trójek
        int unikanieTrojek = lider->getUnikanieTrojek();
        if (unikanieTrojek != 0) {
            std::vector<int> dyzuryLidera = lider->liczniki->zwrocDyzury();
            for (auto it4=dyzuryLidera.begin(); it4<dyzuryLidera.end(); ++it4) {
                int dzien = *it4;
                if (dzien - 3 > 0) {
                    if (tablicaDni[dzien-3]->dyzurantWybrany != lider) {
                        tablicaDni[dzien-3]->unikajacyDyzuranci.insert(std::pair<int,XDyzurantTworzacy*>(lider->getId(), lider));
                    }
                }
                if (dzien < liczbaDni-1) {
                    if (tablicaDni[dzien+3]->dyzurantWybrany != lider) {
                        tablicaDni[dzien+3]->unikajacyDyzuranci.insert(std::pair<int,XDyzurantTworzacy*>(lider->getId(), lider));
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

bool XGrafik::sprawdzZgodnoscZMinimalnaLiczbaDyzurowDlaWszystkich() {
    for (auto el : mapaLicznikowDyzurantow) {
        if (el.second->liczbaDyzurow < el.second->parent->getMinimalnie()) {
            return false;
        }
    }
    return true;
}

void XGrafik::wypelnijGrafikDyzurantami(std::vector<XDyzurantTworzacy*>* tdt, int ileIteracji, TWorker* pw, bool czyP, bool* decS, int* licS, QMutex* mut, bool spu) {
    //ustawienie zmiennych odnośnie przyspieszenia (związane z timerem)
    czyPrzyspieszenie = czyP;
    decyzjaOSkroceniu = decS;
    licznikSkrocen = licS;
    mutex = mut;
    skracaniePomimoUlozenia = spu;
    //ustawienie wskaźnika do obiektu 'w którym' biegnie odpowiedni wątek
    parentWorker = pw;
    //uzupełnienie wskaźnika do tablicy dyżurantów tworzących (pochodzi z obiektu MNoweGrafiki)
    tablicaDyzurantowTworzacych = tdt;
    //stworzenie mapy licznikow dla odpowiednich dyzurantow tworzących
    XDyzurantTworzacy::XLiczniki* elementMapy(nullptr);
    int odpowiedniKlucz(-1);
    for (auto it=tablicaDyzurantowTworzacych->begin(); it<tablicaDyzurantowTworzacych->end(); ++it) {
        elementMapy = new XDyzurantTworzacy::XLiczniki((*it)->liczniki);
        odpowiedniKlucz = (*it)->getId();
        mapaLicznikowDyzurantow.insert(std::pair<int, XDyzurantTworzacy::XLiczniki*>(odpowiedniKlucz, elementMapy));
    }
    //stworzenie w "globalnej" przestrzeni licznika stworzonych grafików oraz zmiennej od decyzji dalszego szukania i innych zmiennych sterujących
    licznikStworzonychGrafikow = new int(0);
    zakonczenieSzukania = new bool(false);  //false - czyli szukamy do oporu
    licznikOstatecznyStworzonychGrafikow = new int(0);
    liczbaIteracji = new int(ileIteracji);
    //inicjalizacja funkcji pseudolosowej
    srand(time(0));

    if (czyPrzyspieszenie) {        //jeśli działamy na przyspieszaczu, włączamy timer
        parentWorker->startTimerX();
    }
    bool result = wypelnijDzien(1);

    //ten moment uruchamia się po powrocie z całego procesu wyszukiwania grafików
    //usuwamy powyższe zmienne sterujące
    delete licznikStworzonychGrafikow;
    licznikStworzonychGrafikow = nullptr;
    delete zakonczenieSzukania;
    zakonczenieSzukania = nullptr;
    //kończymy pracę obiektu  odpowiedzialnego za komunikację, ale przedtem wyswietlamy komunikat o zakończeniu szukania grafików
    parentWorker->pokazKomunikatZakonczeniaSzukania(result, *licznikOstatecznyStworzonychGrafikow);
    //teraz prezenter już nie istnieje, więc likwidujemy pozostałe zmienne sterujące
    delete licznikOstatecznyStworzonychGrafikow;
    licznikOstatecznyStworzonychGrafikow = nullptr;
    delete liczbaIteracji;
    liczbaIteracji = nullptr;
    //chyba koniec ???

}

void XGrafik::dodajUnikanieTrojek(XDyzurantTworzacy::XLiczniki* licznikDt, XDyzurantTworzacy* dt, int klucz, bool& result, int dzien) {
    licznikDt->sortujDyzury();
    result = true;
    std::vector<int> dyzury = licznikDt->zwrocDyzury();
    for (auto it3=dyzury.begin(); it3<dyzury.end(); ++it3) {
        int dzienX = *it3;
        if (dzienX-3 > dzien && dzienX-3 > 0) {
            if (tablicaDni[dzienX-3]->dyzurantWybrany != dt) {
                tablicaDni[dzienX-3]->unikajacyDyzuranci.insert(std::pair<int,XDyzurantTworzacy*>(klucz, dt));
                tablicaDni[dzienX-3]->mozliwiNieUnikajacyDyzuranci.erase(klucz);
                if (tablicaDni[dzienX-3]->mozliwiNieUnikajacyDyzuranci.empty()) {
                    result = false;
                    return;
                }
            }
        }
        if (dzienX+3 > dzien && dzienX+3 <= liczbaDni) {
            if (tablicaDni[dzienX+3]->dyzurantWybrany != dt) {
                tablicaDni[dzienX+3]->unikajacyDyzuranci.insert(std::pair<int,XDyzurantTworzacy*>(klucz, dt));
                tablicaDni[dzienX+3]->mozliwiNieUnikajacyDyzuranci.erase(klucz);
                if (tablicaDni[dzienX+3]->mozliwiNieUnikajacyDyzuranci.empty()) {
                    result = false;
                    return;
                }
            }
        }
    }
}

void XGrafik::dodajUnikanie(XDyzurantTworzacy::XLiczniki* licznikDt, XDyzurantTworzacy* dt, int klucz, int unikanieKrotnosc, bool& result, int dzien) {   //dodaje unikanie i od razu przelicza tablicę MOZLIWI_NIE_UNIKAJACY
    licznikDt->sortujDyzury();
    result = true;
    std::vector<int> tablicaPar;
    int lewy(0), prawy(0);
    tablicaPar = licznikDt->znajdzSekwencje(unikanieKrotnosc);
    for (auto it3 = tablicaPar.begin(); it3 < tablicaPar.end(); it3 += 2) {
        lewy = *it3;
        prawy = *(it3+1);
        if (lewy-2 > dzien && lewy-2 > 0) { //ustawiamy tylko wprzód!
            if (tablicaDni[lewy-2]->dyzurantWybrany != dt) {
                tablicaDni[lewy-2]->unikajacyDyzuranci.insert(std::pair<int,XDyzurantTworzacy*>(klucz, dt));
                tablicaDni[lewy-2]->mozliwiNieUnikajacyDyzuranci.erase(klucz);
                //przeliczMozliwiNieUnikajacyDyzuranciDlaJednegoDnia(lewy-2);
                //no i mogło się okazać że wyleciał w tym dniu zbiór MOZLIWI_NIE_UNIKAJACY !
                if (tablicaDni[lewy-2]->mozliwiNieUnikajacyDyzuranci.size() == 0) {
                    result = false;     //wiec trzeba wyjsc z błędem.
                    return;
                }
            }
        }
        if (prawy+2 > dzien && prawy+2 <= liczbaDni) { //ustawiamy tylko wprzód!
            if (tablicaDni[prawy+2]->dyzurantWybrany != dt) {
                tablicaDni[prawy+2]->unikajacyDyzuranci.insert(std::pair<int,XDyzurantTworzacy*>(klucz, dt));
                tablicaDni[prawy+2]->mozliwiNieUnikajacyDyzuranci.erase(klucz);
                //przeliczMozliwiNieUnikajacyDyzuranciDlaJednegoDnia(prawy+2);
                //no i mogło się okazać że wyleciał w tym dniu zbiór MOZLIWI_NIE_UNIKAJACY !
                if (tablicaDni[prawy+2]->mozliwiNieUnikajacyDyzuranci.size() == 0) {
                    result = false;     //wiec trzeba wyjsc z błędem.
                    return;
                }
            }
        }
    }
}

bool XGrafik::losujDyzurantaDoDyzuruPoKluczu(int dzien, int& kluczWybranegoDyzuranta) {
    //najpierw sprawdzamy, czy już może nie jest ten dzień ustawiony (np. z ustawień wstępnych)
    if (tablicaDni[dzien]->statusUstawiania == USTAWIONY_NIE_DO_RUSZENIA) { //to oznacza że był wstawiony z ustawień wstępnych
        kluczWybranegoDyzuranta = tablicaDni[dzien]->dyzurantWybrany->getId();
        return true;    //jeśli tak to kończymy
    }
    //a teraz trzeba sprawdzić czy w ogóle jest z czego wybierać
    if (tablicaDni[dzien]->mozliwiNieUnikajacyDyzuranci.empty()) {
        kluczWybranegoDyzuranta = -1;
        return false;
    }
    //teraz losujemy z możliwych odpowiedniego dyżuranta
    auto it = tablicaDni[dzien]->mozliwiNieUnikajacyDyzuranci.begin();
    std::advance(it, rand() % (tablicaDni[dzien]->mozliwiNieUnikajacyDyzuranci.size()));
    //a teraz zmienne odnoszące się do róznych elementów wylosowanego dyżuranta
    XDyzurantTworzacy* dt = it->second; //wskaźnik do tablicy dyżurantów tworzących
    int klucz = it->first;  //klucz
    kluczWybranegoDyzuranta = klucz;    //też klucz, ale przekazywany na zewnątrz procedury
    XDyzurantTworzacy::XLiczniki* licznikDt = mapaLicznikowDyzurantow[klucz];
    //w pierwszej kolejności zwiekszamy liczniki danego dyzuranta
    licznikDt->incLiczbaDyzurow(tablicaDni[dzien]->dzienTygodnia);
    //i sprawdzamy czy liczniki nie zostały przekroczone
    if (!(licznikDt->sprawdzZgodnoscMaksymalnejLiczbyDyzurow() && licznikDt->sprawdzZgodnoscLiczbySobotINiedzielIWeekendow())) {
        //dt->decLiczbaDyzurow(tablicaDni[dzien]->dzienTygodnia);   //niepotrzebne, przy return false i tak liczniki są niszczone
        return false;
    }
    if (!(licznikDt->sprawdzZgodnoscLiczbyPiatkow())) {
        return false;
    }
    //liczniki nie zostały przekroczone, więc dodajemy do listy dyżurów
    licznikDt->dodajDyzur(dzien);
    //przypisanie dyżuranta do dnia
    tablicaDni[dzien]->dyzurantWybrany = dt;
    tablicaDni[dzien]->statusUstawiania = USTAWIONY_WSTEPNIE;   //widać że był wstawiony z losowania
    //wyrzucenie z tablic MOZLIWY i MOZLIWY_NIE_UNIKAJACY
    tablicaDni[dzien]->mozliwiDyzuranci.erase(klucz);
    tablicaDni[dzien]->mozliwiNieUnikajacyDyzuranci.erase(klucz);
    //usuniecie z tablic MOZLIWY I MOZLIWY_NIE_UNIKAJACY z dni sasiednich
    tablicaDni[dzien-1]->mozliwiDyzuranci.erase(klucz);
    tablicaDni[dzien-1]->mozliwiNieUnikajacyDyzuranci.erase(klucz);
    tablicaDni[dzien+1]->mozliwiDyzuranci.erase(klucz);
    tablicaDni[dzien+1]->mozliwiNieUnikajacyDyzuranci.erase(klucz);
    //dodawanie unikania w razie włączonej opcji unikania ciągów
    int krotnoscUnikanie = dt->getUnikaniePodRzad();
    bool resultDodaniaUnikania(false);
    if (krotnoscUnikanie != 0) {
        dodajUnikanie(licznikDt, dt, klucz, krotnoscUnikanie,resultDodaniaUnikania, dzien);     //dodaje unikanie i od razu przelicza tablicę MOZLIWI_NIE_UNIKAJACY
        if (!resultDodaniaUnikania) {
            //licznikDt->decLiczbaDyzurow(tablicaDni[dzien]->dzienTygodnia);     //trzeba cofnąć zmiany w tablicy dyżurantów - niepotrzebne - patrz wyżej
            //licznikDt->usunDyzur(dzien);       //nie mogę przez pop_back, bo dokonano sortowania przed szukaniem sekwencji - niepotrzebne - patrz wyżej
            return false;
        }
    }
    //dodawanie unikania w razie włączonej opcji unikania trójek
    int unikanieTrojek = dt->getUnikanieTrojek();
    bool resultDodaniaUnikaniaTrojek(false);
    if (unikanieTrojek != 0) {
        dodajUnikanieTrojek(licznikDt, dt, klucz, resultDodaniaUnikaniaTrojek, dzien);
        if (!resultDodaniaUnikaniaTrojek) {
            return false;
        }
    }
    //przeszliśmy wszystkie etapy - jest OK.
    return true;
}

bool XGrafik::wypelnijDzien(int dzien) {        //glowna funkcja wywolywana rekurencyjnie
    //qDebug() << "Odpalono procedurę rekurencyjną";
//UWAGA: jeśli *zakończenieSzukania==false, to oznacza że traktujemy jakby grafik nie był znaleziony czyli szukamy do oporu
//jeśli *zakończenieSzukania==true, to funkcja będzie wychodzić z pętli byle szybciej
//ten "przełącznik" zakończenieSzukania służy do tego by w razie decyzji o zaprzestaniu poszukiwań móc posprzątać cały rekurencyjny bałagan który się stworzył

    //najpierw pokazujemy który dzień właśnie ogarniamy
    parentWorker->pokazLiczbeObrotow(dzien);
    //teraz sprawdzamy warunek wyjścia z procedury
    if (dzien > liczbaDni) {
        //czyli ułożyliśmy cały grafik !!!!! - ale trzeba jeszcze sprawdzic czy zgadza sie minimalna liczba dyzurow dla kazdego dyzuranta
        if (!sprawdzZgodnoscZMinimalnaLiczbaDyzurowDlaWszystkich()) {
            return *zakonczenieSzukania;   //jeśli nie to spadamy.
        }
        //jeśli tak - tworzymy - lub wykorzystujemy obiekt komunikatora z bazą danych...
        if (db == nullptr) {
            db = new DBObslugiwaczBazyDanych();
        }
        //... oraz zapisujemy do pliku...
        db->zapiszUlozonyGrafikDoPliku(this, *licznikOstatecznyStworzonychGrafikow);
        //... zwiększamy licznik stworzonych grafików
        (*licznikStworzonychGrafikow)++;
        (*licznikOstatecznyStworzonychGrafikow)++;
        parentWorker->pokazLiczbeInteracji(*licznikOstatecznyStworzonychGrafikow);  //wysyłamy na ekran ilość zrobionych grafików
        //.... oraz resetujemy timer, jeśli działamy na przyspieszaczu I NIE SKRACAMY POMIMO ułożenia grafiku (co znalezienie grafiku to timer się resetuje
        if (czyPrzyspieszenie) {
            if (!skracamyPomimoUlozenia) {
                parentWorker->startTimerX();
            }
        }
        //... oraz sprawdzamy czy nie doszliśmy do progu decyzji o wyświetleniu okna co do dalszych poszukiwań
        if (*licznikStworzonychGrafikow >= (*liczbaIteracji)) {
            parentWorker->przymknijOknoProgresu();  //najpierw przymykamy okno progresu żeby nie zasłaniało
            int wybor = parentWorker->zapytajOKontynuacje();   //nie będzie powrotu z tej funkcji przed decyzją użytkownika
            if (wybor == 1) {
                *zakonczenieSzukania = false;
            }
            else if (wybor == 2) {
                *zakonczenieSzukania = true;
            }
            *licznikStworzonychGrafikow = 0;        //zerujemy licznik, od nowa liczymy "dziesiątkę grafików"
            parentWorker->pokazOknoProgresu();      //z powrotem pokazujemy okno progresu
        }
        //teraz jesteśmy za wyboremm czyli okno decyzji zniknęło, program się odblokował, więc z powrotem wyświetlamy okno postępu
        //...i spadamy.
        return *zakonczenieSzukania;
    }
    XGrafik* nowyGrafik(nullptr);
    bool resultDodania(false);
    int kluczWybranegoDyzurantaDoTegoDnia(-1);
    do {
        do {
            if (nowyGrafik != nullptr){         //robi się tylko gdy warunek pętli się schrzanił i trzeba liczyć jeszcze raz
                //dla USTAWIONY_NIE_DO_RUSZENIA cała ta instrukcja warunkowa uruchomiona była została z drugiego warunku, czyli trzeba wrócić krok wstecz
                //tutaj nie ma znaczenia pustość tablicy MOŻLIWI NIE UNIKAJĄCY - bez niniejszego warunku ustawiony sztywno dyżurant uniemożliwiałby powrót algorytmu
                if (tablicaDni[dzien]->statusUstawiania == USTAWIONY_NIE_DO_RUSZENIA) {
                    delete nowyGrafik;
                    nowyGrafik = nullptr;
                    return *zakonczenieSzukania;
                }
                //wyrzucamy z tablicy MOZLIWE dla DANEGO DNIA - UWAGA: AKTUALNEGO GRAFIKU!!! - dyzuranta, którego wstawienie zakończyło się klęską
                if (kluczWybranegoDyzurantaDoTegoDnia != -1) {
                    tablicaDni[dzien]->mozliwiDyzuranci.erase(kluczWybranegoDyzurantaDoTegoDnia);
                    tablicaDni[dzien]->mozliwiNieUnikajacyDyzuranci.erase(kluczWybranegoDyzurantaDoTegoDnia);
                }
                //usuwamy stworzony do celów byłego dodawania grafik - tam jest za duży rozpierdol żeby cofać zmiany, trzeba zrekonstruować cały obiekt na nowo
                delete nowyGrafik;
                nowyGrafik = nullptr;
                //a teraz BARDZO WAŻNE: tablica MOŻLIWI NIE UNIKAJĄCY mogła się właśnie wyczyścić, więc trzeba wtedy ZAKOŃCZYĆ DZIAŁANIE TEJ INSTANCJI
                if (tablicaDni[dzien]->mozliwiNieUnikajacyDyzuranci.empty()) {
                    return *zakonczenieSzukania;
                }
                //teraz - jeśli jesteśmy na przyspieszaczu - sprawdzamy czy nie trzeba zakończyć procedury i skrócić (wrócić)
                //odbywa się to PO usunięciu najnowszego grafiku z którego nastąpił powrót - dzięki temu nie powinno być wycieku pamięci
                if (czyPrzyspieszenie) {
                    //blokujemy dostęp do danych
                    mutex->lock();
                    if (*decyzjaOSkroceniu) {
                        if (*licznikSkrocen > 0 && dzien > 1) {     //czyli jesteśmy w jakiejś dalszej iteracji, czyli można śmiało skracać
                            (*licznikSkrocen)--;
                            mutex->unlock();    //odblokowujemy przed skróceniem
                            return false;
                        }
                        else if (*licznikSkrocen > 0 && dzien <= 1) {   //drugie oznacza że jesteśmy w pierwszej iteracji, czyli lepiej nie wychodźmy z niej
                            *licznikSkrocen = 0;
                            *decyzjaOSkroceniu = false;
                            parentWorker->startTimerX();     //ponieważ to już był ostatni skrót, na nowo włączamy timer
                        }
                        else {      //czyli *licznikSkrocen == 0. Więc koniec skracania.
                            *licznikSkrocen = 0;    //redundantne, ale może lepiej niech zostanie
                            *decyzjaOSkroceniu = false; //kończymy cykl skracania
                            parentWorker->startTimerX(); //ponieważ był to już ostatni skrót, restartujemy timer
                            mutex->unlock();    //odblokowujemy jw.
                            return false;
                        }
                    }
                    mutex->unlock();    //odblokowujemy dostęp do zmiennych sterujących
                }
            }
            nowyGrafik = new XGrafik(this);
            resultDodania = nowyGrafik->losujDyzurantaDoDyzuruPoKluczu(dzien, kluczWybranegoDyzurantaDoTegoDnia);
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
    return *zakonczenieSzukania;
}

std::string XGrafik::getMiesiacRok() {
    std::string miesiacPart = przeliczMiesiacNaLiczbe(miesiac);
    std::string rokPart = std::to_string(rok);
    std::string miesiacRok = miesiacPart + "_" + rokPart;
    return miesiacRok;
}

XGrafik::~XGrafik() {
    //usuwanie każdego dnia z tablicy dni
    for (auto it=tablicaDni.begin(); it<tablicaDni.end(); ++it) {
        if ((*it) != nullptr) {
            delete (*it);
            (*it) = nullptr;
        }
    }
    //usuwanie kazdej pozycji z liczników dla dyzurantów tworzacych
    for (auto el : mapaLicznikowDyzurantow) {
        if (el.second != nullptr) {
            delete el.second;
            el.second = nullptr;
        }
    }
    //usuwanie obiektu dostepu do bazy danych
    if (db != nullptr) {
        delete db;
        db = nullptr;
    }
}

//XWyswietlanyGrafik===================================================================================================================================================================================

XWyswietlanyGrafik::XWyswietlanyGrafik(std::string np) : listaPozycjiGrafiku(nullptr), nazwaPliku(np) {
    listaPozycjiGrafiku = new std::vector<XPozycjaGrafiku*>();
}

XWyswietlanyGrafik::~XWyswietlanyGrafik() {
    XPozycjaGrafiku* doUsuniecia(nullptr);
    if (listaPozycjiGrafiku != nullptr) {
        for (auto it = listaPozycjiGrafiku->begin(); it<listaPozycjiGrafiku->end(); ++it) {
            if ((*it) != nullptr) {
                doUsuniecia = *it;
                delete doUsuniecia;
                doUsuniecia = nullptr;
                *it = nullptr;
            }
        }
        delete listaPozycjiGrafiku;
    }
}

//XWyswietlanyGrafik::XPozycjaGrafiku=====================================================================================================================================================================

XWyswietlanyGrafik::XPozycjaGrafiku::XPozycjaGrafiku(QString dz, QString dt, QString dy) 
    : dzien(dz), dzienTygodnia(dt), dyzurant(dy) {}



