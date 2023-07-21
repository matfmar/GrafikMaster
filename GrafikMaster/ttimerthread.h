
#ifndef TTIMERTHREAD_H
#define TTIMERTHREAD_H

#include <QThread>
#include <QTimer>


class TTimerThread : public QThread
{
public:
    explicit TTimerThread(QObject *parent = nullptr);
    void run();
};

#endif // TTIMERTHREAD_H
