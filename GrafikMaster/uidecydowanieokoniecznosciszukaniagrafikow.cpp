
#include "uidecydowanieokoniecznosciszukaniagrafikow.h"
#include "pdecydowanieokontynuacjiszukaniagrafikow.h"
#include <QMessageBox>

UIDecydowanieOKoniecznosciSzukaniaGrafikow::UIDecydowanieOKoniecznosciSzukaniaGrafikow(PDecydowanieOKontynuacjiSzukaniaGrafikow* p) {
    setWindowTitle(tr("Szukanie grafików..."));
    parent = p;

    buttonSzukajDalej = new QPushButton(tr("SZUKAJ DALEJ"), this);
    buttonZakonczSzukanie = new QPushButton(tr("ZAKOŃCZ SZUKANIE"), this);
    label = new QLabel(labelText, this);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(label);
    mainLayout->addWidget(buttonSzukajDalej);
    mainLayout->addWidget(buttonZakonczSzukanie);

    setLayout(mainLayout);

    QObject::connect(buttonSzukajDalej, SIGNAL(clicked()), this, SLOT(onButtonSzukajDalejClicked()));
    QObject::connect(buttonZakonczSzukanie, SIGNAL(clicked()), this, SLOT(onButtonZakonczSzukanieClicked()));

    setFixedSize(300, 300);
}

void UIDecydowanieOKoniecznosciSzukaniaGrafikow::setLabel(int ileGrafikow) {
    label->setText(labelText + QString::number(ileGrafikow));
}

void UIDecydowanieOKoniecznosciSzukaniaGrafikow::onButtonSzukajDalejClicked() {
    parent->setDecyzjaUzytkownika(1);
    close();
}

void UIDecydowanieOKoniecznosciSzukaniaGrafikow::onButtonZakonczSzukanieClicked() {
    parent->setDecyzjaUzytkownika(2);
    close();
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

UIDecydowanieOKoniecznosciSzukaniaGrafikow::~UIDecydowanieOKoniecznosciSzukaniaGrafikow() {

}
