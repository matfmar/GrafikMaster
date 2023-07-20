
#ifndef PMAIN_H
#define PMAIN_H

class UIMainWindow;
class PEdycjaBazyDyzurantow;
class PDodawanieNowegoGrafiku;

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
};

#endif // PMAIN_H
