
#include "uiprzegladaniegrafikowroboczych.h"
#include "pprzegladaniegrafikowroboczych.h"
#include <QMessageBox>
#include <QStringList>

UIPrzegladanieGrafikowRoboczych::UIPrzegladanieGrafikowRoboczych(PPrzegladanieGrafikowRoboczych* p, QWidget *parent)
    : QMainWindow{parent} {
    setWindowTitle(tr("Przeglądanie grafików roboczych"));
    pPrzegladanieGrafikowRoboczych = p;
    mainWidget = new QWidget(this);

    labelMiesiac = new QLabel(tr("Miesiąc:"), this);
    labelRok = new QLabel(tr("Rok"), this);
    editMiesiac = new QLineEdit(this);
    editRok = new QLineEdit(this);
    buttonSzukaj = new QPushButton(tr("Szukaj grafików"), this);
    groupMiesiacRok = new QGroupBox(tr("Wyszukiwanie grup grafików"), this);
    layoutGroup = new QGridLayout(this);
    layoutGroup->addWidget(labelMiesiac, 0, 0);
    layoutGroup->addWidget(editMiesiac, 0, 1);
    layoutGroup->addWidget(labelRok, 1, 0);
    layoutGroup->addWidget(editRok, 1, 1);
    layoutGroup->addWidget(buttonSzukaj, 2, 0);
    groupMiesiacRok->setLayout(layoutGroup);

    buttonLeft = new QPushButton(tr("<<"), this);
    buttonRight = new QPushButton(tr(">>"), this);
    buttonLeft->setEnabled(false);
    buttonRight->setEnabled(false);
    labelNumber = new QLabel(tr("0"), this);
    layoutChoice = new QHBoxLayout(this);
    layoutChoice->addWidget(buttonLeft);
    layoutChoice->addWidget(labelNumber);
    layoutChoice->addWidget(buttonRight);

    tableGrafik = new QTableWidget(32, 3, this);
    QStringList etykiety;
    etykiety << "#" << "Dzień tygodnia" << "Dyżurant";
    tableGrafik->setHorizontalHeaderLabels(etykiety);
    tableGrafik->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableGrafik->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableGrafik->setSelectionMode(QAbstractItemView::SingleSelection);        
    buttonUsun = new QPushButton(tr("Usuń ten grafik"), this);
    buttonClose = new QPushButton(tr("Zamknij"), this);
    buttonUsun->setEnabled(false);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(groupMiesiacRok);
    mainLayout->addLayout(layoutChoice);
    mainLayout->addWidget(tableGrafik);
    mainLayout->addWidget(buttonUsun);
    mainLayout->addWidget(buttonClose);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    QObject::connect(buttonSzukaj, SIGNAL(clicked()), this, SLOT(onButtonSzukajClicked()));
    QObject::connect(buttonLeft, SIGNAL(clicked()), this, SLOT(onButtonLeftClicked()));
    QObject::connect(buttonRight, SIGNAL(clicked()), this, SLOT(onButtonRightClicked()));
    QObject::connect(buttonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));
    QObject::connect(buttonUsun, SIGNAL(clicked()), this, SLOT(onButtonUsunClicked()));
            
}

void UIPrzegladanieGrafikowRoboczych::onButtonSzukajClicked() {
    bool result1(false), result2(false);
    int miesiac = editMiesiac->text().toInt(&result1);
    int rok = editRok->text().toInt(&result2);
    if (!(result1 && result2)) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nieprawidłowe dane!"), QMessageBox::Ok);
        return;
    }
    int number(-1);
    number = pPrzegladanieGrafikowRoboczych->wybranoSzukanieGrafikow(miesiac, rok);
    labelNumber->setText("0 / " + QString::number(number));
}

void UIPrzegladanieGrafikowRoboczych::ableRightButton(bool how) {
    buttonRight->setEnabled(how);
}

void UIPrzegladanieGrafikowRoboczych::ableLeftButton(bool how) {
    buttonLeft->setEnabled(how);
}

void UIPrzegladanieGrafikowRoboczych::ableUsunButton(bool how) {
    buttonUsun->setEnabled(how);
}

void UIPrzegladanieGrafikowRoboczych::wyczyscTabele() {
    tableGrafik->clearContents();
    labelNumber->setText(tr("BRAK"));
}

void UIPrzegladanieGrafikowRoboczych::onButtonUsunClicked() {
    bool czyCosZostaje(false);
    bool result = pPrzegladanieGrafikowRoboczych->wybranoUsuniecieGrafiku(czyCosZostaje);
    if (!result) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nie udało się usunąć grafiku. Być może grafik nie został nawet wybrany."), QMessageBox::Ok);
        return;
    }
    QMessageBox::information(this, tr("Informacja"), tr("Usunięto dany grafik"), QMessageBox::Ok);
    if (!czyCosZostaje) {
        wyczyscTabele();
    }
}

void UIPrzegladanieGrafikowRoboczych::onButtonLeftClicked() {
    XWyswietlanyGrafik* grafikDoWyswietlenia(nullptr);
    int ktory(-1), ileWszystkich(-1);
    grafikDoWyswietlenia = pPrzegladanieGrafikowRoboczych->wybranoGrafikWLewo(ktory, ileWszystkich);
    if (grafikDoWyswietlenia == nullptr || grafikDoWyswietlenia->listaPozycjiGrafiku == nullptr) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nie udało się wyświetlić grafiku."), QMessageBox::Ok);
        return;
    }
    labelNumber->setText(QString::number(ktory) + " / " + QString::number(ileWszystkich));
    int licznikWierszy(0);
    for (auto it = grafikDoWyswietlenia->listaPozycjiGrafiku->begin(); it < grafikDoWyswietlenia->listaPozycjiGrafiku->end(); ++it) {
        tableGrafik->setItem(licznikWierszy, 0, (*it)->dzien);
        tableGrafik->setItem(licznikWierszy, 1, (*it)->dzienTygodnia);
        tableGrafik->setItem(licznikWierszy, 2, (*it)->dyzurant);
        licznikWierszy++;
    }    
}

void UIPrzegladanieGrafikowRoboczych::wyswietlKonkretnyGrafik(XWyswietlanyGrafik* grafikDoWyswietlenia, int ktory, int ileWszystkich) {
    if (grafikDoWyswietlenia->listaPozycjiGrafiku == nullptr) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nie udało się wyświetlić grafiku."), QMessageBox::Ok);
        return;
    }
    labelNumber->setText(QString::number(ktory) + " / " + QString::number(ileWszystkich));
    int licznikWierszy(0);
    for (auto it = grafikDoWyswietlenia->listaPozycjiGrafiku->begin(); it < grafikDoWyswietlenia->listaPozycjiGrafiku->end(); ++it) {
        tableGrafik->setItem(licznikWierszy, 0, (*it)->dzien);
        tableGrafik->setItem(licznikWierszy, 1, (*it)->dzienTygodnia);
        tableGrafik->setItem(licznikWierszy, 2, (*it)->dyzurant);
        licznikWierszy++;
    }    
}
    
void UIPrzegladanieGrafikowRoboczych::onButtonRightClicked() {
    XWyswietlanyGrafik* grafikDoWyswietlenia(nullptr);
    int ktory(-1), ileWszystkich(-1);
    grafikDoWyswietlenia = pPrzegladanieGrafikowRoboczych->wybranoGrafikWPrawo(ktory, ileWszystkich);
    if (grafikDoWyswietlenia == nullptr || grafikDoWyswietlenia->listaPozycjiGrafiku == nullptr) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nie udało się wyświetlić grafiku."), QMessageBox::Ok);
        return;
    }
    labelNumber->setText(QString::number(ktory) + " / " + QString::number(ileWszystkich));
    int licznikWierszy(0);
    for (auto it = grafikDoWyswietlenia->listaPozycjiGrafiku->begin(); it < grafikDoWyswietlenia->listaPozycjiGrafiku->end(); ++it) {
        tableGrafik->setItem(licznikWierszy, 0, (*it)->dzien);
        tableGrafik->setItem(licznikWierszy, 1, (*it)->dzienTygodnia);
        tableGrafik->setItem(licznikWierszy, 2, (*it)->dyzurant);
        licznikWierszy++;
    }
}
    
void UIPrzegladanieGrafikowRoboczych::onButtonCloseClicked() {
    close();
}

