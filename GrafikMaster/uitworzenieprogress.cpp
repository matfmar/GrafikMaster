
#include "uitworzenieprogress.h"
#include "pprogress.h"

UITworzenieProgress::UITworzenieProgress(PProgress* p) {
    parent = p;

    layout = new QVBoxLayout(this);
    labelTekst = new QLabel(tr("Ilość utworzonych grafików: "), this);
    labelIleGrafikow = new QLabel(tr("0"), this);
    labelTekstObroty = new QLabel(tr("Ilość wykonanych obrotów: "), this);
    labelIleObrotow = new QLabel(tr("0"), this);
    layout->addWidget(labelTekst);
    layout->addWidget(labelIleGrafikow);
    layout->addWidget(labelTekstObroty);
    layout->addWidget(labelIleObrotow);
    setLayout(layout);
}

void UITworzenieProgress::setLabelIleGrafikow(int ileGrafikow) {
    labelIleGrafikow->setText(QString::number(ileGrafikow));
}

void UITworzenieProgress::setLabelIleObrotow(int ileObrotow) {
    labelIleObrotow->setText(QString::number(ileObrotow));
}
