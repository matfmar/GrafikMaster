
#include "uiprzegladaniegrafikowostatecznych.h"
#include "pprzegladaniegrafikowostatecznych.h"
#include <QMessageBox>
#include <QStringList>
#include "dto.h"
#include <QFont>
#include <QFileDialog>

UIPrzegladanieGrafikowOstatecznych::UIPrzegladanieGrafikowOstatecznych(PPrzegladanieGrafikowOstatecznych* p, QWidget *parent)
    : QMainWindow{parent}
{
    setWindowTitle(tr("Przeglądanie grafików ostatecznych"));
    pPrzegladanieGrafikowOstatecznych = p;
    mainWidget = new QWidget(this);

    labelMiesiac = new QLabel(tr("Miesiąc:"), this);
    labelRok = new QLabel(tr("Rok"), this);
    comboDniTygodnia = new QComboBox(this);
    editRok = new QLineEdit(this);
    buttonSzukaj = new QPushButton(tr("Szukaj grafików"), this);
    groupMiesiacRok = new QGroupBox(tr("Wyszukiwanie grup grafików"), this);
    layoutGroup = new QGridLayout(this);
    layoutGroup->addWidget(labelMiesiac, 0, 0);
    layoutGroup->addWidget(comboDniTygodnia, 0, 1);
    layoutGroup->addWidget(labelRok, 1, 0);
    layoutGroup->addWidget(editRok, 1, 1);
    layoutGroup->addWidget(buttonSzukaj, 2, 0);
    groupMiesiacRok->setLayout(layoutGroup);

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
    buttonDrukujPDF = new QPushButton(tr("Zapisz ten grafik jako PDF"), this);
    buttonDrukujPDF->setEnabled(false);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(groupMiesiacRok);
    mainLayout->addWidget(tableGrafik);
    mainLayout->addWidget(buttonDrukujPDF);
    mainLayout->addWidget(buttonUsun);
    mainLayout->addWidget(buttonClose);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    QObject::connect(buttonSzukaj, SIGNAL(clicked()), this, SLOT(onButtonSzukajClicked()));
    QObject::connect(buttonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));
    QObject::connect(buttonUsun, SIGNAL(clicked()), this, SLOT(onButtonUsunClicked()));
    QObject::connect(buttonDrukujPDF, SIGNAL(clicked()), this, SLOT(onButtonZapiszJakoPDFClicked()));

    tablicaMiesiecy = {STYCZEN, LUTY, MARZEC, KWIECIEN, MAJ, CZERWIEC, LIPIEC, SIERPIEN, WRZESIEN, PAZDZIERNIK, LISTOPAD, GRUDZIEN};
    for (auto it=tablicaMiesiecy.begin(); it<tablicaMiesiecy.end(); ++it) {
        comboDniTygodnia->addItem(translateEnumToQString(*it));
    }
}

QString UIPrzegladanieGrafikowOstatecznych::translateEnumToQString(Miesiac m) {
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

void UIPrzegladanieGrafikowOstatecznych::onButtonSzukajClicked() {
    bool result2(false);
    int miesiac = comboDniTygodnia->currentIndex() + 1;
    int rok = editRok->text().toInt(&result2);
    if (!(result2)) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nieprawidłowe dane!"), QMessageBox::Ok);
        return;
    }
    int number(-1);
    number = pPrzegladanieGrafikowOstatecznych->wybranoSzukanieGrafikow(miesiac, rok);
}

/*void UIPrzegladanieGrafikowOstatecznych::ableUsunButton(bool how) {
    buttonUsun->setEnabled(how);
}*/

void UIPrzegladanieGrafikowOstatecznych::wyczyscTabele() {
    tableGrafik->setRowCount(0);
}

void UIPrzegladanieGrafikowOstatecznych::onButtonUsunClicked() {
    bool result = pPrzegladanieGrafikowOstatecznych->wybranoUsuniecieGrafiku();
    if (!result) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nie udało się usunąć grafiku. Być może grafik nie został nawet wybrany."), QMessageBox::Ok);
        return;
    }
    QMessageBox::information(this, tr("Informacja"), tr("Usunięto dany grafik"), QMessageBox::Ok);
    wyczyscTabele();
    buttonUsun->setEnabled(false);
    buttonDrukujPDF->setEnabled(false);
}

void UIPrzegladanieGrafikowOstatecznych::onButtonZapiszJakoPDFClicked() {
    QString filename = QFileDialog::getSaveFileName(this, tr("Wybierz miejsce i nazwę pliku PDF"), "C:\\", tr("Dokumenty PDF (*.pdf)"));
    if (filename.isEmpty()) {
        return;
    }
    bool result = pPrzegladanieGrafikowOstatecznych->zapiszJakoPDF(filename);
    if (!result) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nie udało się zapisać jako PDF"), QMessageBox::Ok);
        return;
    }
    QMessageBox::information(this, tr("Informacja"), tr("Pomyślnie zapisano grafik jako PDF"), QMessageBox::Ok);
}

void UIPrzegladanieGrafikowOstatecznych::wyswietlKonkretnyGrafik(XWyswietlanyGrafik* grafikDoWyswietlenia) {
    tableGrafik->setRowCount(0);
    if (grafikDoWyswietlenia->listaPozycjiGrafiku == nullptr) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nie udało się wyświetlić grafiku."), QMessageBox::Ok);
        return;
    }
    int licznikWierszy(0);
    for (auto it = grafikDoWyswietlenia->listaPozycjiGrafiku->begin(); it < grafikDoWyswietlenia->listaPozycjiGrafiku->end(); ++it) {
        tableGrafik->insertRow(licznikWierszy);
        tableGrafik->setItem(licznikWierszy, 0, new QTableWidgetItem((*it)->dzien));
        tableGrafik->setItem(licznikWierszy, 1, new QTableWidgetItem((*it)->dzienTygodnia));
        tableGrafik->setItem(licznikWierszy, 2, new QTableWidgetItem((*it)->dyzurant));
        licznikWierszy++;
    }
    buttonDrukujPDF->setEnabled(true);
    buttonUsun->setEnabled(true);
}


void UIPrzegladanieGrafikowOstatecznych::onButtonCloseClicked() {
    close();
}
