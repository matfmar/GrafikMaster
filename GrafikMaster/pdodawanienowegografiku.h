
#ifndef PDODAWANIENOWEGOGRAFIKU_H
#define PDODAWANIENOWEGOGRAFIKU_H

#include <vector>
#include <QString>

class MNoweGrafiki;
class MDyzuranci;
class UIDodawanieNowegoGrafikuWstep;
class UIDodawanieNowegoGrafiku;
class XDyzurant;
class XDyzurantTworzacy;
enum Miesiac : int;
enum DzienTygodnia : int;

class PDodawanieNowegoGrafiku {
public:
    PDodawanieNowegoGrafiku();
    ~PDodawanieNowegoGrafiku();
    void wybranoDodanieInformacjiWstepnychNowegoGrafiku(int r, int ld, Miesiac m, DzienTygodnia dt);
    QString wybranoDodanieDyzurantaTworzacego(QString nick);
    void wybranoUsuniecieDyzurantaTworzacego(QString nick);
    XDyzurantTworzacy* wybranoPobranieDanychDyzurantaTworzacego(QString nick);
private:
    UIDodawanieNowegoGrafikuWstep* uiDodawanieNowegoGrafikuWstep;
    UIDodawanieNowegoGrafiku* uiDodawanieNowegoGrafiku;
    MNoweGrafiki* mNoweGrafiki;
    MDyzuranci* mDyzuranci;
    std::vector<XDyzurant*>* tablicaDyzurantow;
};

#endif // PDODAWANIENOWEGOGRAFIKU_H
