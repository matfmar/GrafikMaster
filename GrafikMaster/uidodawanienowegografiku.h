
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
    UIDodawanieNowegoGrafiku(std::vector<XDyzurant*>* td, PDodawanieNowegoGrafiku* pDodawanieNowegoGrafiku, QWidget *parent = nullptr);
    ~UIDodawanieNowegoGrafiku() {}
public slots:
    void onButtonUpdateClicked();
    void onButtonStartClicked();
    void onButtonZerujClicked();
    void onListaDyzurantowTworzacychClicked(QListWidgetItem* item);
private:
    QWidget* mainWidget;
    QListWidget* listaDyzurantowDostepnych,* listaDyzurantowTworzacych;
    QLabel* labelDyzuranciDostepni,* labelDyzuranciTworzacy;
    QPushButton* buttonWPrawo,* buttonWLewo;
    QLabel* labelChce,* labelNieMoze,* labelMoze,* labelUnika,* labelMaks,* labelMin,* labelPodRzad;
    QLabel* labelMaksSoboty,* labelMaksNiedziele,* labelMaksWeekendy;
    QLineEdit* editChce,* editNieMoze,* editMoze,* editUnika,* editMaks,* editMin;
    QLineEdit* editMaksSoboty,* editMaksNiedziele,* editMaksWeekendy;
    QPushButton* buttonUpdate,* buttonStart,* buttonZeruj;
    QRadioButton* wyborMoze,* wyborNieMoze;
    QRadioButton* wyborDwa,* wyborTrzy,* wyborCztery;

    QVBoxLayout* layoutButtonsPrawoLewo,* layoutListLeft,* layoutListRight;
    QHBoxLayout* layoutListWidgetsButtons;
    QGroupBox* groupMozeNieMoze,* groupPodRzad;
    QButtonGroup* groupRadioMozeNieMoze,* groupRadioPodRzad;
    QGridLayout* layoutLabelsEdits,* layoutRadioGroup;
    QVBoxLayout* layoutPodRzad;
    QVBoxLayout* mainLayout;
    QHBoxLayout* ultimateLayout;

    PDodawanieNowegoGrafiku* pDodawanieNowegoGrafiku;

};

#endif // UIDODAWANIENOWEGOGRAFIKU_H
