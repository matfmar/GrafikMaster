
#include "uidodawanienowegografikuwstep.h"
#include "pdodawanienowegografiku.h"
#include "dto.h"

UIDodawanieNowegoGrafikuWstep::UIDodawanieNowegoGrafikuWstep(std::vector<Miesiac> tM, std::vector<DzienTygodnia> tDT, PDodawanieNowegoGrafiku* pd) {
    setWindowTitle(tr("Dane nowego grafiku"));
    pDodawanieNowegoGrafiku = pd;

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

    gridLayout = new QGridLayout(this);
    gridLayout -> addWidget(labelRok, 0, 0);
    gridLayout -> addWidget(editRok, 0, 1);
    gridLayout -> addWidget(labelMiesiac, 1, 0);
    gridLayout -> addWidget(boxMiesiac, 1, 1);
    gridLayout -> addWidget(labelLiczbaDni, 2, 0);
    gridLayout -> addWidget(editLiczbaDni, 2, 1);
    gridLayout -> addWidget(labelPierwszyDzien, 3, 0);
    gridLayout -> addWidget(boxPierwszyDzien, 3, 1);
    gridLayout -> addWidget(buttonDodaj, 5, 0);
    gridLayout -> addWidget(buttonAnuluj, 5, 1);
    setLayout(gridLayout);

    QObject::connect(buttonDodaj, SIGNAL(clicked()), this, SLOT(onButtonDodajClicked()));
    QObject::connect(buttonAnuluj, SIGNAL(clicked()), this, SLOT(onButtonAnulujClicked()));

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

void UIDodawanieNowegoGrafikuWstep::onButtonDodajClicked() {

}

void UIDodawanieNowegoGrafikuWstep::onButtonAnulujClicked() {
    close();
}
