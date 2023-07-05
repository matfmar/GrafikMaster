
#include "mnowegrafiki.h"
#include "dto.h"

MNoweGrafiki::MNoweGrafiki()
    : nowyGrafik(nullptr), tablicaDyzurantowTworzacych(nullptr) {
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
}
