
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

class UIPrzegladanieGrafikowRoboczych : public QMainWindow {
    Q_OBJECT
public:
    UIPrzegladanieGrafikowRoboczych(PPrzegladanieGrafikowRoboczych* p, QWidget *parent = nullptr);
    ~UIPrzegladanieGrafikowRoboczych() {}
public slots:
    void onButtonSzukajClicked();
    void onButtonLeftClicked();
    void onButtonRightClicked();
    void onButtonCloseClicked();
private:
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

};

#endif // UIPRZEGLADANIEGRAFIKOWROBOCZYCH_H
