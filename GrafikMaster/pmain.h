
#ifndef PMAIN_H
#define PMAIN_H

class UIMainWindow;
class PEdycjaBazyDyzurantow;

class PMain {
public:
    PMain();
    ~PMain();

    void wybranoEdycjeBazyDyzurantow();
    void wybranoDodanieNowegoGrafiku();
    void wybranoPrzegladanieGrafikowRoboczych();
    void wybranoPrzegladanieGrafikowOstatecznych();
private:
    UIMainWindow* uiMainWindow;
    PEdycjaBazyDyzurantow* pEdycjaBazyDyzurantow;
};

#endif // PMAIN_H
