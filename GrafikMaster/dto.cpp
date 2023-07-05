#include "dto.h"

//XDyzurant
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

//XDyzurantTworzacy
XDyzurantTworzacy::XDyzurantTworzacy()
    : XDyzurant(), maksymalnie(0), minimalnie(0), unikaniePodRzad(0),
    maksymalnieSoboty(0), maksymalnieNiedziele(0), maksymalnieWeekendy(0), wpisywanieGdzieMoze(false) {}

XDyzurantTworzacy::XDyzurantTworzacy(int a, std::string s, int b, int c, int d, int e, int sb, int nd, int wk, bool wgm)
    : XDyzurant(a, s, b), maksymalnie(c), minimalnie(d), unikaniePodRzad(e),
    maksymalnieSoboty(sb), maksymalnieNiedziele(nd), maksymalnieWeekendy(wk), wpisywanieGdzieMoze(wgm) {}

XDyzurantTworzacy::XDyzurantTworzacy(XDyzurant* d)
    : XDyzurant(d), maksymalnie(0), minimalnie(0), unikaniePodRzad(0),
    maksymalnieSoboty(0), maksymalnieNiedziele(0), maksymalnieWeekendy(0), wpisywanieGdzieMoze(false) {}

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

//XDzien
XDzien::XDzien()
    : dzienTygodnia(NIEZNANY_DZIEN), liczbaDnia(0), czySwieto(false), statusUstawiania(NIEZNANY_STATUS), dyzurantWybrany(nullptr) {}

XDzien::XDzien(DzienTygodnia dt, int ld, bool czs, StatusDnia sd, XDyzurantTworzacy* dw)
    : dzienTygodnia(dt), liczbaDnia(ld), czySwieto(czs), statusUstawiania(sd), dyzurantWybrany(dw) {}

//XGrafik
XGrafik::XGrafik()
    : rok(0), miesiac(NIEZNANY_MIESIAC), status(NIEZNANY_STATUS_GRAFIKU), liczbaDni(0), pierwszyDzien(NIEZNANY_DZIEN) {}

XGrafik::XGrafik(int r, Miesiac m, StatusGrafiku st, int ld, DzienTygodnia pd)
    : rok(r), miesiac(m), status(st), liczbaDni(ld), pierwszyDzien(pd) {}


