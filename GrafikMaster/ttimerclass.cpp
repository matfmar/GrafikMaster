
#include "ttimerclass.h"
#include <QThread>

TTimerClass::TTimerClass(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timeFinishedSlot()));
}

void TTimerClass::process() {

}

void TTimerClass::startTimerTC() {
    timer->start(3000);         //na 3 sekundy, UWAGA: ta funkcja restartuje, jeśli timer już był aktywny
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
