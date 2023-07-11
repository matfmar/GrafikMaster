
#ifndef UIDECYDOWANIEOKONIECZNOSCISZUKANIAGRAFIKOW_H
#define UIDECYDOWANIEOKONIECZNOSCISZUKANIAGRAFIKOW_H


#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>


class UIDecydowanieOKoniecznosciSzukaniaGrafikow : public QDialog {
    Q_OBJECT
public:
    UIDecydowanieOKoniecznosciSzukaniaGrafikow();
    ~UIDecydowanieOKoniecznosciSzukaniaGrafikow() {}
    void wyswietlKomunikatZakonczeniaSzukania();
public slots:
    void onButtonSzukajDalejClicked();
    void onButtonZakonczSzukanieClicked();
    void onButtonWyswietlGrafikiClicked();
private:
    QPushButton* buttonSzukajDalej,* buttonZakonczSzukanie,* buttonWyswietlGrafiki;
    QVBoxLayout* mainLayout;

};

#endif // UIDECYDOWANIEOKONIECZNOSCISZUKANIAGRAFIKOW_H
