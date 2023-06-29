
#include "uidodawanienowegodyzuranta.h"
#include "pedycjabazydyzurantow.h"
#include <QMessageBox>

UIDodawanieNowegoDyzuranta::UIDodawanieNowegoDyzuranta(PEdycjaBazyDyzurantow* pebd) {
    setWindowTitle(tr("Dodawanie nowego dyżuranta"));
    pEdycjaBazyDyzurantow = pebd;

    labelNick = new QLabel(tr("nick:"), this);
    labelPriorytet = new QLabel(tr("priorytet:"), this);
    editNick = new QLineEdit(this);
    editPriorytet = new QLineEdit(this);
    buttonOK = new QPushButton(tr("OK"), this);
    buttonAnuluj = new QPushButton(tr("Anuluj"), this);

    layout = new QGridLayout(this);
    layout -> addWidget(labelNick, 0, 0);
    layout -> addWidget(labelPriorytet, 1, 0);
    layout -> addWidget(editNick, 0, 1);
    layout -> addWidget(editPriorytet, 1, 1);
    layout -> addWidget(buttonOK, 2, 0);
    layout -> addWidget(buttonAnuluj, 2, 1);

    setLayout(layout);

    QObject::connect(buttonOK, SIGNAL(clicked()), this, SLOT(onButtonOKClicked()));
    QObject::connect(buttonAnuluj, SIGNAL(clicked()), this, SLOT(onButtonAnulujClicked()));
}

void UIDodawanieNowegoDyzuranta::onButtonOKClicked() {
    QString nick = editNick -> text();
    QString idText = editPriorytet -> text();
    int ret(-1);
    if (nick.isEmpty() || idText.isEmpty()) {
        ret = QMessageBox::critical(this, tr("Błąd"), tr("Niewłaściwe dane!"), QMessageBox::Ok);
        close();
        return;
    }
    int priorytet(0);
    bool result(false);
    priorytet = idText.toInt(&result);
    if (!result) {
        ret = QMessageBox::critical(this, tr("Błąd"), tr("Niewłaściwe dane!"), QMessageBox::Ok);
        close();
        return;
    }
    pEdycjaBazyDyzurantow ->wybranoPrawdziweDodanieNowegoDyzuranta(nick, priorytet);
}

void UIDodawanieNowegoDyzuranta::onButtonAnulujClicked() {
    close();
}

UIDodawanieNowegoDyzuranta::~UIDodawanieNowegoDyzuranta() {}
