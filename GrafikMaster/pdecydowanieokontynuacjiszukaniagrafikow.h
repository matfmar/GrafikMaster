
#ifndef PDECYDOWANIEOKONTYNUACJISZUKANIAGRAFIKOW_H
#define PDECYDOWANIEOKONTYNUACJISZUKANIAGRAFIKOW_H


class UIDecydowanieOKoniecznosciSzukaniaGrafikow;

class PDecydowanieOKontynuacjiSzukaniaGrafikow {
public:
    PDecydowanieOKontynuacjiSzukaniaGrafikow();
    ~PDecydowanieOKontynuacjiSzukaniaGrafikow();
    void pokazOknoWyboruOpcji();
    void pokazKomunikatZakonczeniaSzukania();
private:
    UIDecydowanieOKoniecznosciSzukaniaGrafikow* uiDecydowanieOKoniecznosciSzukaniaGrafikow;

};

#endif // PDECYDOWANIEOKONTYNUACJISZUKANIAGRAFIKOW_H
