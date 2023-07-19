
#include "pprogress.h"
#include "uitworzenieprogress.h"

PProgress::PProgress()
    : uiTworzenieProgress(nullptr) {
    uiTworzenieProgress = new UITworzenieProgress(this);
}

void PProgress::pokazOknoProgress() {
    if (uiTworzenieProgress != nullptr) {
        uiTworzenieProgress->show();
    }
    else {
        uiTworzenieProgress = new UITworzenieProgress(this);
        uiTworzenieProgress->show();
    }
}

void PProgress::setLabelOknoProgress(int ileGrafikow) {
    uiTworzenieProgress->setLabelIleGrafikow(ileGrafikow);
}

void PProgress::zamknijOknoProgress() {
    delete uiTworzenieProgress;
    uiTworzenieProgress = nullptr;
}

PProgress::~PProgress() {
    if (uiTworzenieProgress != nullptr) {
        delete uiTworzenieProgress;
        uiTworzenieProgress = nullptr;
    }
}

