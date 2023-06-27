
#include "uiedycjabazydyzurantow.h"
#include "pedycjabazydyzurantow.h"

UIEdycjaBazyDyzurantow::UIEdycjaBazyDyzurantow(PEdycjaBazyDyzurantow* pebd, QWidget *parent)
    : QMainWindow(parent), pEdycjaBazyDyzurantow(pebd) {
    setWindowTitle(tr("Edycja bazy dyżurantów"));
    mainWidget = new QWidget(this);

    listaDyzurantow = new QListWidget(this);
    buttonDodajDyzuranta = new QPushButton(tr("Dodaj nowego dyżuranta"), this);
    labelNick = new QLabel(tr("nick:"), this);
    labelPriorytet = new QLabel(tr("priorytet:"), this);
    editNick = new QLineEdit(this);
    editPriorytet = new QLineEdit(this);
    buttonUpdate = new QPushButton(tr("Aktualizuj dane"), this);
    buttonUsun = new QPushButton(tr("Usuń tego dyżuranta"), this);

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

    mainWidget -> setLayout(mainLayout);
    setCentralWidget(mainWidget);

    QObject::connect(buttonDodajDyzuranta, SIGNAL(clicked()), this, SLOT(onButtonDodajDyzurantaClicked()));
    QObject::connect(buttonUpdate, SIGNAL(clicked()), this, SLOT(onButtonUpdateDyzurantaClicked()));
    QObject::connect(buttonUsun, SIGNAL(clicked()), this, SLOT(onButtonUsunDyzurantaClicked()));
    QObject::connect(listaDyzurantow, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onListWidgetClicked(QListWidgetItem*)));

}

void UIEdycjaBazyDyzurantow::onButtonDodajDyzurantaClicked() {

}

void UIEdycjaBazyDyzurantow::onButtonUpdateDyzurantaClicked() {

}

void UIEdycjaBazyDyzurantow::onButtonUsunDyzurantaClicked() {

}

void UIEdycjaBazyDyzurantow::onListWidgetClicked(QListWidgetItem* item) {

}

UIEdycjaBazyDyzurantow::~UIEdycjaBazyDyzurantow() {

}
