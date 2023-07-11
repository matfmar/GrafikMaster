
#ifndef UIDECYDOWANIEOKONIECZNOSCISZUKANIAGRAFIKOW_H
#define UIDECYDOWANIEOKONIECZNOSCISZUKANIAGRAFIKOW_H


#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>

class PDecydowanieOKontynuacjiSzukaniaGrafikow;

class UIDecydowanieOKoniecznosciSzukaniaGrafikow : public QDialog {
    Q_OBJECT
public:
    UIDecydowanieOKoniecznosciSzukaniaGrafikow(PDecydowanieOKontynuacjiSzukaniaGrafikow* p);
    ~UIDecydowanieOKoniecznosciSzukaniaGrafikow() {}
    void wyswietlKomunikatZakonczeniaSzukania(bool result);
public slots:
    void onButtonSzukajDalejClicked();
    void onButtonZakonczSzukanieClicked();
    void onButtonWyswietlGrafikiClicked();
private:
    QPushButton* buttonSzukajDalej,* buttonZakonczSzukanie,* buttonWyswietlGrafiki;
    QVBoxLayout* mainLayout;
    PDecydowanieOKontynuacjiSzukaniaGrafikow* parent;

};

#endif // UIDECYDOWANIEOKONIECZNOSCISZUKANIAGRAFIKOW_H
