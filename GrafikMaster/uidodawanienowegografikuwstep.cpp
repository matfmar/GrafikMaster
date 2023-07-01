
#include "uidodawanienowegografikuwstep.h"
#include "pdodawanienowegografiku.h"

UIDodawanieNowegoGrafikuWstep::UIDodawanieNowegoGrafikuWstep(PDodawanieNowegoGrafiku* pd) {
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

}

void UIDodawanieNowegoGrafikuWstep::onButtonDodajClicked() {

}

void UIDodawanieNowegoGrafikuWstep::onButtonAnulujClicked() {
    close();
}
