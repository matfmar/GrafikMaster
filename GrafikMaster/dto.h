
#ifndef DTO_H
#define DTO_H

#include <string>
#include <vector>
#include <map>

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
    void setNick(std::string s);
    void setPriorytet(int a);
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
    XDyzurantTworzacy(int a, std::string s, int b, int c, int d, int e, int sb, int nd, int wk, bool wgm);
    XDyzurantTworzacy(XDyzurant* d);
    ~XDyzurantTworzacy() {}
    std::string getKiedyChce();
    std::string getKiedyNieMoze();
    std::string getKiedyMoze();
    std::string getKiedyUnika();
    std::vector<int> getKiedyChce2();
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
    void setWpisywanieCzyMoze(bool b);
    void incLiczbaDyzurow(DzienTygodnia dt);
    void decLiczbaDyzurow(DzienTygodnia dt);
    bool sprawdzCzyMozeDanegoDnia(int dzien);
    bool sprawdzCzyChceDanegoDnia(int dzien);
    void usunDyzur(int dzien);
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
    bool wpisywanieGdzieMoze;

    int liczbaDyzurow;
    int liczbaSobot;
    int liczbaNiedziel;
    int liczbaWeekendow;
    std::vector<int> dyzury;

    std::vector<int> convertStringToVectorOfInts(std::string s, bool& result);
};

//XDzien
struct XDzien {
    XDzien();
    XDzien(DzienTygodnia dt, int ld, bool czs, StatusDnia sd, XDyzurantTworzacy* dw);
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
    XGrafik(int r, Miesiac m, StatusGrafiku st, int ld, DzienTygodnia pd);
    void stworzPodstawyGrafiku();
    void dodajPierwszeDaneDyzurantaMozeUnika(XDyzurantTworzacy* dyzurant);
    void dodajPierwszeDaneDyzurantowKiedyChca(std::vector<XDyzurantTworzacy*>* tablicaDyzurantowTworzacych);
    void przeliczMozliwiNieUnikajacyDyzuranciDlaKazdegoDnia();
    void przeliczMozliwiNieUnikajacyDyzuranciDlaJednegoDnia(int dzien);
    std::vector<XDzien*> udostepnijTabliceDni();
    ~XGrafik();
private:
    int rok;
    Miesiac miesiac;
    StatusGrafiku status;
    int liczbaDni;
    DzienTygodnia pierwszyDzien;
    std::vector<XDzien*> tablicaDni;    //numerowane od 1 do liczbaDni+1;
};

//GENERAL
DzienTygodnia incDzien(DzienTygodnia dt);

#endif // DTO_H
