
#ifndef MNOWEGRAFIKI_H
#define MNOWEGRAFIKI_H

#include <vector>
#include <string>

enum Miesiac : int;
enum DzienTygodnia : int;
class XGrafik;
class XDyzurantTworzacy;
class XDyzurant;

class MNoweGrafiki {
public:
    MNoweGrafiki();
    ~MNoweGrafiki();
    void wyciagnijTabliceMiesiecyIDniTygodnia(std::vector<Miesiac>& tabM, std::vector<DzienTygodnia>& tabDT);
    XGrafik* utworzNowyGrafik(int r, int ld, Miesiac m, DzienTygodnia dt);
    std::string utworzDyzurantaTworzacego(XDyzurant* dyzurant);
    void usunDyzurantaTworzacego(std::string nick);
    XDyzurantTworzacy* pobierzDaneDyzurantaTworzacego(std::string nick);
private:
    std::vector<Miesiac> tablicaMiesiecy;
    std::vector<DzienTygodnia> tablicaDniTygodnia;
    XGrafik* nowyGrafik;
    std::vector<XDyzurantTworzacy*>* tablicaDyzurantowTworzacych;

    void wypelnijTabliceEnumeracyjne();
};

#endif // MNOWEGRAFIKI_H
