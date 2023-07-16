
#include "uiprzegladaniegrafikowroboczych.h"
#include "pprzegladaniegrafikowroboczych.h"
#include <QMessageBox>

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
    labelNumber = new QLabel(tr("0"), this);
    layoutChoice = new QHBoxLayout(this);
    layoutChoice->addWidget(buttonLeft);
    layoutChoice->addWidget(labelNumber);
    layoutChoice->addWidget(buttonRight);

    tableGrafik = new QTableWidget(31, 3, this);
    buttonClose = new QPushButton(tr("Zamknij"), this);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(groupMiesiacRok);
    mainLayout->addLayout(layoutChoice);
    mainLayout->addWidget(tableGrafik);
    mainLayout->addWidget(buttonClose);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    QObject::connect(buttonSzukaj, SIGNAL(clicked()), this, SLOT(onButtonSzukajClicked()));
    QObject::connect(buttonLeft, SIGNAL(clicked()), this, SLOT(onButtonLeftClicked()));
    QObject::connect(buttonRight, SIGNAL(clicked()), this, SLOT(onButtonRightClicked()));
    QObject::connect(buttonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));
            
}

void UIPrzegladanieGrafikowRoboczych::onButtonSzukajClicked() {
    bool result1(false), result2(false);
    int miesiac = editMiesiac->text().toInt(&result1);
    int rok = editRok->text().toInt(&result2);
    if (!(result1 && result2)) {
        QMessageBox::critical(this, tr("Błąd"), tr("Nieprawidłowe dane!"), QMessageBox::Ok);
        return;
    }
    pPrzegladanieGrafikowRoboczych->wybranoSzukanieGrafikow(miesiac, rok);
}
    
void UIPrzegladanieGrafikowRoboczych::onButtonLeftClicked() {
    
}
    
void UIPrzegladanieGrafikowRoboczych::onButtonRightClicked() {
    
}
    
void UIPrzegladanieGrafikowRoboczych::onButtonCloseClicked() {
    
}

