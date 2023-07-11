
#include "uidecydowanieokoniecznosciszukaniagrafikow.h"
#include <QMessageBox>

UIDecydowanieOKoniecznosciSzukaniaGrafikow::UIDecydowanieOKoniecznosciSzukaniaGrafikow()
    : QDialog() {
    setWindowTitle(tr("Szukanie grafików..."));

    buttonSzukajDalej = new QPushButton(tr("SZUKAJ DALEJ"), this);
    buttonWyswietlGrafiki = new QPushButton(tr("WYŚWIETL ZNALEZIONE GRAFIKI"), this);
    buttonZakonczSzukanie = new QPushButton(tr("ZAKOŃCZ SZUKANIE"), this);\

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(buttonSzukajDalej);
    mainLayout->addWidget(buttonWyswietlGrafiki);
    mainLayout->addWidget(buttonZakonczSzukanie);

    setLayout(mainLayout);

    QObject::connect(buttonSzukajDalej, SIGNAL(clicked()), this, SLOT(onButtonSzukajDalejClicked()));
    QObject::connect(buttonWyswietlGrafiki, SIGNAL(clicked()), this, SLOT(onButtonWyswietlGrafikiClicked()));
    QObject::connect(buttonZakonczSzukanie, SIGNAL(clicked()), this, SLOT(onButtonZakonczSzukanieClicked()));

}

void UIDecydowanieOKoniecznosciSzukaniaGrafikow::onButtonSzukajDalejClicked() {

}

void UIDecydowanieOKoniecznosciSzukaniaGrafikow::onButtonZakonczSzukanieClicked() {

}

void UIDecydowanieOKoniecznosciSzukaniaGrafikow::onButtonWyswietlGrafikiClicked() {

}

void UIDecydowanieOKoniecznosciSzukaniaGrafikow::wyswietlKomunikatZakonczeniaSzukania() {
    QMessageBox::information(this, tr("Informacja"), tr("Zakończono wyszukiwanie grafików"), QMessageBox::Ok);
    close();
}
