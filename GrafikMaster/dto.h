
#ifndef DTO_H
#define DTO_H

#include <string>
#include <vector>
#include <map>
#include <QMutex>
#include <QString>

class DBObslugiwaczBazyDanych;
class TWorker;

//(enum)DzienTygodnia
enum DzienTygodnia : int {
    NIEZNANY_DZIEN = 0,
    PONIEDZIALEK = 1,
    WTOREK = 2,
    SRODA = 3,
    CZWARTEK = 4,
    PIATEK = 5,
    SOBOTA = 6,
    NIEDZIELA = 7
};

//(enum)Miesiac
enum Miesiac : int {
    NIEZNANY_MIESIAC = 0,
    STYCZEN = 1,
    LUTY = 2,
    MARZEC = 3,
    KWIECIEN = 4,
    MAJ = 5,
    CZERWIEC = 6,
    LIPIEC = 7,
    SIERPIEN = 8,
    WRZESIEN = 9,
    PAZDZIERNIK = 10,
    LISTOPAD = 11,
    GRUDZIEN = 12
};

//(enum)StatusGrafiku
enum StatusGrafiku : int {
    NIEZNANY_STATUS_GRAFIKU = 0,
    ROBOCZY = 1,
    KLEPNIETY = 2
};

//(enum)StatusDnia
enum StatusDnia : int {
    NIEZNANY_STATUS = 0,
    NIEUSTAWIONY_W_TRAKCIE = 1,
    USTAWIONY_WSTEPNIE = 2,
    NIEUSTAWIONY_NIE_DO_USTAWIENIA = 3,
    USTAWIONY_NIE_DO_RUSZENIA = 4
};

//XDyzurant
class XDyzurant {
public:
    XDyzurant();
    XDyzurant(int a, std::string s, int b);
    XDyzurant(XDyzurant* d);
    std::string getNick();
    int getPriorytet();
    int getId();
    //void setNick(std::string s);
    //void setPriorytet(int a);
    virtual ~XDyzurant() {}
protected:
    int id;
    std::string nick;
    int priorytet;
};

//XDyzurantTworzacy
class XDyzurantTworzacy : public XDyzurant {
public:
    XDyzurantTworzacy();
    XDyzurantTworzacy(int a, std::string s, int b, int c, int d, int e, int sb, int nd, int wk, bool wgm, int mp, int ut, int msbn, int mwzp);
    XDyzurantTworzacy(XDyzurant* d);
    ~XDyzurantTworzacy();

    class XLiczniki {
    public:
        XLiczniki(XDyzurantTworzacy* p);
        XLiczniki(XLiczniki* l);    //copy constructor
        XDyzurantTworzacy* parent;

        int liczbaDyzurow;
        int liczbaSobot;
        int liczbaNiedziel;
        int liczbaWeekendow;
        int liczbaPiatkow;
        int liczbaWeekendowZPiatkami;
        int liczbaSwiatBezNiedziel;
        std::vector<int> dyzury;

        void incLiczbaDyzurow(DzienTygodnia dt, bool czySwieto);
        void decLiczbaDyzurow(DzienTygodnia dt, bool czySwieto);
        void usunDyzur(int dzien);
        void usunDyzurPrzedPopBack();
        void dodajDyzur(int dzien);
        void sortujDyzury();
        std::vector<int> znajdzSekwencje(int krotnosc);
        std::vector<int> zwrocDyzury();
        bool sprawdzZgodnoscMaksymalnejLiczbyDyzurow();    //wylacznie maksymalna liczba
        //bool sprawdzZgodnoscMinimalnejLiczbyDyzurow();
        bool sprawdzZgodnoscLiczbySobotINiedzielIWeekendow();
        bool sprawdzZgodnoscLiczbyPiatkow();
        bool sprawdzZgodnoscLiczbySwiatBezNiedzielIWeekendowZPiatkami();
        int zwrocIleDyzurowBrakuje();
    };
    XLiczniki* liczniki;

    std::string getKiedyChce();
    std::string getKiedyNieMoze();
    std::string getKiedyMoze();
    std::string getKiedyUnika();
    //std::vector<int> getKiedyChce2();
    std::vector<int> getKiedyMoze2();
    std::vector<int> getKiedyNieMoze2();
    std::vector<int> getKiedyUnika2();
    bool getCzyWpisywanieGdzieMoze();
    int getMaksymalnie();
    int getMinimalnie();
    int getUnikaniePodRzad();
    int getMaksymelnieSoboty();
    int getMaksymalnieNiedziele();
    int getMaksymalnieWeekendy();
    int getMaksymalniePiatki();
    int getMaksymalnieWeekendyZPiatkami();
    int getMaksymalnieSwietaBezNiedziel();
    int getUnikanieTrojek();
    void setKiedyChce(std::string s, bool& result);
    void setKiedyNieMoze(std::string s, bool& result);
    void setKiedyMoze(std::string s, bool& result);
    void setKiedyUnika(std::string s, bool& result);
    void setMaksymalnie(int a);
    void setMinimalnie(int a);
    void setUnikaniePodRzad(int a);
    void setMaksymalnieSoboty(int a);
    void setMaksymalnieNiedziele(int a);
    void setMaksymalnieWeekendy(int a);
    void setMaksymalniePiatki(int a);
    void setMaksymalnieSwietaBezNiedziel(int a);
    void setMaksymalnieWeekendyZPiatkami(int a);
    void setUnikanieTrojek(int a);
    void setWpisywanieCzyMoze(bool b);
    void incLiczbaDyzurow(DzienTygodnia dt);
    //void decLiczbaDyzurow(DzienTygodnia dt);
    //bool sprawdzCzyMozeDanegoDnia(int dzien);
    bool sprawdzCzyChceDanegoDnia(int dzien);
    //void usunDyzur(int dzien);
    //void usunDyzurPrzedPopBack();
    void dodajDyzur(int dzien);
    void sortujDyzury();

    std::vector<int> znajdzSekwencje(int krotnosc);
private:
    std::vector<int> kiedyChce;
    std::vector<int> kiedyNieMoze;
    std::vector<int> kiedyMoze;
    std::vector<int> kiedyUnika;
    int maksymalnie;
    int minimalnie;
    int unikaniePodRzad;
    int maksymalnieSoboty;
    int maksymalnieNiedziele;
    int maksymalnieWeekendy;
    int maksymalniePiatki;
    int maksymalnieWeekendyZPiatkami;
    int maksymalnieSwietaBezNiedziel;
    int unikanieTrojek;
    bool wpisywanieGdzieMoze;



    std::vector<int> convertStringToVectorOfInts(std::string s, bool& result);
};

//XDzien
struct XDzien {
    XDzien();
    XDzien(DzienTygodnia dt, int ld, bool czs, StatusDnia sd, XDyzurantTworzacy* dw);
    XDzien(XDzien& xd);
    XDzien(XDzien* xd);
    ~XDzien() {}
    DzienTygodnia dzienTygodnia;
    int liczbaDnia;
    bool czySwieto;
    StatusDnia statusUstawiania;
    std::map<int, XDyzurantTworzacy*> mozliwiDyzuranci;
    std::map<int, XDyzurantTworzacy*> unikajacyDyzuranci;
    std::map<int, XDyzurantTworzacy*> mozliwiNieUnikajacyDyzuranci;
    XDyzurantTworzacy* dyzurantWybrany;

    void przeliczMozliwiNieUnikajacyDyzuranci();
};


//XGrafik
class XGrafik {
public:
    XGrafik();
    XGrafik(int r, Miesiac m, StatusGrafiku st, int ld, DzienTygodnia pd, std::vector<int> swieta);
    XGrafik(XGrafik& gr);
    XGrafik(XGrafik* gr);
    void stworzPodstawyGrafiku();
    void dodajPierwszeDaneDyzurantaMozeUnika(XDyzurantTworzacy* dyzurant);
    void dodajPierwszeDaneDyzurantowKiedyChca(std::vector<XDyzurantTworzacy*>* tablicaDyzurantowTworzacych);
    void przeliczMozliwiNieUnikajacyDyzuranciDlaKazdegoDnia();
    //void przeliczMozliwiNieUnikajacyDyzuranciDlaJednegoDnia(int dzien);
    void wypelnijGrafikDyzurantami(std::vector<XDyzurantTworzacy*>* tdt, int ileIteracji, TWorker* pw, bool czyP, bool* decS, int* licS, QMutex* mut, bool spu, QMutex* mwz, bool* wz);
    std::vector<XDzien*> udostepnijTabliceDni();
    std::string getMiesiacRok();

    bool losujDyzurantaDoDyzuruPoKluczu(int dzien, int& kluczWybranegoDyzuranta);

    bool wypelnijDzien(int dzien);  //niestety ta funkcja rekurencyjna chyba musi byc publiczna

    ~XGrafik();
private:
    int rok;
    Miesiac miesiac;
    StatusGrafiku status;
    int liczbaDni;
    DzienTygodnia pierwszyDzien;
    std::vector<int> listaSwiat;
    std::vector<XDzien*> tablicaDni;    //numerowane od 1 do liczbaDni+1;
    DBObslugiwaczBazyDanych* db;        //do zapisywania wypelnionych w calosci grafikow
    TWorker* parentWorker;      //do wysyłania syngałów międzywątkowych

    std::vector<XDyzurantTworzacy*>* tablicaDyzurantowTworzacych;
    std::map<int, XDyzurantTworzacy::XLiczniki*> mapaLicznikowDyzurantow;   //szeregowane po kluczach odpowiednich dyżurantów tworzących

    //zmienne sterujące pętlą oraz do komunikacji z TWorker
    int* licznikStworzonychGrafikow;    //wskaźnik do "globalnej" zmiennej zawierającej ilość stworzonych grafików
    bool* zakonczenieSzukania;          //wskaźnik do "globalnej" zmiennej zawierającej decyzję o sposobie wychodzenia z pętli (true -> kończymy, false -> szukamy dalej)
    int* licznikOstatecznyStworzonychGrafikow;
    int* liczbaIteracji;
    QMutex* mutexWymuszenieZakonczenia;
    bool* wymuszenieZakonczenia;

    //zmienne w razie działania z przyspieszczem
    bool czyPrzyspieszenie;
    bool* decyzjaOSkroceniu;
    int* licznikSkrocen;
    bool skracaniePomimoUlozenia;
    QMutex* mutex;

    void dodajUnikanie(XDyzurantTworzacy::XLiczniki* licznikDt, XDyzurantTworzacy* dt, int klucz, int unikanieKrotnosc, bool& result, int dzien);
    void dodajUnikanieTrojek(XDyzurantTworzacy::XLiczniki* licznikDt, XDyzurantTworzacy* dt, int klucz, bool& result, int dzien);
    //bool sprawdzPustoscZbioruMozliwiNieUnikajacy(int dzien);
    bool sprawdzZgodnoscZMinimalnaLiczbaDyzurowDlaWszystkich();
    bool sprawdzCzySwieto(int dzien, DzienTygodnia dt);
    bool sprawdzCzyJestSzansaWepchnieciaDyzurantaOkreslonaLiczbeRazy(int odKiedy, int ileJeszczeTrzeba, int id);
};

//XWyswietlanyGrafik

struct XWyswietlanyGrafik {
    XWyswietlanyGrafik(std::string np, int m, int r);
    ~XWyswietlanyGrafik();
    struct XPozycjaGrafiku {
        XPozycjaGrafiku(QString dz, QString dt, QString dy, bool cS);
        QString dzien;
        QString dzienTygodnia;
        QString dyzurant;
        bool czySwieto;
    };
    std::string nazwaPliku;
    int miesiac;
    int rok;
    std::vector<XPozycjaGrafiku*>* listaPozycjiGrafiku;
};

//GENERAL
DzienTygodnia incDzien(DzienTygodnia dt);
std::string przeliczDzienTygodniaNaLancuch(DzienTygodnia dt);
std::string przeliczMiesiacNaLiczbe(Miesiac m);

#endif // DTO_H
