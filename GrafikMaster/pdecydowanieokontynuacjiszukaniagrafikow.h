
#ifndef PDECYDOWANIEOKONTYNUACJISZUKANIAGRAFIKOW_H
#define PDECYDOWANIEOKONTYNUACJISZUKANIAGRAFIKOW_H


class UIDecydowanieOKoniecznosciSzukaniaGrafikow;
class PPrzegladanieGrafikowRoboczych;

class PDecydowanieOKontynuacjiSzukaniaGrafikow {
public:
    PDecydowanieOKontynuacjiSzukaniaGrafikow();
    ~PDecydowanieOKontynuacjiSzukaniaGrafikow();
    int pokazOknoWyboruOpcji(); //zwraca decyzję użytkownika (1-kontynuacja, 2-stop)
    void pokazKomunikatZakonczeniaSzukania(bool result, int ileGrafikow);
    void setDecyzjaUzytkownika(int d);
    void przegladajGrafiki();
private:
    UIDecydowanieOKoniecznosciSzukaniaGrafikow* uiDecydowanieOKoniecznosciSzukaniaGrafikow;
    int decyzjaUzytkownika; //1-szukamy dalej, 2-koniec szukania
    PPrzegladanieGrafikowRoboczych* pPrzegladanieGrafikowRoboczych;

};

#endif // PDECYDOWANIEOKONTYNUACJISZUKANIAGRAFIKOW_H
