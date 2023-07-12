
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

class UITworzoneGrafiki;    //debug only

class PDodawanieNowegoGrafiku {
public:
    PDodawanieNowegoGrafiku();
    ~PDodawanieNowegoGrafiku();
    void wybranoDodanieInformacjiWstepnychNowegoGrafiku(int r, int ld, Miesiac m, DzienTygodnia dt);
    QString wybranoDodanieDyzurantaTworzacego(QString nick);
    void wybranoUsuniecieDyzurantaTworzacego(QString nick);
    XDyzurantTworzacy* wybranoPobranieDanychDyzurantaTworzacego(QString nick);
    bool wybranoUpdateDyzurantaTworzacego(QString nick, bool czyM, QString m, QString nm, QString u, QString ch, int maks, int min, int maksS, int maksN, int maksW, int c);
    void wybranoProsbeOStworzenieGrafiku(bool& immediateResult);
    void wybranoDecyzjeWarunkowPoczatkowychGrafiku(int decyzja);

private:
    UIDodawanieNowegoGrafikuWstep* uiDodawanieNowegoGrafikuWstep;
    UIDodawanieNowegoGrafiku* uiDodawanieNowegoGrafiku;
    MNoweGrafiki* mNoweGrafiki;
    MDyzuranci* mDyzuranci;
    std::vector<XDyzurant*>* tablicaDyzurantow;
    int decyzjaWarunkowPoczatkowychGrafiku;

    UITworzoneGrafiki* uiTworzoneGrafiki;   //debug only
};

#endif // PDODAWANIENOWEGOGRAFIKU_H
