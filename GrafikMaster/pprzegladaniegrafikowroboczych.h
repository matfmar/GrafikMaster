
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
    void wybranoSzukanieGrafikow(int miesiac, int rok);
    void wybranoGrafikWLewo();
    void wybranoGrafikWPrawo();
    void wybranoZamkniecie();
private:
    UIPrzegladanieGrafikowRoboczych* uiPrzegladanieGrafikowRoboczych;
    std::vector<XWyswietlanyGrafik*>* aktualnaListaGrafikow;
    DBObslugiwaczBazyDanych* db;
};

#endif // PPRZEGLADANIEGRAFIKOWROBOCZYCH_H
