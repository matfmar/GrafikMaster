
#include "uidodawanienowegografikuwstep.h"
#include "pdodawanienowegografiku.h"
#include "dto.h"
#include <QMessageBox>

UIDodawanieNowegoGrafikuWstep::UIDodawanieNowegoGrafikuWstep(std::vector<Miesiac> tM, std::vector<DzienTygodnia> tDT, PDodawanieNowegoGrafiku* pd) {
    setWindowTitle(tr("Dane nowego grafiku"));
    pDodawanieNowegoGrafiku = pd;
    tablicaMiesiecy = tM;
    tablicaDniTygodnia = tDT;

    labelRok = new QLabel(tr("Rok:"), this);
    editRok = new QLineEdit(this);
    labelMiesiac = new QLabel(tr("Miesiąc:"), this);
    boxMiesiac = new QComboBox(this);
    labelLiczbaDni = new QLabel(tr("Liczba dni:"), this);
    editLiczbaDni = new QLineEdit(this);
    labelPierwszyDzien = new QLabel(tr("Pierwszy dzień miesiąca:"), this);
    boxPierwszyDzien = new QComboBox(this);
    buttonDodaj = new QPushButton(tr("Dalej"), this);
    buttonAnuluj = new QPushButton(tr("Anuluj"), this);
    labelSwieta = new QLabel(tr("Dni świąteczne:"), this);
    editSwieta = new QLineEdit(this);
    buttonZapisz = new QPushButton(tr("Zapamiętaj te parametry"), this);
    buttonWczytaj = new QPushButton(tr("Wczytaj zapamiętane parametry"), this);

    gridLayout = new QGridLayout(this);
    gridLayout -> addWidget(labelRok, 0, 0);
    gridLayout -> addWidget(editRok, 0, 1);
    gridLayout -> addWidget(labelMiesiac, 1, 0);
    gridLayout -> addWidget(boxMiesiac, 1, 1);
    gridLayout -> addWidget(labelLiczbaDni, 2, 0);
    gridLayout -> addWidget(editLiczbaDni, 2, 1);
    gridLayout -> addWidget(labelPierwszyDzien, 3, 0);
    gridLayout -> addWidget(boxPierwszyDzien, 3, 1);
    gridLayout -> addWidget(labelSwieta, 4, 0);
    gridLayout -> addWidget(editSwieta, 4, 1);
    gridLayout -> addWidget(buttonDodaj, 6, 0);
    gridLayout -> addWidget(buttonAnuluj, 6, 1);
    gridLayout -> addWidget(buttonZapisz, 7, 0);
    gridLayout -> addWidget(buttonWczytaj, 8, 0);
    setLayout(gridLayout);

    QObject::connect(buttonDodaj, SIGNAL(clicked()), this, SLOT(onButtonDodajClicked()));
    QObject::connect(buttonAnuluj, SIGNAL(clicked()), this, SLOT(onButtonAnulujClicked()));
    QObject::connect(buttonZapisz, SIGNAL(clicked()), this, SLOT(onButtonZapiszClicked()));
    QObject::connect(buttonWczytaj, SIGNAL(clicked()), this, SLOT(onButtonWczytajClicked()));

    for (auto it = tM.begin(); it<tM.end(); ++it) {
        boxMiesiac -> addItem(translateEnumToQString(*it));
    }

    for (auto it = tDT.begin(); it<tDT.end(); ++it) {
        boxPierwszyDzien -> addItem(translateEnumToQString(*it));
    }

}

QString UIDodawanieNowegoGrafikuWstep::translateEnumToQString(Miesiac m) {
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

QString UIDodawanieNowegoGrafikuWstep::translateEnumToQString(DzienTygodnia dt) {
    QString s("");
    switch (dt) {
        case PONIEDZIALEK: s = tr("Poniedziałek"); break;
        case WTOREK: s = tr("Wtorek"); break;
        case SRODA: s = tr("Środa"); break;
        case CZWARTEK: s = tr("Czwartek"); break;
        case PIATEK: s = tr("Piątek"); break;
        case SOBOTA: s = tr("Sobota"); break;
        case NIEDZIELA: s = tr("Niedziela"); break;
        default: s = "NIEZNANY_DZIEŃ"; break;
    }
    return s;
}

void UIDodawanieNowegoGrafikuWstep::onButtonZapiszClicked() {
    QString editRokString = editRok->text();    //1. wiersz
    QString liczbaDniString = editLiczbaDni->text();      //2. wiersz
    int boxMiesiacIndex = boxMiesiac->currentIndex();    //3. wiersz
    int boxPierwszyDzienIndex = boxPierwszyDzien->currentIndex();    //4. wiersz
    QString editSwietaString = editSwieta->text();    //5. wiersz
    std::vector<QString> daneDoZapisu;
    daneDoZapisu.push_back(editRokString);
    daneDoZapisu.push_back(liczbaDniString);
    daneDoZapisu.push_back(QString::number(boxMiesiacIndex));
    daneDoZapisu.push_back(QString::number(boxPierwszyDzienIndex));
    daneDoZapisu.push_back(editSwietaString);
    bool result = pDodawanieNowegoGrafiku->wybranoZapisanieParametrowGrafiku(daneDoZapisu);
    if (!result) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nie udano się zapisać danych."), QMessageBox::Ok);
    }
    else {
        QMessageBox::information(this, tr("Informacja"), tr("Pomyślnie zachowano dane."), QMessageBox::Ok);
    }
}

void UIDodawanieNowegoGrafikuWstep::onButtonWczytajClicked() {
    bool result(false);
    std::vector<QString> daneWczytane = pDodawanieNowegoGrafiku->wybranoWczytanieParametrowGrafiku(result);
    if (!result) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nie udało się wczytać danych."), QMessageBox::Ok);
        return;
    }
    editRok->setText(daneWczytane[0]);
    editLiczbaDni->setText(daneWczytane[1]);
    boxMiesiac->setCurrentIndex(daneWczytane[2].toInt());
    boxPierwszyDzien->setCurrentIndex(daneWczytane[3].toInt());
    editSwieta->setText(daneWczytane[4]);
}

void UIDodawanieNowegoGrafikuWstep::onButtonDodajClicked() {
    int ret(0);
    if (editRok->text().isEmpty() || editLiczbaDni->text().isEmpty()) {
        ret = QMessageBox::critical(this, tr("Błąd"), tr("Za mało danych!"), QMessageBox::Ok);
        return;
    }
    bool result(false);
    int rok = editRok->text().toInt(&result);
    if (!result) {
        ret = QMessageBox::critical(this, tr("Błąd"), tr("Zły rok!"), QMessageBox::Ok);
        return;
    }
    int liczbaDni(0);
    liczbaDni = editLiczbaDni->text().toInt(&result);
    if ((!result) || ((liczbaDni < 28) || (liczbaDni > 31))) {
        ret = QMessageBox::critical(this, tr("Błąd"), tr("Zła liczba dni!"), QMessageBox::Ok);
        return;
    }
    Miesiac miesiac = tablicaMiesiecy[boxMiesiac->currentIndex()];
    DzienTygodnia pierwszyDzien = tablicaDniTygodnia[boxPierwszyDzien->currentIndex()];
    QString listaSwiat = editSwieta->text();
    bool resultDodaniaWstepnego(false);
    pDodawanieNowegoGrafiku ->wybranoDodanieInformacjiWstepnychNowegoGrafiku(rok, liczbaDni, miesiac, pierwszyDzien, listaSwiat, resultDodaniaWstepnego);
    if (!resultDodaniaWstepnego) {
        QMessageBox::critical(this, tr("Błąd"), tr("Wprowadzono nieprawidłowo dane dotyczące świąt."), QMessageBox::Ok);
        return;
    }
}

void UIDodawanieNowegoGrafikuWstep::onButtonAnulujClicked() {
    close();
}
