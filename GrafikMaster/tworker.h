
#ifndef TWORKER_H
#define TWORKER_H


#include <QObject>
#include <vector>
#include <QSemaphore>

class XGrafik;
class XDyzurantTworzacy;

class TWorker : public QObject
{
    Q_OBJECT
public:
    TWorker(XGrafik* g, std::vector<XDyzurantTworzacy*>* tdt, int ile, QSemaphore* sem, QSemaphore* sem2, QObject* parent = nullptr);
    ~TWorker();
    //wywoływane przez obiekty XGrafik  - poniższe funkcje wysyłają odpowiednie sygnały
    void pokazLiczbeInteracji(int a);
    void pokazOknoProgresu();
    void przymknijOknoProgresu();
    int zapytajOKontynuacje();
    void pokazKomunikatZakonczeniaSzukania(bool wynikTworzeniaGrafikow, int ileGrafikow);
public slots:
    void process();
signals:
    //do obsługi QThread
    void finished();
    void error(QString err);
    //do komunikacji z progress managerem
    void sendInt(int);
    void hideProgressWindow();
    void showProgressWindow();
    void killProgressWindow();
    void showAskWindow(int*);
    void showEndCommunicate(bool, int);
private:
    XGrafik* grafikBazowy;
    std::vector<XDyzurantTworzacy*>* tablicaDyzurantowTworzacych;
    int ileIteracji;
    QSemaphore* semafor,* semafor2;
    int* result;

};

#endif // TWORKER_H
