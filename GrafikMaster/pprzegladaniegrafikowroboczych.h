
#ifndef PPRZEGLADANIEGRAFIKOWROBOCZYCH_H
#define PPRZEGLADANIEGRAFIKOWROBOCZYCH_H

#include <vector>
#include <string>
#include <QString>

class UIPrzegladanieGrafikowRoboczych;
class XWyswietlanyGrafik;
class DBObslugiwaczBazyDanych;

class PPrzegladanieGrafikowRoboczych
{
public:
    PPrzegladanieGrafikowRoboczych();
    ~PPrzegladanieGrafikowRoboczych();
    void pokazOknoPrzegladaniaGrafikow();
    int wybranoSzukanieGrafikow(int miesiac, int rok);
    XWyswietlanyGrafik* wybranoGrafikWLewo(int& ktory, int& ileWszystkich);
    XWyswietlanyGrafik* wybranoGrafikWPrawo(int& ktory, int& ileWszystkich);
    //void wybranoZamkniecie();
    bool wybranoUsuniecieGrafiku(bool& czyCosZostaje);
    bool wybranoUsuniecieWszystkichGrafikow();
    bool wybranoKlepniecieGrafiku();
    bool zapiszJakoPDF(QString f);
private:
    UIPrzegladanieGrafikowRoboczych* uiPrzegladanieGrafikowRoboczych;
    std::vector<XWyswietlanyGrafik*>* aktualnaListaGrafikow;//materiał do sortowania
    int ileGrafikowNaLiscie;
    int ktoryWyswietlamy;
    DBObslugiwaczBazyDanych* db;
    std::vector<std::string> listaNazwPlikow;

    void wyczyscAktualnaListeGrafikow();
    QString odczytajMiesiac(int m);
};

#endif // PPRZEGLADANIEGRAFIKOWROBOCZYCH_H
