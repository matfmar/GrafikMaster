
#ifndef UIDECYDOWANIEOKONIECZNOSCISZUKANIAGRAFIKOW_H
#define UIDECYDOWANIEOKONIECZNOSCISZUKANIAGRAFIKOW_H


#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class PDecydowanieOKontynuacjiSzukaniaGrafikow;

class UIDecydowanieOKoniecznosciSzukaniaGrafikow : public QDialog {
    Q_OBJECT
public:
    UIDecydowanieOKoniecznosciSzukaniaGrafikow(PDecydowanieOKontynuacjiSzukaniaGrafikow* p);
    ~UIDecydowanieOKoniecznosciSzukaniaGrafikow();
    void wyswietlKomunikatZakonczeniaSzukania(bool result, int ileGrafikow);
    void setLabel(int ileGrafikow);
public slots:
    void onButtonSzukajDalejClicked();
    void onButtonZakonczSzukanieClicked();
private:
    QPushButton* buttonSzukajDalej,* buttonZakonczSzukanie;
    QLabel* label;
    QVBoxLayout* mainLayout;
    PDecydowanieOKontynuacjiSzukaniaGrafikow* parent;
    const QString labelText = tr("Liczba już znalezionych grafików: ");

};

#endif // UIDECYDOWANIEOKONIECZNOSCISZUKANIAGRAFIKOW_H
