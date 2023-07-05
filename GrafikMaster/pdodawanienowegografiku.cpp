
#include "pdodawanienowegografiku.h"
#include "uidodawanienowegografikuwstep.h"
#include "uidodawanienowegografiku.h"
#include "mnowegrafiki.h"
#include "dto.h"
#include "mdyzuranci.h"

PDodawanieNowegoGrafiku::PDodawanieNowegoGrafiku()
    : uiDodawanieNowegoGrafikuWstep(nullptr), mNoweGrafiki(nullptr), uiDodawanieNowegoGrafiku(nullptr), tablicaDyzurantow(nullptr), mDyzuranci(nullptr) {
    mNoweGrafiki = new MNoweGrafiki();
    std::vector<Miesiac> tabMiesiace;
    std::vector<DzienTygodnia> tabDniTygodnia;
    mNoweGrafiki -> wyciagnijTabliceMiesiecyIDniTygodnia(tabMiesiace, tabDniTygodnia);
    uiDodawanieNowegoGrafikuWstep = new UIDodawanieNowegoGrafikuWstep(tabMiesiace, tabDniTygodnia, this);
    uiDodawanieNowegoGrafikuWstep -> show();
}

void PDodawanieNowegoGrafiku::wybranoDodanieInformacjiWstepnychNowegoGrafiku(int r, int ld, Miesiac m, DzienTygodnia dt) {
    XGrafik* nowyGrafik = mNoweGrafiki ->utworzNowyGrafik(r, ld, m, dt);
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

}
