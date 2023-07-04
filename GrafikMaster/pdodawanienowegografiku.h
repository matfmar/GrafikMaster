
#ifndef PDODAWANIENOWEGOGRAFIKU_H
#define PDODAWANIENOWEGOGRAFIKU_H

#include <vector>

class MNoweGrafiki;
class MDyzuranci;
class UIDodawanieNowegoGrafikuWstep;
class UIDodawanieNowegoGrafiku;
class XDyzurant;
enum Miesiac : int;
enum DzienTygodnia : int;

class PDodawanieNowegoGrafiku {
public:
    PDodawanieNowegoGrafiku();
    ~PDodawanieNowegoGrafiku();
    void wybranoDodanieInformacjiWstepnychNowegoGrafiku(int r, int ld, Miesiac m, DzienTygodnia dt);
private:
    UIDodawanieNowegoGrafikuWstep* uiDodawanieNowegoGrafikuWstep;
    UIDodawanieNowegoGrafiku* uiDodawanieNowegoGrafiku;
    MNoweGrafiki* mNoweGrafiki;
    MDyzuranci* mDyzuranci;
    std::vector<XDyzurant*>* tablicaDyzurantow;
};

#endif // PDODAWANIENOWEGOGRAFIKU_H
