
#include "uidodawanienowegografiku.h"

UIDodawanieNowegoGrafiku::UIDodawanieNowegoGrafiku(QWidget *parent)
    : QMainWindow{parent} {
    setWindowTitle(tr("Dodawanie dyżurantów do grafiku"));
    mainWidget = new QWidget(this);

    labelDyzuranciDostepni = new QLabel(tr("Lista dostępnych dyżurantów:"), this);
    labelDyzuranciTworzacy = new QLabel(tr("Lista dyżurantów do tego grafiku:"), this);
    listaDyzurantowDostepnych = new QListWidget(this);
    listaDyzurantowDostepnych -> setSelectionMode(QAbstractItemView::SingleSelection);
    listaDyzurantowTworzacych = new QListWidget(this);
    listaDyzurantowTworzacych -> setSelectionMode(QAbstractItemView::SingleSelection);
    buttonWLewo = new QPushButton(tr("<<<<<"), this);
    buttonWPrawo = new QPushButton(tr(">>>>>"), this);
    layoutButtonsPrawoLewo = new QVBoxLayout(this);
    layoutButtonsPrawoLewo->addWidget(buttonWLewo);
    layoutButtonsPrawoLewo->addWidget(buttonWPrawo);
    layoutListLeft = new QVBoxLayout(this);
    layoutListLeft->addWidget(labelDyzuranciDostepni);
    layoutListLeft->addWidget(listaDyzurantowDostepnych);
    layoutListRight = new QVBoxLayout(this);
    layoutListRight->addWidget(labelDyzuranciTworzacy);
    layoutListRight->addWidget(listaDyzurantowTworzacych);
    layoutListWidgetsButtons = new QHBoxLayout(this);
    layoutListWidgetsButtons->addLayout(layoutListLeft);
    layoutListWidgetsButtons->addLayout(layoutButtonsPrawoLewo);
    layoutListWidgetsButtons->addLayout(layoutListRight);

    labelNieMoze = new QLabel(tr("Nie może:"), this);
    labelMoze = new QLabel(tr("Może:"), this);
    editNieMoze = new QLineEdit(this);
    editMoze = new QLineEdit(this);
    wyborMoze = new QRadioButton(tr("MOŻE"), this);
    wyborNieMoze = new QRadioButton(tr("NIE MOŻE"), this);
    groupRadioMozeNieMoze = new QButtonGroup(this);
    groupRadioMozeNieMoze->addButton(wyborNieMoze);
    groupRadioMozeNieMoze->addButton(wyborMoze);
    layoutRadioGroup = new QGridLayout(this);
    layoutRadioGroup->addWidget(wyborNieMoze, 0, 0);
    layoutRadioGroup->addWidget(wyborMoze, 0, 1);
    layoutRadioGroup->addWidget(labelNieMoze, 1, 0);
    layoutRadioGroup->addWidget(editNieMoze, 1, 1);
    layoutRadioGroup->addWidget(labelMoze, 2, 0);
    layoutRadioGroup->addWidget(editMoze, 2, 1);
    groupMozeNieMoze = new QGroupBox(tr("Dni, w których może lub nie może wziąć dyżuru"), this);
    groupMozeNieMoze->setLayout(layoutRadioGroup);
    wyborNieMoze->setChecked(true);

    labelChce = new QLabel(tr("Chce:"), this);
    editChce = new QLineEdit(this);
    labelUnika = new QLabel(tr("Unika:"), this);
    editUnika = new QLineEdit(this);
    labelMaks = new QLabel(tr("Maksymalna liczba dyżurów:"), this);
    editMaks = new QLineEdit(this);
    labelMin = new QLabel(tr("Minimalna liczba dyżurów:"), this);
    editMin = new QLineEdit(this);
    labelMaksSoboty = new QLabel(tr("Maksymalna liczba sobót:"), this);
    editMaksSoboty = new QLineEdit(this);
    labelMaksNiedziele = new QLabel(tr("Maksymalna liczba niedziel:"), this);
    editMaksNiedziele = new QLineEdit(this);
    labelMaksWeekendy = new QLabel(tr("Maksymalna liczba weekendów:"), this);
    editMaksWeekendy = new QLineEdit(this);
    layoutLabelsEdits = new QGridLayout(this);
    layoutLabelsEdits->addWidget(labelChce, 0, 0);
    layoutLabelsEdits->addWidget(editChce, 0, 1);
    layoutLabelsEdits->addWidget(labelUnika, 1, 0);
    layoutLabelsEdits->addWidget(editUnika, 1, 1);
    layoutLabelsEdits->addWidget(labelMaks, 2, 0);
    layoutLabelsEdits->addWidget(editMaks, 2, 1);
    layoutLabelsEdits->addWidget(labelMin, 3, 0);
    layoutLabelsEdits->addWidget(editMin, 3, 1);
    layoutLabelsEdits->addWidget(labelMaksSoboty, 4, 0);
    layoutLabelsEdits->addWidget(editMaksSoboty, 4, 1);
    layoutLabelsEdits->addWidget(labelMaksNiedziele, 5, 0);
    layoutLabelsEdits->addWidget(editMaksNiedziele, 5, 1);
    layoutLabelsEdits->addWidget(labelMaksWeekendy, 6, 0);
    layoutLabelsEdits->addWidget(editMaksWeekendy, 6, 1);

    labelPodRzad = new QLabel(tr("Unikaj ciągów:"), this);
    wyborDwa = new QRadioButton(tr("Dwa i więcej pod rząd"), this);
    wyborTrzy = new QRadioButton(tr("Trzy i więcej pod rząd"), this);
    wyborCztery = new QRadioButton(tr("Cztery i więcej pod rząd"), this);
    groupRadioPodRzad = new QButtonGroup(this);
    groupRadioPodRzad->addButton(wyborDwa);
    groupRadioPodRzad->addButton(wyborTrzy);
    groupRadioPodRzad->addButton(wyborCztery);
    buttonZeruj = new QPushButton(tr("Wyczyść ciągi dyżurowe"), this);
    layoutPodRzad = new QVBoxLayout(this);
    layoutPodRzad->addWidget(labelPodRzad);
    layoutPodRzad->addWidget(wyborDwa);
    layoutPodRzad->addWidget(wyborTrzy);
    layoutPodRzad->addWidget(wyborCztery);
    layoutPodRzad->addWidget(buttonZeruj);
    groupPodRzad = new QGroupBox(tr("Ciągi dyżurowe"), this);
    groupPodRzad->setLayout(layoutPodRzad);

    buttonUpdate = new QPushButton(tr("Aktualizuj dane"), this);

    mainLayout = new QVBoxLayout(this);
    mainLayout -> addLayout(layoutListWidgetsButtons);
    mainLayout -> addWidget(groupMozeNieMoze);
    mainLayout -> addLayout(layoutLabelsEdits);
    mainLayout -> addWidget(groupPodRzad);
    mainLayout -> addWidget(buttonUpdate);

    buttonStart = new QPushButton(tr("UŁÓŻ GRAFIK !"), this);

    ultimateLayout = new QHBoxLayout(this);
    ultimateLayout -> addLayout(mainLayout);
    ultimateLayout -> addWidget(buttonStart);

    mainWidget -> setLayout(ultimateLayout);
    setCentralWidget(mainWidget);

    QObject::connect(buttonUpdate, SIGNAL(clicked()), this, SLOT(onButtonUpdateClicked()));
    QObject::connect(buttonStart, SIGNAL(clicked()), this, SLOT(onButtonStartClicked()));
    QObject::connect(buttonZeruj, SIGNAL(clicked()), this, SLOT(onButtonZerujClicked()));
    QObject::connect(listaDyzurantowTworzacych, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onListaDyzurantowTworzacychClicked(QListWidgetItem*)));

}

void UIDodawanieNowegoGrafiku::onButtonUpdateClicked() {
    
}

void UIDodawanieNowegoGrafiku::onButtonStartClicked() {
    
}
    
void UIDodawanieNowegoGrafiku::onButtonZerujClicked() {
    
}

void UIDodawanieNowegoGrafiku::onListaDyzurantowTworzacychClicked(QListWidgetItem* item) {
    
}

