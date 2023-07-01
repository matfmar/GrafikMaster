
#ifndef DTO_H
#define DTO_H

#include <string>
#include <vector>
#include <map>

//(enum)DzienTygodnia
enum DzienTygodnia {
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
enum Miesiac {
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
enum StatusGrafiku {
    NIEZNANY_STATUS_GRAFIKU = 0,
    ROBOCZY = 1,
    KLEPNIETY = 2
};

//(enum)StatusDnia
enum StatusDnia {
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
    std::string getNick();
    int getPriorytet();
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
    XDyzurantTworzacy(int a, std::string s, int b, int c, int d, int e);
    ~XDyzurantTworzacy() {}
private:
    std::vector<int> kiedyChce;
    std::vector<int> kiedyNieMoze;
    std::vector<int> kiedyMoze;
    std::vector<int> kiedyUnika;
    int maksymalnie;
    int minimalnie;
    int unikaniePodRzad;
};

//XDzien
class XDzien {
public:
    XDzien();
    XDzien(DzienTygodnia dt, int ld, bool czs, StatusDnia sd, XDyzurantTworzacy* dw);
    ~XDzien() {}
private:
    DzienTygodnia dzienTygodnia;
    int liczbaDnia;
    bool czySwieto;
    StatusDnia statusUstawiania;
    std::map<int, XDyzurantTworzacy*> mozliwiDyzuranci;
    std::map<int, XDyzurantTworzacy*> unikajacyDyzuranci;
    XDyzurantTworzacy* dyzurantWybrany;
};


//XGrafik
class XGrafik {
public:
    XGrafik();
    XGrafik(int r, Miesiac m, StatusGrafiku st, int ld, DzienTygodnia pd);
    ~XGrafik() {}
private:
    int rok;
    Miesiac miesiac;
    StatusGrafiku status;
    int liczbaDni;
    DzienTygodnia pierwszyDzien;
    std::vector<XDzien*> tablicaDni;
};

#endif // DTO_H
