
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
    void startTimerTC();
    void stopTimerTC();
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
