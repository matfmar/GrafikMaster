
#include "uidodawanienowegografiku.h"
#include "pdodawanienowegografiku.h"
#include "dto.h"
#include <QMessageBox>

UIDodawanieNowegoGrafiku::UIDodawanieNowegoGrafiku(std::vector<XDyzurant*>* td, PDodawanieNowegoGrafiku* pd, QWidget *parent)
    : QMainWindow{parent} {
    setWindowTitle(tr("Dodawanie dyżurantów do grafiku"));
    mainWidget = new QWidget(this);
    pDodawanieNowegoGrafiku = pd;

    labelDyzuranciDostepni = new QLabel(tr("Lista dostępnych dyżurantów:"), this);
    labelDyzuranciTworzacy = new QLabel(tr("Lista dyżurantów do tego grafiku:"), this);
    listaDyzurantowDostepnych = new QListWidget(this);
    listaDyzurantowDostepnych -> setSelectionMode(QAbstractItemView::SingleSelection);
    listaDyzurantowTworzacych = new QListWidget(this);
    listaDyzurantowTworzacych -> setSelectionMode(QAbstractItemView::SingleSelection);
    buttonWLewo = new QPushButton(tr("<<<<<"), this);
    buttonWLewo->setEnabled(false);
    buttonWPrawo = new QPushButton(tr(">>>>>"), this);
    buttonWPrawo->setEnabled(false);
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
    editNieMoze->setEnabled(true);
    editMoze->setEnabled(false);

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
    wyborNic = new QRadioButton(tr("Nie unikaj ciągów"), this);
    groupRadioPodRzad = new QButtonGroup(this);
    groupRadioPodRzad->addButton(wyborDwa);
    groupRadioPodRzad->addButton(wyborTrzy);
    groupRadioPodRzad->addButton(wyborCztery);
    groupRadioPodRzad->addButton(wyborNic);
    layoutPodRzad = new QVBoxLayout(this);
    layoutPodRzad->addWidget(labelPodRzad);
    layoutPodRzad->addWidget(wyborDwa);
    layoutPodRzad->addWidget(wyborTrzy);
    layoutPodRzad->addWidget(wyborCztery);
    layoutPodRzad->addWidget(wyborNic);
    groupPodRzad = new QGroupBox(tr("Ciągi dyżurowe"), this);
    groupPodRzad->setLayout(layoutPodRzad);
    wyborCztery->setChecked(true);

    buttonUpdate = new QPushButton(tr("Aktualizuj dane"), this);
    buttonUpdate->setEnabled(false);

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
    QObject::connect(listaDyzurantowTworzacych, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onListaDyzurantowTworzacychClicked(QListWidgetItem*)));
    QObject::connect(listaDyzurantowDostepnych, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onListaDyzurantowDostepnychClicked(QListWidgetItem*)));
    QObject::connect(buttonWPrawo, SIGNAL(clicked()), this, SLOT(onButtonWPrawoClicked()));
    QObject::connect(buttonWLewo, SIGNAL(clicked()), this, SLOT(onButtonWLewoClicked()));
    QObject::connect(wyborMoze, SIGNAL(clicked()), this, SLOT(onWyborMozeClicked()));
    QObject::connect(wyborNieMoze, SIGNAL(clicked()), this, SLOT(onWyborNieMozeClicked()));

    wypelnijListeDyzurantami(td);
}

void UIDodawanieNowegoGrafiku::wypelnijListeDyzurantami(std::vector<XDyzurant*>* tab) {
    if (tab == nullptr) {
        int ret = QMessageBox::critical(this, tr("BŁĄD"), tr("Błąd odczytu listy dyżurantów z bazy!"), QMessageBox::Ok);
        return;
    }
    QString item("");
    for (auto it = tab->begin(); it != tab->end(); ++it) {
        item = QString::fromStdString((*it)->getNick());
        listaDyzurantowDostepnych -> addItem(item);
    }
}

void UIDodawanieNowegoGrafiku::onButtonWPrawoClicked() {
    QString nick = (listaDyzurantowDostepnych->currentItem())->text();
    QString nowyNick = pDodawanieNowegoGrafiku->wybranoDodanieDyzurantaTworzacego(nick);
    listaDyzurantowTworzacych->addItem(nowyNick);
    delete (listaDyzurantowDostepnych->currentItem());
    buttonWPrawo->setEnabled(false);
}

void UIDodawanieNowegoGrafiku::onButtonWLewoClicked() {
    QString nick = (listaDyzurantowTworzacych->currentItem())->text();
    pDodawanieNowegoGrafiku->wybranoUsuniecieDyzurantaTworzacego(nick);
    listaDyzurantowDostepnych->addItem(nick);
    delete (listaDyzurantowTworzacych->currentItem());
    buttonWLewo->setEnabled(false);
}

void UIDodawanieNowegoGrafiku::onButtonUpdateClicked() {
    QString nick = listaDyzurantowTworzacych->currentItem()->text();
    bool czyWpisywanieGdzieMoze = wyborMoze->isChecked();
    QString stringMoze = editMoze->text();
    QString stringNieMoze = editNieMoze->text();
    QString stringChce = editChce->text();
    QString stringUnika = editUnika->text();
    bool result;
    int maksymalnie = editMaks->text().toInt(&result);
    if (!result) return;
    int minimalnie = editMin->text().toInt(&result);
    if (!result) return;
    int maksSoboty = editMaksSoboty->text().toInt(&result);
    if (!result) return;
    int maksNiedziele = editMaksNiedziele->text().toInt(&result);
    if (!result) return;
    int maksWeekendy = editMaksWeekendy->text().toInt(&result);
    if (!result) return;
    int wyborCiagi(-1);
    if (wyborNic->isChecked()) wyborCiagi = 0;
    else if (wyborDwa->isChecked()) wyborCiagi = 2;
    else if (wyborTrzy->isChecked()) wyborCiagi = 3;
    else if (wyborCztery->isChecked()) wyborCiagi = 4;
    else wyborCiagi = -1;
    result = pDodawanieNowegoGrafiku->wybranoUpdateDyzurantaTworzacego(nick, czyWpisywanieGdzieMoze, stringMoze, stringNieMoze, stringUnika, stringChce, maksymalnie, minimalnie, maksSoboty, maksNiedziele, maksWeekendy, wyborCiagi);
    if (!result) {
        QMessageBox::critical(this, tr("Błąd"), tr("Błędne dane!"), QMessageBox::Ok);
    }
    else {
        QMessageBox::information(this, tr("Potwierdzenie"), tr("Zaktualizowano dane dyżuranta w tym grafiku."), QMessageBox::Ok);
    }
    onListaDyzurantowTworzacychClicked(listaDyzurantowTworzacych->currentItem());
}

void UIDodawanieNowegoGrafiku::onButtonStartClicked() {
    pDodawanieNowegoGrafiku->wybranoProsbeOStworzenieGrafiku();
}

void UIDodawanieNowegoGrafiku::onListaDyzurantowDostepnychClicked(QListWidgetItem* item) {
    buttonWPrawo->setEnabled(true);
}

void UIDodawanieNowegoGrafiku::onListaDyzurantowTworzacychClicked(QListWidgetItem* item) {
    QString nick = item ->text();
    XDyzurantTworzacy* aktualnyDyzurant = pDodawanieNowegoGrafiku -> wybranoPobranieDanychDyzurantaTworzacego(nick);
    editChce->setText(QString::fromStdString(aktualnyDyzurant->getKiedyChce()));
    bool wybor = aktualnyDyzurant->getCzyWpisywanieGdzieMoze();
    if (wybor) {
        wyborMoze->setChecked(true);
        editMoze->setText(QString::fromStdString(aktualnyDyzurant->getKiedyMoze()));
        editMoze->setEnabled(true);
        editNieMoze->clear();
        editNieMoze->setEnabled(false);
    }
    else {
        wyborNieMoze->setChecked(true);
        editNieMoze->setText(QString::fromStdString(aktualnyDyzurant->getKiedyNieMoze()));
        editNieMoze->setEnabled(true);
        editMoze->clear();
        editMoze->setEnabled(false);
    }
    editUnika->setText(QString::fromStdString(aktualnyDyzurant->getKiedyUnika()));
    editMaks->setText(QString::number(aktualnyDyzurant->getMaksymalnie()));
    editMin->setText(QString::number(aktualnyDyzurant->getMinimalnie()));
    editMaksSoboty->setText(QString::number(aktualnyDyzurant->getMaksymelnieSoboty()));
    editMaksNiedziele->setText(QString::number(aktualnyDyzurant->getMaksymalnieNiedziele()));
    editMaksWeekendy->setText(QString::number(aktualnyDyzurant->getMaksymalnieWeekendy()));
    switch (aktualnyDyzurant->getUnikaniePodRzad()) {
    case 0: wyborNic->setChecked(true); break;
    case 2: wyborDwa->setChecked(true); break;
    case 3: wyborTrzy->setChecked(true); break;
    case 4: wyborCztery->setChecked(true); break;
    default: wyborNic->setChecked(true); break;
    }

    buttonWLewo->setEnabled(true);
    buttonUpdate->setEnabled(true);
}

void UIDodawanieNowegoGrafiku::onWyborMozeClicked() {
    if (wyborMoze->isChecked()) {
        editMoze->setEnabled(true);
        editNieMoze->setEnabled(false);
        editNieMoze->clear();
    }
    else {
        editMoze->setEnabled(false);
        editMoze->clear();
        editNieMoze->setEnabled(true);
    }
}

void UIDodawanieNowegoGrafiku::onWyborNieMozeClicked() {
    if (wyborNieMoze->isChecked()) {
        editNieMoze->setEnabled(true);
        editMoze->setEnabled(false);
        editMoze->clear();
    }
    else {
        editNieMoze->setEnabled(false);
        editNieMoze->clear();
        editMoze->setEnabled(true);
    }
}

