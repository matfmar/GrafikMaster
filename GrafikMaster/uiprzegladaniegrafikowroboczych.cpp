
#include "uiprzegladaniegrafikowroboczych.h"
#include "pprzegladaniegrafikowroboczych.h"

UIPrzegladanieGrafikowRoboczych::UIPrzegladanieGrafikowRoboczych(PPrzegladanieGrafikowRoboczych* p, QWidget *parent)
    : QMainWindow{parent} {
    setWindowTitle(tr("Przeglądanie grafików roboczych"));
    pPrzegladanieGrafikowRoboczych = p;
    mainWidget = new QWidget(this);

        

/*
    PPrzegladanieGrafikowRoboczych* pPrzegladanieGrafikowRoboczych;
    QWidget* mainWidget;

    QGroupBox* groupMiesiacRok;
    QLabel* labelMiesiac,* labelRok;
    QLineEdit* editMiesiac,* editRok;
    QPushBUtton* buttonSzukaj;
    QGridLayout* layoutGroup;
    
    QPushButton* buttonLeft,* buttonRight;
    QLabel* labelNumber;
    QHBoxLayout* layoutChoice;

    QTableWidget* tableGrafik;
    QPushButton* buttonClose;
    QVBoxLayout* mainLayout;
    */
        
}

