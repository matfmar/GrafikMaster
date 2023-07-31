
#ifndef UIDODAWANIENOWEGOGRAFIKU_H
#define UIDODAWANIENOWEGOGRAFIKU_H


#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QCheckBox>
#include <vector>

class XDyzurant;
class PDodawanieNowegoGrafiku;

class UIDodawanieNowegoGrafiku : public QMainWindow {
    Q_OBJECT
public:
    UIDodawanieNowegoGrafiku(std::vector<XDyzurant*>* td, PDodawanieNowegoGrafiku* pd, QWidget *parent = nullptr);
    ~UIDodawanieNowegoGrafiku() {}
public slots:
    void onButtonUpdateClicked();
    void onButtonStartClicked();
    void onListaDyzurantowTworzacychClicked(QListWidgetItem* item);
    void onListaDyzurantowDostepnychClicked(QListWidgetItem* item);
    void onButtonWPrawoClicked();
    void onButtonWLewoClicked();
    void onWyborMozeClicked();
    void onWyborNieMozeClicked();
    void onButtonZapiszUstawieniaClicked();
    void onButtonWczytajUstawieniaClicked();
    void onButtonUsunWszystkieUstawieniaClicked();
private:
    QWidget* mainWidget;
    QListWidget* listaDyzurantowDostepnych,* listaDyzurantowTworzacych;
    QLabel* labelDyzuranciDostepni,* labelDyzuranciTworzacy;
    QPushButton* buttonWPrawo,* buttonWLewo;
    QLabel* labelChce,* labelNieMoze,* labelMoze,* labelUnika,* labelMaks,* labelMin,* labelPodRzad;
    QLabel* labelMaksSoboty,* labelMaksNiedziele,* labelMaksWeekendy,* labelMaksPiatki,* labelIleIteracji;
    QLabel* labelMaksWeekendyZPiatkami,* labelMaksSwietaBezNiedziel;
    QLineEdit* editChce,* editNieMoze,* editMoze,* editUnika,* editMaks,* editMin,* editIleIteracji;
    QLineEdit* editMaksSoboty,* editMaksNiedziele,* editMaksWeekendy,* editMaksPiatki;
    QLineEdit* editMaksWeekendyZPiatkami,* editMaksSwietaBezNiedziel;
    QCheckBox* wyborBezTrojek,* wyborSkracajNiezaleznieOdUlozenia;
    QPushButton* buttonUpdate,* buttonStart;
    QPushButton* buttonZapiszUstawienia;
    QPushButton* buttonWczytajUstawienia;
    QPushButton* buttonUsunZapisaneUstawienia;
    QRadioButton* wyborMoze,* wyborNieMoze;
    QRadioButton* wyborDwa,* wyborTrzy,* wyborCztery,* wyborNic;
    QRadioButton* wyborNormalnie,* wyborSzybko,* wyborBardzoSzybko,* wyborEkstremanlnieSzybko;
    QVBoxLayout* layoutButtonsPrawoLewo,* layoutListLeft,* layoutListRight,* layoutPrzyciski;
    QHBoxLayout* layoutListWidgetsButtons,* layoutRightLabelEdit;
    QGroupBox* groupMozeNieMoze,* groupPodRzad,* groupZapisywanieWczytywanie,* groupSzybkosc;
    QButtonGroup* groupRadioMozeNieMoze,* groupRadioPodRzad,* groupRadioSzybkosc;
    QGridLayout* layoutLabelsEdits,* layoutRadioGroup;
    QVBoxLayout* layoutPodRzad,* layoutZapisywanieWczytywanie,* layoutRight,* layoutSzybkosc;
    QVBoxLayout* mainLayout;
    QHBoxLayout* ultimateLayout;
    PDodawanieNowegoGrafiku* pDodawanieNowegoGrafiku;

    void wypelnijListeDyzurantami(std::vector<XDyzurant*>* tab);
};

#endif // UIDODAWANIENOWEGOGRAFIKU_H
