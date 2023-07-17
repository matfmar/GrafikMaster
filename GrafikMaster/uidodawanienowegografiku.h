
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
private:
    QWidget* mainWidget;
    QListWidget* listaDyzurantowDostepnych,* listaDyzurantowTworzacych;
    QLabel* labelDyzuranciDostepni,* labelDyzuranciTworzacy;
    QPushButton* buttonWPrawo,* buttonWLewo;
    QLabel* labelChce,* labelNieMoze,* labelMoze,* labelUnika,* labelMaks,* labelMin,* labelPodRzad;
    QLabel* labelMaksSoboty,* labelMaksNiedziele,* labelMaksWeekendy;
    QLineEdit* editChce,* editNieMoze,* editMoze,* editUnika,* editMaks,* editMin;
    QLineEdit* editMaksSoboty,* editMaksNiedziele,* editMaksWeekendy;
    QPushButton* buttonUpdate,* buttonStart;
    QPushButton* buttonZapiszUstawienia;
    QRadioButton* wyborMoze,* wyborNieMoze;
    QRadioButton* wyborDwa,* wyborTrzy,* wyborCztery,* wyborNic;
    QVBoxLayout* layoutButtonsPrawoLewo,* layoutListLeft,* layoutListRight;
    QHBoxLayout* layoutListWidgetsButtons;
    QGroupBox* groupMozeNieMoze,* groupPodRzad;
    QButtonGroup* groupRadioMozeNieMoze,* groupRadioPodRzad;
    QGridLayout* layoutLabelsEdits,* layoutRadioGroup;
    QVBoxLayout* layoutPodRzad;
    QVBoxLayout* mainLayout;
    QHBoxLayout* ultimateLayout;
    PDodawanieNowegoGrafiku* pDodawanieNowegoGrafiku;

    void wypelnijListeDyzurantami(std::vector<XDyzurant*>* tab);
};

#endif // UIDODAWANIENOWEGOGRAFIKU_H
