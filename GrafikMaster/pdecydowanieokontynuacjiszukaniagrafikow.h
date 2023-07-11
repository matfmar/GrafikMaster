
#ifndef PDECYDOWANIEOKONTYNUACJISZUKANIAGRAFIKOW_H
#define PDECYDOWANIEOKONTYNUACJISZUKANIAGRAFIKOW_H


class UIDecydowanieOKoniecznosciSzukaniaGrafikow;

class PDecydowanieOKontynuacjiSzukaniaGrafikow {
public:
    PDecydowanieOKontynuacjiSzukaniaGrafikow();
    ~PDecydowanieOKontynuacjiSzukaniaGrafikow();
    int pokazOknoWyboruOpcji(); //zwraca decyzję użytkownika (1-kontynuacja, 2-stop)
    void pokazKomunikatZakonczeniaSzukania(bool result);
    void setDecyzjaUzytkownika(int d);
private:
    UIDecydowanieOKoniecznosciSzukaniaGrafikow* uiDecydowanieOKoniecznosciSzukaniaGrafikow;
    int decyzjaUzytkownika; //1-szukamy dalej, 2-koniec szukania

};

#endif // PDECYDOWANIEOKONTYNUACJISZUKANIAGRAFIKOW_H
