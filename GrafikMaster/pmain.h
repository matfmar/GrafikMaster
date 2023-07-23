
#ifndef PMAIN_H
#define PMAIN_H

class UIMainWindow;
class PEdycjaBazyDyzurantow;
class PDodawanieNowegoGrafiku;
class PPrzegladanieGrafikowRoboczych;

class PMain {
public:
    PMain();
    ~PMain();

    void wybranoEdycjeBazyDyzurantow();
    void wybranoDodanieNowegoGrafiku();
    void wybranoPrzegladanieGrafikowRoboczych();
    void wybranoPrzegladanieGrafikowOstatecznych();
    void wybranoZakonczenieTworzeniaGrafikow();
private:
    UIMainWindow* uiMainWindow;
    PEdycjaBazyDyzurantow* pEdycjaBazyDyzurantow;
    PDodawanieNowegoGrafiku* pDodawanieNowegoGrafiku;
    PPrzegladanieGrafikowRoboczych* pPrzegladanieGrafikowRoboczych;
};

#endif // PMAIN_H
