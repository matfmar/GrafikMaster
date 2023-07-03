
#ifndef MNOWEGRAFIKI_H
#define MNOWEGRAFIKI_H

#include <vector>

enum Miesiac : int;
enum DzienTygodnia : int;
class XGrafik;

class MNoweGrafiki {
public:
    MNoweGrafiki();
    ~MNoweGrafiki();
    void wyciagnijTabliceMiesiecyIDniTygodnia(std::vector<Miesiac>& tabM, std::vector<DzienTygodnia>& tabDT);
    XGrafik* utworzNowyGrafik(int r, int ld, Miesiac m, DzienTygodnia dt);
private:
    std::vector<Miesiac> tablicaMiesiecy;
    std::vector<DzienTygodnia> tablicaDniTygodnia;
    XGrafik* nowyGrafik;

    void wypelnijTabliceEnumeracyjne();
};

#endif // MNOWEGRAFIKI_H
