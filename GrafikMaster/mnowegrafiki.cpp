
#include "mnowegrafiki.h"
#include "dto.h"

MNoweGrafiki::MNoweGrafiki()
    : nowyGrafik(nullptr) {
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
    return nowyGrafik;
}

MNoweGrafiki::~MNoweGrafiki() {
    if (nowyGrafik != nullptr) {
        delete nowyGrafik;
        nowyGrafik = nullptr;
    }
}
