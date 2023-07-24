
#ifndef UIPRZEGLADANIEGRAFIKOWROBOCZYCH_H
#define UIPRZEGLADANIEGRAFIKOWROBOCZYCH_H


#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QTableWidget>

class PPrzegladanieGrafikowRoboczych;
class XWyswietlanyGrafik;

class UIPrzegladanieGrafikowRoboczych : public QMainWindow {
    Q_OBJECT
public:
    UIPrzegladanieGrafikowRoboczych(PPrzegladanieGrafikowRoboczych* p, QWidget *parent = nullptr);
    ~UIPrzegladanieGrafikowRoboczych() {}
    void ableRightButton(bool how);
    void ableLeftButton(bool how);
    void ableUsunButton(bool how);
    void wyswietlKonkretnyGrafik(XWyswietlanyGrafik* grafikDoWyswietlenia, int ktory, int ileWszystkich);
    void wyczyscTabele();
public slots:
    void onButtonSzukajClicked();
    void onButtonLeftClicked();
    void onButtonRightClicked();
    void onButtonCloseClicked();
    void onButtonUsunClicked();
private:
    PPrzegladanieGrafikowRoboczych* pPrzegladanieGrafikowRoboczych;
    QWidget* mainWidget;

    QGroupBox* groupMiesiacRok;
    QLabel* labelMiesiac,* labelRok;
    QLineEdit* editMiesiac,* editRok;
    QPushButton* buttonSzukaj;
    QGridLayout* layoutGroup;
    
    QPushButton* buttonLeft,* buttonRight,* buttonUsun,* buttonUsunWszystko;
    QLabel* labelNumber;
    QHBoxLayout* layoutChoice;

    QTableWidget* tableGrafik;
    QPushButton* buttonClose;
    QVBoxLayout* mainLayout;

};

#endif // UIPRZEGLADANIEGRAFIKOWROBOCZYCH_H
