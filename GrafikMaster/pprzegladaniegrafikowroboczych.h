
#ifndef PPRZEGLADANIEGRAFIKOWROBOCZYCH_H
#define PPRZEGLADANIEGRAFIKOWROBOCZYCH_H


class UIPrzegladanieGrafikowRoboczych;
class XWyswietlanyGrafik;
class DBObslugiwaczBazyDanych;

class PPrzegladanieGrafikowRoboczych
{
public:
    PPrzegladanieGrafikowRoboczych();
    ~PPrzegladanieGrafikowRoboczych();
    int wybranoSzukanieGrafikow(int miesiac, int rok);
    void wybranoGrafikWLewo();
    XWyswietlanyGrafik* wybranoGrafikWPrawo(int& ktory, int& ileWszystkich);
    void wybranoZamkniecie();
    bool wybranoUsuniecieGrafiku(bool& czyCosZostaje);
private:
    UIPrzegladanieGrafikowRoboczych* uiPrzegladanieGrafikowRoboczych;
    std::vector<XWyswietlanyGrafik*>* aktualnaListaGrafikow;
    int ileGrafikowNaLiscie;
    int ktoryWyswietlamy;
    DBObslugiwaczBazyDanych* db;

    void wyczyscAktualnaListeGrafikow();
};

#endif // PPRZEGLADANIEGRAFIKOWROBOCZYCH_H
