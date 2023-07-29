
#include "pdodawanienowegografiku.h"
#include "uidodawanienowegografikuwstep.h"
#include "uidodawanienowegografiku.h"
#include "mnowegrafiki.h"
#include "dto.h"
#include "mdyzuranci.h"

#include "uitworzonegrafiki.h"  //debug only

PDodawanieNowegoGrafiku::PDodawanieNowegoGrafiku()
    : uiDodawanieNowegoGrafikuWstep(nullptr), mNoweGrafiki(nullptr), uiDodawanieNowegoGrafiku(nullptr), tablicaDyzurantow(nullptr), mDyzuranci(nullptr),
    uiTworzoneGrafiki(nullptr), decyzjaWarunkowPoczatkowychGrafiku(0) {
    mNoweGrafiki = new MNoweGrafiki();
    std::vector<Miesiac> tabMiesiace;
    std::vector<DzienTygodnia> tabDniTygodnia;
    mNoweGrafiki -> wyciagnijTabliceMiesiecyIDniTygodnia(tabMiesiace, tabDniTygodnia);
    uiDodawanieNowegoGrafikuWstep = new UIDodawanieNowegoGrafikuWstep(tabMiesiace, tabDniTygodnia, this);
    uiDodawanieNowegoGrafikuWstep -> show();
}

bool PDodawanieNowegoGrafiku::wybranoZapisanieParametrowGrafiku(std::vector<QString> daneDoZapisu) {
    return (mNoweGrafiki->zapiszParametryGrafiku(daneDoZapisu));
}

std::vector<QString> PDodawanieNowegoGrafiku::wybranoWczytanieParametrowGrafiku(bool& result) {
    return (mNoweGrafiki->wczytajParametryGrafiku(result));
}

void PDodawanieNowegoGrafiku::wybranoDodanieInformacjiWstepnychNowegoGrafiku(int r, int ld, Miesiac m, DzienTygodnia dt, QString listaSwiat, bool& result) {
    XGrafik* nowyGrafik = mNoweGrafiki ->utworzNowyGrafik(r, ld, m, dt, listaSwiat, result);
    if (!result) {
        return;
    }
    uiDodawanieNowegoGrafikuWstep -> close();
    mDyzuranci = new MDyzuranci();
    tablicaDyzurantow = mDyzuranci -> wyciagnijTabliceDyzurantow();
    uiDodawanieNowegoGrafiku = new UIDodawanieNowegoGrafiku(tablicaDyzurantow, this);
    uiDodawanieNowegoGrafiku -> show();
}

QString PDodawanieNowegoGrafiku::wybranoDodanieDyzurantaTworzacego(QString nick) {
    XDyzurant* dyzurantZlokalizowany(nullptr);
    for (auto it = tablicaDyzurantow->begin(); it<tablicaDyzurantow->end(); ++it) {
        if ((*it)->getNick() == (nick.toStdString())) {
            dyzurantZlokalizowany = *it;
            break;
        }
    }
    std::string nowyNick = mNoweGrafiki -> utworzDyzurantaTworzacego(dyzurantZlokalizowany);
    return (QString::fromStdString(nowyNick));
}

void PDodawanieNowegoGrafiku::wybranoUsuniecieDyzurantaTworzacego(QString nick) {
    mNoweGrafiki -> usunDyzurantaTworzacego(nick.toStdString());
}

XDyzurantTworzacy* PDodawanieNowegoGrafiku::wybranoPobranieDanychDyzurantaTworzacego(QString nick) {
    XDyzurantTworzacy* xdt = mNoweGrafiki -> pobierzDaneDyzurantaTworzacego(nick.toStdString());
    return xdt;
}

bool PDodawanieNowegoGrafiku::wybranoUpdateDyzurantaTworzacego(QString nick, bool czyM, QString m, QString nm, QString u,
                                                               QString ch, int maks, int min, int maksS, int maksN,
                                                               int maksW, int c, int maksP, int wyborT, int msbn, int mwzp) {
    bool result = mNoweGrafiki->updateDyzurantaTworzacego(nick.toStdString(), czyM, m.toStdString(), nm.toStdString(),
                                                          u.toStdString(), ch.toStdString(), maks, min,
                                                          maksS, maksN, maksW, c, maksP, wyborT, msbn, mwzp);
    return result;
}

void PDodawanieNowegoGrafiku::wybranoProsbeOStworzenieGrafiku(bool& immediateResult, int ileIteracji, int szybkosc, bool skracaniePomimoUlozenia) {
    XGrafik* grafikWstepny = mNoweGrafiki->wypelnijGrafikPierwszymiDanymi();

    //pokazujemy efekt pierwszych danych na grafik
    if (uiTworzoneGrafiki != nullptr) {
        delete uiTworzoneGrafiki;
        uiTworzoneGrafiki = nullptr;
    }
    uiTworzoneGrafiki = new UITworzoneGrafiki(grafikWstepny, this);
    uiTworzoneGrafiki->exec();  //blokujące program

    if (decyzjaWarunkowPoczatkowychGrafiku == 0) {
        return;
    }

    //jeśli jest ok, to idziemy dalej.
    mNoweGrafiki->wypelnijGrafikDyzurantami(immediateResult, ileIteracji, szybkosc, skracaniePomimoUlozenia);

    if (immediateResult) {      //przy dobrej wstepnej weryfikacji zamykamy okno tworzenia grafikow
        uiDodawanieNowegoGrafiku->close();
    }


}

void PDodawanieNowegoGrafiku::wybranoDecyzjeWarunkowPoczatkowychGrafiku(int decyzja) {
    decyzjaWarunkowPoczatkowychGrafiku = decyzja;
}

bool PDodawanieNowegoGrafiku::wybranoZapisanieUstawienDoPliku() {
    bool najpierwUsuniecie = mNoweGrafiki->usunWszystkieUstawieniaZPlikow();
    return (mNoweGrafiki->zapiszUstawieniaDoPliku());
}

std::vector<std::string> PDodawanieNowegoGrafiku::wybranoWczytanieUstawien() {
    return (mNoweGrafiki->wczytajUstawienia(tablicaDyzurantow));
}

bool PDodawanieNowegoGrafiku::wybranoUsunWszystkieUstawienia() {
    return (mNoweGrafiki->usunWszystkieUstawieniaZPlikow());
}

PDodawanieNowegoGrafiku::~PDodawanieNowegoGrafiku() {
    if (mNoweGrafiki != nullptr) {
        delete mNoweGrafiki;
        mNoweGrafiki = nullptr;
    }
    if (uiDodawanieNowegoGrafikuWstep != nullptr) {
        delete uiDodawanieNowegoGrafikuWstep;
        uiDodawanieNowegoGrafikuWstep = nullptr;
    }
    if (uiDodawanieNowegoGrafiku != nullptr) {
        delete uiDodawanieNowegoGrafiku;
        uiDodawanieNowegoGrafiku = nullptr;
    }
    if (mDyzuranci != nullptr) {
        delete mDyzuranci;
        mDyzuranci = nullptr;
    }
    if (uiTworzoneGrafiki != nullptr) {
        delete uiTworzoneGrafiki;
        uiTworzoneGrafiki = nullptr;
    }

}
