
#include "uitworzenieprogress.h"
#include "pprogress.h"

UITworzenieProgress::UITworzenieProgress(PProgress* p) {
    parent = p;

    layout = new QVBoxLayout(this);
    labelTekst = new QLabel(tr("Ilość utworzonych grafików: "), this);
    labelIleGrafikow = new QLabel(tr("0"), this);
    layout->addWidget(labelTekst);
    layout->addWidget(labelIleGrafikow);
    setLayout(layout);
}

void UITworzenieProgress::setLabelIleGrafikow(int ileGrafikow) {
    labelIleGrafikow->setText(QString::number(ileGrafikow));
}
