
#include "uiprzegladaniegrafikowroboczych.h"
#include "pprzegladaniegrafikowroboczych.h"
#include <QMessageBox>
#include <QStringList>
#include "dto.h"
#include <QFont>
#include <QFileDialog>

UIPrzegladanieGrafikowRoboczych::UIPrzegladanieGrafikowRoboczych(PPrzegladanieGrafikowRoboczych* p, QWidget *parent)
    : QMainWindow{parent} {
    setWindowTitle(tr("Przeglądanie grafików roboczych"));
    pPrzegladanieGrafikowRoboczych = p;
    mainWidget = new QWidget(this);

    labelMiesiac = new QLabel(tr("Miesiąc:"), this);
    labelRok = new QLabel(tr("Rok"), this);
    comboDniTygodnia = new QComboBox(this);
    //editMiesiac = new QLineEdit(this);
    editRok = new QLineEdit(this);
    buttonSzukaj = new QPushButton(tr("Szukaj grafików"), this);
    groupMiesiacRok = new QGroupBox(tr("Wyszukiwanie grup grafików"), this);
    layoutGroup = new QGridLayout(this);
    layoutGroup->addWidget(labelMiesiac, 0, 0);
    layoutGroup->addWidget(comboDniTygodnia, 0, 1);
    //layoutGroup->addWidget(editMiesiac, 0, 1);
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

    tableGrafik = new QTableWidget(0, 3, this);
    QStringList etykiety;
    etykiety << "#" << "Dzień tygodnia" << "Dyżurant";
    tableGrafik->setHorizontalHeaderLabels(etykiety);
    tableGrafik->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableGrafik->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableGrafik->setSelectionMode(QAbstractItemView::SingleSelection);        
    buttonUsun = new QPushButton(tr("Usuń ten grafik"), this);
    buttonClose = new QPushButton(tr("Zamknij"), this);
    buttonUsun->setEnabled(false);
    buttonUsunWszystko = new QPushButton(tr("Usuń WSZYSTKIE grafiki z danego miesiąca i danego roku"), this);
    buttonUsunWszystko->setEnabled(false);
    buttonKlepnijGrafik = new QPushButton(tr("Klepnij grafik jako aktualny"), this);
    buttonKlepnijGrafik->setEnabled(false);
    buttonDrukujPDF = new QPushButton(tr("Zapiszj ten grafik jako PDF"), this);
    buttonDrukujPDF->setEnabled(false);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(groupMiesiacRok);
    mainLayout->addLayout(layoutChoice);
    mainLayout->addWidget(tableGrafik);
    mainLayout->addWidget(buttonDrukujPDF);
    mainLayout->addWidget(buttonKlepnijGrafik);
    mainLayout->addWidget(buttonUsun);
    mainLayout->addWidget(buttonUsunWszystko);
    mainLayout->addWidget(buttonClose);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
    setFixedSize(600, 800);

    QObject::connect(buttonSzukaj, SIGNAL(clicked()), this, SLOT(onButtonSzukajClicked()));
    QObject::connect(buttonLeft, SIGNAL(clicked()), this, SLOT(onButtonLeftClicked()));
    QObject::connect(buttonRight, SIGNAL(clicked()), this, SLOT(onButtonRightClicked()));
    QObject::connect(buttonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));
    QObject::connect(buttonUsun, SIGNAL(clicked()), this, SLOT(onButtonUsunClicked()));
    QObject::connect(buttonUsunWszystko, SIGNAL(clicked()), this, SLOT(onButtonUsunWszystkoClicked()));
    QObject::connect(buttonKlepnijGrafik, SIGNAL(clicked()), this, SLOT(onButtonKlepnijGrafikClicked()));
    QObject::connect(buttonDrukujPDF, SIGNAL(clicked()), this, SLOT(onButtonZapiszJakoPDFClicked()));

    tablicaMiesiecy = {STYCZEN, LUTY, MARZEC, KWIECIEN, MAJ, CZERWIEC, LIPIEC, SIERPIEN, WRZESIEN, PAZDZIERNIK, LISTOPAD, GRUDZIEN};
    for (auto it=tablicaMiesiecy.begin(); it<tablicaMiesiecy.end(); ++it) {
        comboDniTygodnia->addItem(translateEnumToQString(*it));
    }
}

QString UIPrzegladanieGrafikowRoboczych::translateEnumToQString(Miesiac m) {
    QString s("");
    switch (m) {
    case STYCZEN: s = tr("Styczeń"); break;
    case LUTY: s = tr("Luty"); break;
    case MARZEC: s = tr("Marzec"); break;
    case KWIECIEN: s = tr("Kwiecień"); break;
    case MAJ: s = tr("Maj"); break;
    case CZERWIEC: s = tr("Czerwiec"); break;
    case LIPIEC: s = tr("Lipiec"); break;
    case SIERPIEN: s = tr("Sierpień"); break;
    case WRZESIEN: s = tr("Wrzesień"); break;
    case PAZDZIERNIK: s = tr("Październik"); break;
    case LISTOPAD: s = tr("Listopad"); break;
    case GRUDZIEN: s = tr("Grudzień"); break;
    default: s = tr("NIEZNANY_MIESIĄC"); break;
    }
    return s;
}

void UIPrzegladanieGrafikowRoboczych::onButtonSzukajClicked() {
    bool result2(false);
    int miesiac = comboDniTygodnia->currentIndex() + 1;
    //int miesiac = editMiesiac->text().toInt(&result1);
    int rok = editRok->text().toInt(&result2);
    if (!(result2)) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nieprawidłowe dane!"), QMessageBox::Ok);
        return;
    }
    int number(-1);
    number = pPrzegladanieGrafikowRoboczych->wybranoSzukanieGrafikow(miesiac, rok);
    labelNumber->setText("0 / " + QString::number(number));
    if (number >= 0) {
        buttonUsunWszystko->setEnabled(true);
    }
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
    tableGrafik->setRowCount(0);
}

void UIPrzegladanieGrafikowRoboczych::onButtonUsunWszystkoClicked() {
    bool result = pPrzegladanieGrafikowRoboczych->wybranoUsuniecieWszystkichGrafikow();
    if (!result) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nie udało się usunąć grafików. Być może grafiki nie zostały nawet wybrane."), QMessageBox::Ok);
        return;
    }
    labelNumber->setText(tr("BRAK"));
    tableGrafik->setRowCount(0);
    buttonLeft->setEnabled(false);
    buttonRight->setEnabled(false);
    buttonUsun->setEnabled(false);
    buttonDrukujPDF->setEnabled(false);
    buttonUsunWszystko->setEnabled(false);
    QMessageBox::information(this, tr("Informacja"), tr("Usunięto WSZYSTKIE grafiki z danego miesiąca i danego roku."), QMessageBox::Ok);
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
    if (!czyCosZostaje) {
        buttonUsun->setEnabled(false);
        buttonDrukujPDF->setEnabled(false);
        buttonKlepnijGrafik->setEnabled(false);
    }
    else {
        buttonUsun->setEnabled(true);
        buttonDrukujPDF->setEnabled(true);
        buttonKlepnijGrafik->setEnabled(true);
    }
}

void UIPrzegladanieGrafikowRoboczych::onButtonZapiszJakoPDFClicked() {
    QString filename = QFileDialog::getSaveFileName(this, tr("Wybierz miejsce i nazwę pliku PDF"), "C:\\", tr("Dokumenty PDF (*.pdf)"));
    if (filename.isEmpty()) {
        return;
    }
    bool result = pPrzegladanieGrafikowRoboczych->zapiszJakoPDF(filename);
    if (!result) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nie udało się zapisać jako PDF"), QMessageBox::Ok);
        return;
    }
    QMessageBox::information(this, tr("Informacja"), tr("Pomyślnie zapisano grafik jako PDF"), QMessageBox::Ok);
}

void UIPrzegladanieGrafikowRoboczych::onButtonLeftClicked() {
    tableGrafik->setRowCount(0);
    XWyswietlanyGrafik* grafikDoWyswietlenia(nullptr);
    int ktory(-1), ileWszystkich(-1);
    grafikDoWyswietlenia = pPrzegladanieGrafikowRoboczych->wybranoGrafikWLewo(ktory, ileWszystkich);
    if (grafikDoWyswietlenia == nullptr || grafikDoWyswietlenia->listaPozycjiGrafiku == nullptr) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nie udało się wyświetlić grafiku."), QMessageBox::Ok);
        return;
    }
    labelNumber->setText(QString::number(ktory) + " / " + QString::number(ileWszystkich));
    int licznikWierszy(0);
    
    QTableWidgetItem* twitem(nullptr);    
    QFont fontForWeekend;
    fontForWeekend.setBold(true);
    
    for (auto it = grafikDoWyswietlenia->listaPozycjiGrafiku->begin(); it < grafikDoWyswietlenia->listaPozycjiGrafiku->end(); ++it) {
        tableGrafik->insertRow(licznikWierszy);
        tableGrafik->setItem(licznikWierszy, 0, new QTableWidgetItem((*it)->dzien));
        tableGrafik->setItem(licznikWierszy, 1, new QTableWidgetItem((*it)->dzienTygodnia));
        tableGrafik->setItem(licznikWierszy, 2, new QTableWidgetItem((*it)->dyzurant));
        
        if ((*it)->dzienTygodnia == "niedziela" || (*it)->dzienTygodnia == "sobota") {
            for (int i=0; i<3; ++i) {
                twitem = tableGrafik->item(licznikWierszy, i);
                twitem->setFont(fontForWeekend);
            }
        }
        
        licznikWierszy++;
    }
    buttonKlepnijGrafik->setEnabled(true);
    buttonDrukujPDF->setEnabled(true);
}

void UIPrzegladanieGrafikowRoboczych::wyswietlKonkretnyGrafik(XWyswietlanyGrafik* grafikDoWyswietlenia, int ktory, int ileWszystkich) {
    tableGrafik->setRowCount(0);
    if (grafikDoWyswietlenia->listaPozycjiGrafiku == nullptr) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nie udało się wyświetlić grafiku."), QMessageBox::Ok);
        return;
    }
    labelNumber->setText(QString::number(ktory) + " / " + QString::number(ileWszystkich));
    int licznikWierszy(0);
    for (auto it = grafikDoWyswietlenia->listaPozycjiGrafiku->begin(); it < grafikDoWyswietlenia->listaPozycjiGrafiku->end(); ++it) {
        tableGrafik->insertRow(licznikWierszy);
        tableGrafik->setItem(licznikWierszy, 0, new QTableWidgetItem((*it)->dzien));
        tableGrafik->setItem(licznikWierszy, 1, new QTableWidgetItem((*it)->dzienTygodnia));
        tableGrafik->setItem(licznikWierszy, 2, new QTableWidgetItem((*it)->dyzurant));
        licznikWierszy++;
    }    
    buttonKlepnijGrafik->setEnabled(true);
    buttonDrukujPDF->setEnabled(true);
}
    
void UIPrzegladanieGrafikowRoboczych::onButtonRightClicked() {
    tableGrafik->setRowCount(0);
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
        tableGrafik->insertRow(licznikWierszy);
        tableGrafik->setItem(licznikWierszy, 0, new QTableWidgetItem((*it)->dzien));
        tableGrafik->setItem(licznikWierszy, 1, new QTableWidgetItem((*it)->dzienTygodnia));
        tableGrafik->setItem(licznikWierszy, 2, new QTableWidgetItem((*it)->dyzurant));
        licznikWierszy++;
    }
    buttonKlepnijGrafik->setEnabled(true);
    buttonDrukujPDF->setEnabled(true);
}

void UIPrzegladanieGrafikowRoboczych::onButtonKlepnijGrafikClicked() {
    bool result = pPrzegladanieGrafikowRoboczych->wybranoKlepniecieGrafiku();
    if (!result) {
        QMessageBox::critical(this, tr("Błąd"), tr("Przyklepanie grafiku nie udało się. Być może już jakiś wcześniej został klepnięty."), QMessageBox::Ok);
        return;
    }
    QMessageBox::information(this, tr("Informacja"), tr("Pomyślnie przyklepano grafik jako aktualny. Teraz możesz usunąć wszystkie z danego miesiąca i danego roku"), QMessageBox::Ok);
}
    
void UIPrzegladanieGrafikowRoboczych::onButtonCloseClicked() {
    close();
}

