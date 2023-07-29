
#ifndef PMAIN_H
#define PMAIN_H

class UIMainWindow;
class PEdycjaBazyDyzurantow;
class PDodawanieNowegoGrafiku;
class PPrzegladanieGrafikowRoboczych;
class PPrzegladanieGrafikowOstatecznych;

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
    PPrzegladanieGrafikowOstatecznych* pPrzegladanieGrafikowOstatecznych;
};

#endif // PMAIN_H
