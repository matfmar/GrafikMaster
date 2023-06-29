
#include "uiedycjabazydyzurantow.h"
#include "pedycjabazydyzurantow.h"
#include <QMessageBox>
#include "dto.h"

UIEdycjaBazyDyzurantow::UIEdycjaBazyDyzurantow(std::vector<XDyzurant*>* tablicaDyzurantow, PEdycjaBazyDyzurantow* pebd, QWidget *parent)
    : QMainWindow(parent), pEdycjaBazyDyzurantow(pebd) {
    setWindowTitle(tr("Edycja bazy dyżurantów"));
    mainWidget = new QWidget(this);

    listaDyzurantow = new QListWidget(this);
    listaDyzurantow -> setSelectionMode(QAbstractItemView::SingleSelection);
    buttonDodajDyzuranta = new QPushButton(tr("Dodaj nowego dyżuranta"), this);
    labelNick = new QLabel(tr("nick:"), this);
    labelPriorytet = new QLabel(tr("priorytet:"), this);
    editNick = new QLineEdit(this);
    editPriorytet = new QLineEdit(this);
    buttonUpdate = new QPushButton(tr("Aktualizuj dane"), this);
    buttonUsun = new QPushButton(tr("Usuń tego dyżuranta"), this);
    buttonSave = new QPushButton(tr("Zapisz zmiany - kliknij zanim zamkniesz okno!"), this);

    leftLayout = new QVBoxLayout(this);
    leftLayout -> addWidget(listaDyzurantow);
    leftLayout -> addWidget(buttonDodajDyzuranta);

    rightLayout = new QGridLayout(this);
    groupDyzurant = new QGroupBox(tr("Dane zaznaczonego dyżuranta"), this);
    rightLayout -> addWidget(labelNick, 0, 0);
    rightLayout -> addWidget(editNick, 0, 1);
    rightLayout -> addWidget(labelPriorytet, 1, 0);
    rightLayout -> addWidget(editPriorytet, 1, 1);
    rightLayout -> addWidget(buttonUpdate, 2, 2);
    rightLayout -> addWidget(buttonUsun, 3, 2);
    groupDyzurant -> setLayout(rightLayout);

    mainLayout = new QHBoxLayout(this);
    mainLayout -> addLayout(leftLayout);
    mainLayout -> addWidget(groupDyzurant);

    ultimateMainLayout = new QVBoxLayout(this);
    ultimateMainLayout -> addLayout(mainLayout);
    ultimateMainLayout -> addWidget(buttonSave);

    mainWidget -> setLayout(ultimateMainLayout);
    setCentralWidget(mainWidget);

    QObject::connect(buttonDodajDyzuranta, SIGNAL(clicked()), this, SLOT(onButtonDodajDyzurantaClicked()));
    QObject::connect(buttonUpdate, SIGNAL(clicked()), this, SLOT(onButtonUpdateDyzurantaClicked()));
    QObject::connect(buttonUsun, SIGNAL(clicked()), this, SLOT(onButtonUsunDyzurantaClicked()));
    QObject::connect(listaDyzurantow, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onListWidgetClicked(QListWidgetItem*)));

    wypelnijListeDyzurantami(tablicaDyzurantow);
}

void UIEdycjaBazyDyzurantow::wypelnijListeDyzurantami(std::vector<XDyzurant*>* tab) {
    if (tab == nullptr) {
        int ret = QMessageBox::critical(this, tr("BŁĄD"), tr("Błąd odczytu listy dyżurantów z bazy!"), QMessageBox::Ok);
        return;
    }
    QString item("");
    for (auto it = tab->begin(); it != tab->end(); ++it) {
        item = QString::fromStdString((*it)->getNick());
        listaDyzurantow -> addItem(item);
    }
}

void UIEdycjaBazyDyzurantow::aktualizujTabeleDyzurantow(std::vector<XDyzurant*>* tablicaDyzurantow, bool resultOfAddingNew) {
    int ret(-1);
    if (!resultOfAddingNew) {
        ret = QMessageBox::critical(this, tr("Błąd"), tr("Błąd dodawania nowego dyżuranta"), QMessageBox::Ok);
        return;
    }
    listaDyzurantow->clear();
    wypelnijListeDyzurantami(tablicaDyzurantow);
}

void UIEdycjaBazyDyzurantow::onButtonDodajDyzurantaClicked() {
    pEdycjaBazyDyzurantow -> wybranoDodanieNowegoDyzuranta();
}

void UIEdycjaBazyDyzurantow::onButtonUpdateDyzurantaClicked() {

}

void UIEdycjaBazyDyzurantow::onButtonUsunDyzurantaClicked() {

}

void UIEdycjaBazyDyzurantow::onListWidgetClicked(QListWidgetItem* item) {
    int row = listaDyzurantow->row(item);
    XDyzurant* dyzurant = pEdycjaBazyDyzurantow -> wybranoPokazanieSzczegolowDyzuranta(row);
    if (dyzurant == nullptr) {
        int ret = QMessageBox::critical(this, tr("BŁĄD"), tr("Błąd odczytu danych dyżuranta!"), QMessageBox::Ok);
        return;
    }
    editNick -> setText(QString::fromStdString(dyzurant->getNick()));
    editPriorytet -> setText(QString::number(dyzurant->getPriorytet()));
}

UIEdycjaBazyDyzurantow::~UIEdycjaBazyDyzurantow() {

}
