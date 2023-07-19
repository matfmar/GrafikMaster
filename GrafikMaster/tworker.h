
#ifndef TWORKER_H
#define TWORKER_H


#include <QObject>

class XGrafik;

class TWorker : public QObject
{
    Q_OBJECT
public:
    TWorker(XGrafik* g, QObject* parent = nullptr);
    ~TWorker() {}
public slots:
    void process() {}
signals:
    void finished();
    void error(QString err);
private:
    XGrafik* grafikBazowy;

};

#endif // TWORKER_H
