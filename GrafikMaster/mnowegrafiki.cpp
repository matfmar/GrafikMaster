
#include "mnowegrafiki.h"
#include "dto.h"
#include <QDebug>

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

bool MNoweGrafiki::updateDyzurantaTworzacego(std::string nick, bool czyM, std::string m, std::string nm, std::string u, std::string ch, int maks, int min, int maksS, int maksN, int maksW, int c) {
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
    dyzurant->setUnikaniePodRzad(c);
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
        if (!((*it)->sprawdzZgodnoscMaksymalnejLiczbyDyzurow() && (*it)->sprawdzZgodnoscLiczbySobotINiedzielIWeekendow()))
            return false;
    }
    return true;
}

void MNoweGrafiki::wypelnijGrafikDyzurantami(bool& immediateResult) {
    immediateResult = sprawdzWstepnieZgodnosc();
    if (!immediateResult) {
        return;
    }
    nowyGrafik -> wypelnijGrafikDyzurantami(tablicaDyzurantowTworzacych);
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
