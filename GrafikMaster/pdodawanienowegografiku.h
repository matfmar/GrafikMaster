
#ifndef PDODAWANIENOWEGOGRAFIKU_H
#define PDODAWANIENOWEGOGRAFIKU_H

#include <vector>
#include <QString>
#include <string>

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
    void wybranoDodanieInformacjiWstepnychNowegoGrafiku(int r, int ld, Miesiac m, DzienTygodnia dt, QString listaSwiat, bool& result);
    QString wybranoDodanieDyzurantaTworzacego(QString nick);
    void wybranoUsuniecieDyzurantaTworzacego(QString nick);
    XDyzurantTworzacy* wybranoPobranieDanychDyzurantaTworzacego(QString nick);
    bool wybranoUpdateDyzurantaTworzacego(QString nick, bool czyM, QString m, QString nm, QString u,
                                          QString ch, int maks, int min, int maksS, int maksN,
                                          int maksW, int c, int maksP, int wyborT, int msbn, int mwzp);

    void wybranoProsbeOStworzenieGrafiku(bool& decisionResult, bool& immediateResult, int ileIteracji, int szybkosc, bool skracaniePomimoUlozenia);

    void wybranoDecyzjeWarunkowPoczatkowychGrafiku(int decyzja);
    bool wybranoZapisanieUstawienDoPliku();
    std::vector<std::string> wybranoWczytanieUstawien();
    bool wybranoUsunWszystkieUstawienia();
    bool wybranoZapisanieParametrowGrafiku(std::vector<QString> daneDoZapisu);    
    std::vector<QString> wybranoWczytanieParametrowGrafiku(bool& result);
private:
    UIDodawanieNowegoGrafikuWstep* uiDodawanieNowegoGrafikuWstep;
    UIDodawanieNowegoGrafiku* uiDodawanieNowegoGrafiku;
    MNoweGrafiki* mNoweGrafiki;
    MDyzuranci* mDyzuranci;
    std::vector<XDyzurant*>* tablicaDyzurantow;
    int decyzjaWarunkowPoczatkowychGrafiku;

    UITworzoneGrafiki* uiTworzoneGrafiki;
};

#endif // PDODAWANIENOWEGOGRAFIKU_H
