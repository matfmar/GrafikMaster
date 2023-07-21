
#ifndef TTIMERCLASS_H
#define TTIMERCLASS_H


#include <QObject>
#include <QTimer>

class TTimerClass : public QObject
{
    Q_OBJECT
public:
    explicit TTimerClass(QObject *parent = nullptr);
    ~TTimerClass();
    void startTimer();
    void stopTimer();
public slots:
    void timeFinishedSlot();
    //do obsługi QThread
    void process();
signals:
    void timeFinishedSignal();
    //do obsługi QThread
    void finished();
private:
    QTimer* timer;


};

#endif // TTIMERCLASS_H
