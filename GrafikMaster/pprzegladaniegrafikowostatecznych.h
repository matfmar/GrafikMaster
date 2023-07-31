
#ifndef PPRZEGLADANIEGRAFIKOWOSTATECZNYCH_H
#define PPRZEGLADANIEGRAFIKOWOSTATECZNYCH_H

#include <vector>
#include <string>
#include <QString>

class UIPrzegladanieGrafikowOstatecznych;
class XWyswietlanyGrafik;
class DBObslugiwaczBazyDanych;

class PPrzegladanieGrafikowOstatecznych {
public:
    PPrzegladanieGrafikowOstatecznych();
    ~PPrzegladanieGrafikowOstatecznych();
    void pokazOknoPrzegladaniaGrafikow();
    int wybranoSzukanieGrafikow(int miesiac, int rok);
    //void wybranoZamkniecie();
    bool wybranoUsuniecieGrafiku();
    bool zapiszJakoPDF(QString f);
private:
    UIPrzegladanieGrafikowOstatecznych* uiPrzegladanieGrafikowOstatecznych;
    XWyswietlanyGrafik* aktualnyGrafik;
    DBObslugiwaczBazyDanych* db;

    QString odczytajMiesiac(int m);
    void usunWyswietlanyGrafik();
};

#endif // PPRZEGLADANIEGRAFIKOWOSTATECZNYCH_H
