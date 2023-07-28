
#include "uitworzenieprogress.h"
#include "pprogress.h"

UITworzenieProgress::UITworzenieProgress(PProgress* p) {
    parent = p;

    layout = new QVBoxLayout(this);
    labelTekst = new QLabel(tr("Ilość utworzonych grafików: "), this);
    labelIleGrafikow = new QLabel(tr("0"), this);
    labelTekstObroty = new QLabel(tr("Ilość wykonanych obrotów: "), this);
    labelIleObrotow = new QLabel(tr("0"), this);
    buttonZakoncz = new QPushButton(tr("Zakończ szukanie"), this);
    layout->addWidget(labelTekst);
    layout->addWidget(labelIleGrafikow);
    layout->addWidget(labelTekstObroty);
    layout->addWidget(labelIleObrotow);
    layout->addWidget(buttonZakoncz);
    setLayout(layout);

    QObject::connect(buttonZakoncz, SIGNAL(clicked()), this, SLOT(onButtonZakonczClicked()));
}

void UITworzenieProgress::setLabelIleGrafikow(int ileGrafikow) {
    labelIleGrafikow->setText(QString::number(ileGrafikow));
}

void UITworzenieProgress::setLabelIleObrotow(int ileObrotow) {
    labelIleObrotow->setText(QString::number(ileObrotow));
}

void UITworzenieProgress::onButtonZakonczClicked() {
    emit buttonZakonczClicked();
}
