
#include "uimainwindow.h"
#include "pmain.h"

UIMainWindow::UIMainWindow(PMain* pm, QWidget *parent)
    : QMainWindow(parent), pMain(pm) {
    setWindowTitle(tr("Grafik Master, v1.0"));
    mainWidget = new QWidget(this);

    mainLabel = new QLabel(tr("Witaj w programie do układania grafików!"), this);
    layout = new QVBoxLayout(this);
    buttonEdytujBazeDyzurantow = new QPushButton(tr("Edytuj bazę dyżurantów"), this);
    buttonDodajNowyGrafik = new QPushButton(tr("Dodaj nowy grafik"), this);
    buttonZakonczBezpiecznieTworzenieGrafikow = new QPushButton(tr("Kliknij, aby bezpiecznie zakończyć tworzenie grafików"), this);
    buttonPrzegladajGrafikiRobocze = new QPushButton(tr("Przeglądaj grafiki robocze"), this);
    buttonPrzegladajGrafikiOstateczne = new QPushButton(tr("Przeglądaj grafiki ostateczne"), this);
    buttonZakonczBezpiecznieTworzenieGrafikow->setEnabled(false);

    layout -> addWidget(mainLabel);
    layout -> addWidget(buttonEdytujBazeDyzurantow);
    layout -> addWidget(buttonDodajNowyGrafik);
    layout -> addWidget(buttonZakonczBezpiecznieTworzenieGrafikow);
    layout -> addWidget(buttonPrzegladajGrafikiRobocze);
    layout -> addWidget(buttonPrzegladajGrafikiOstateczne);

    mainWidget -> setLayout(layout);
    setCentralWidget(mainWidget);

    QObject::connect(buttonEdytujBazeDyzurantow, SIGNAL(clicked()), this, SLOT(onButtonEdytujBazeDyzurantowClicked()));
    QObject::connect(buttonDodajNowyGrafik, SIGNAL(clicked()), this, SLOT(onButtonDodajNowyGrafikClicked()));
    QObject::connect(buttonPrzegladajGrafikiRobocze, SIGNAL(clicked()), this, SLOT(onButtonPrzegladajGrafikiRoboczeClicked()));
    QObject::connect(buttonPrzegladajGrafikiOstateczne, SIGNAL(clicked()), this, SLOT(onButtonPrzegladajGrafikiOstateczneClicked()));
    QObject::connect(buttonZakonczBezpiecznieTworzenieGrafikow, SIGNAL(clicked()), this, SLOT(onButtonZakonczBezpiecznieTworzenieGrafikowClicked()));

}

void UIMainWindow::onButtonEdytujBazeDyzurantowClicked() {
    pMain -> wybranoEdycjeBazyDyzurantow();
}

void UIMainWindow::onButtonDodajNowyGrafikClicked() {
    buttonZakonczBezpiecznieTworzenieGrafikow->setEnabled(true);
    pMain -> wybranoDodanieNowegoGrafiku();
}

void UIMainWindow::onButtonZakonczBezpiecznieTworzenieGrafikowClicked() {
    buttonZakonczBezpiecznieTworzenieGrafikow->setEnabled(false);
    pMain -> wybranoZakonczenieTworzeniaGrafikow();
}

void UIMainWindow::onButtonPrzegladajGrafikiRoboczeClicked() {

}

void UIMainWindow::onButtonPrzegladajGrafikiOstateczneClicked() {

}

UIMainWindow::~UIMainWindow() {
}


