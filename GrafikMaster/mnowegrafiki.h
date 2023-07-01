
#ifndef MNOWEGRAFIKI_H
#define MNOWEGRAFIKI_H

#include <vector>

enum Miesiac : int;
enum DzienTygodnia : int;

class MNoweGrafiki {
public:
    MNoweGrafiki();
    ~MNoweGrafiki();
private:
    std::vector<Miesiac> tablicaMiesiecy;
    std::vector<DzienTygodnia> tablicaDniTygodnia;

    void wypelnijTabliceEnumeracyjne();
};

#endif // MNOWEGRAFIKI_H
