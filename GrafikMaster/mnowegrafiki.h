
#ifndef MNOWEGRAFIKI_H
#define MNOWEGRAFIKI_H

#include <vector>
#include <string>
#include <QSemaphore>

enum Miesiac : int;
enum DzienTygodnia : int;
class XGrafik;
class XDyzurantTworzacy;
class XDyzurant;
class DBObslugiwaczBazyDanych;
class PProgress;
class TWorker;
class QThread;

class MNoweGrafiki {
public:
    MNoweGrafiki();
    ~MNoweGrafiki();
    void wyciagnijTabliceMiesiecyIDniTygodnia(std::vector<Miesiac>& tabM, std::vector<DzienTygodnia>& tabDT);
    XGrafik* utworzNowyGrafik(int r, int ld, Miesiac m, DzienTygodnia dt, QString listaSwiat, bool& result);
    std::string utworzDyzurantaTworzacego(XDyzurant* dyzurant);
    void usunDyzurantaTworzacego(std::string nick);
    XDyzurantTworzacy* pobierzDaneDyzurantaTworzacego(std::string nick);
    bool updateDyzurantaTworzacego(std::string nick, bool czyM, std::string m, std::string nm, std::string u,
                                   std::string ch, int maks, int min, int maksS,
                                   int maksN, int maksW, int c, int maksP,
                                   int wyborT, int msbn, int mwzp);
    bool zapiszUstawieniaDoPliku();
    std::vector<std::string> wczytajUstawienia(std::vector<XDyzurant*>* tablicaDyzurantow);
    XGrafik* wypelnijGrafikPierwszymiDanymi();

    void wypelnijGrafikDyzurantami(bool& immediateResult, int ileIteracji, int szybkosc, bool skracaniePomimoUlozenia);

    bool usunWszystkieUstawieniaZPlikow();
    bool zapiszParametryGrafiku(std::vector<QString> daneDoZapisu);
    std::vector<QString> wczytajParametryGrafiku(bool& result):
private:
    std::vector<Miesiac> tablicaMiesiecy;
    std::vector<DzienTygodnia> tablicaDniTygodnia;
    XGrafik* nowyGrafik;
    std::vector<XDyzurantTworzacy*>* tablicaDyzurantowTworzacych;
    DBObslugiwaczBazyDanych* db;
    PProgress* progressManager;

    TWorker* tWorker;
    QThread* thread;
    QSemaphore* semafor,* semafor2,* semaforLabel;

    void wypelnijTabliceEnumeracyjne();
    void wypelnijDzien(int dzien);
    bool sprawdzWstepnieZgodnosc();
    std::vector<int> convertStringToVectorOfInts(std::string s, bool& result);
};

#endif // MNOWEGRAFIKI_H
