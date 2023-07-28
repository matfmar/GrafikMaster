
#include "ttimerclass.h"

TTimerClass::TTimerClass(QObject *parent)
    : QObject{parent}
{
    timer = nullptr;
}

void TTimerClass::process() {
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timeFinishedSlot()));
}

void TTimerClass::startTimerTC() {
    timer->start(3000);         //na 3 sekundy, UWAGA: ta funkcja restartuje, jeśli timer już był aktywny
}

void TTimerClass::startTheTimerFromOutside() {
    timer->start(3000);
}

void TTimerClass::stopTheTimerFromOutside() {
    if (timer->isActive()) {
        timer->stop();
    }
}

void TTimerClass::stopTimerTC() {
    timer->stop();
}

void TTimerClass::timeFinishedSlot() {
    emit timeFinishedSignal();
}

TTimerClass::~TTimerClass() {
    if (timer != nullptr) {
        if (timer->isActive()) {
            timer->stop();
        }
        delete timer;
        timer = nullptr;
    }
}
