
#include "mnowegrafiki.h"
#include "dto.h"

MNoweGrafiki::MNoweGrafiki() {
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

MNoweGrafiki::~MNoweGrafiki() {

}
