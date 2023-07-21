
#include "ttimerthread.h"

TTimerThread::TTimerThread(QObject *parent)
    : QThread{parent}
{

}

void TTimerThread::run() {
    QThread::exec();
}

