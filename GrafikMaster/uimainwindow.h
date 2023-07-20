
#ifndef UIMAINWINDOW_H
#define UIMAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class PMain;

class UIMainWindow : public QMainWindow {
    Q_OBJECT

public:
    UIMainWindow(PMain* pm, QWidget *parent = nullptr);
    ~UIMainWindow();
public slots:
    void onButtonEdytujBazeDyzurantowClicked();
    void onButtonDodajNowyGrafikClicked();
    void onButtonPrzegladajGrafikiRoboczeClicked();
    void onButtonPrzegladajGrafikiOstateczneClicked();
    void onButtonZakonczBezpiecznieTworzenieGrafikowClicked();
private:
    PMain* pMain;
    QWidget* mainWidget;
    QVBoxLayout* layout;
    QLabel* mainLabel;
    QPushButton* buttonEdytujBazeDyzurantow;
    QPushButton* buttonDodajNowyGrafik;
    QPushButton* buttonPrzegladajGrafikiRobocze;
    QPushButton* buttonPrzegladajGrafikiOstateczne;
    QPushButton* buttonZakonczBezpiecznieTworzenieGrafikow;


};

#endif // UIMAINWINDOW_H
