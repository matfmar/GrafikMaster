#include "dto.h"

//XDyzurant
XDyzurant::XDyzurant()
    : id(0), nick(""), priorytet(0) {}

XDyzurant::XDyzurant(int a, std::string s, int b)
    : id(a), nick(s), priorytet(b) {}

std::string XDyzurant::getNick() {
    return nick;
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
    : XDyzurant(), maksymalnie(0), minimalnie(0), unikaniePodRzad(0) {}

XDyzurantTworzacy::XDyzurantTworzacy(int a, std::string s, int b, int c, int d, int e)
    : XDyzurant(a, s, b), maksymalnie(c), minimalnie(d), unikaniePodRzad(e) {}

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


