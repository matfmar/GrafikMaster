
#include "uidecydowanieokoniecznosciszukaniagrafikow.h"
#include "pdecydowanieokontynuacjiszukaniagrafikow.h"
#include <QMessageBox>

UIDecydowanieOKoniecznosciSzukaniaGrafikow::UIDecydowanieOKoniecznosciSzukaniaGrafikow(PDecydowanieOKontynuacjiSzukaniaGrafikow* p) {
    setWindowTitle(tr("Szukanie grafików..."));
    parent = p;

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
    parent->setDecyzjaUzytkownika(1);
    close();
}

void UIDecydowanieOKoniecznosciSzukaniaGrafikow::onButtonZakonczSzukanieClicked() {
    parent->setDecyzjaUzytkownika(2);
    close();
}

void UIDecydowanieOKoniecznosciSzukaniaGrafikow::onButtonWyswietlGrafikiClicked() {

}

void UIDecydowanieOKoniecznosciSzukaniaGrafikow::wyswietlKomunikatZakonczeniaSzukania(bool result, int ileGrafikow) {
    QString s = QString::number(ileGrafikow);
    QString msg("");
    if (!result) {
        msg = "Zakończono wyszukiwanie grafików - skończyły się opcje. Liczba grafików: " + s + ".";
        QMessageBox::information(this, tr("Informacja"), msg, QMessageBox::Ok);
    }
    else {
        msg = "Zakończono wyszukiwanie grafików - na prośbę użytkownika. Liczba grafików: " + s + ".";
        QMessageBox::information(this, tr("Informacja"), msg, QMessageBox::Ok);
    }
    close();
}
