
#ifndef TWORKER_H
#define TWORKER_H


#include <QObject>
#include <vector>
#include <QSemaphore>
#include <QThread>

class XGrafik;
class XDyzurantTworzacy;
class TTimerClass;

class TWorker : public QObject
{
    Q_OBJECT
public:
    TWorker(XGrafik* g, std::vector<XDyzurantTworzacy*>* tdt, int ile, QSemaphore* sem, QSemaphore* sem2, QSemaphore* sem3, int szybkosc, QObject* parent = nullptr);
    ~TWorker();
    //wywoływane przez obiekty XGrafik  - poniższe funkcje wysyłają odpowiednie sygnały
    void pokazLiczbeInteracji(int a);
    void pokazLiczbeObrotow(int a);
    void pokazOknoProgresu();
    void przymknijOknoProgresu();
    int zapytajOKontynuacje();
    void pokazKomunikatZakonczeniaSzukania(bool wynikTworzeniaGrafikow, int ileGrafikow);
    void startTimer();
public slots:
    //do obslugi QThread
    void process();
    //do obslugi QTimer
    void timePassed();
signals:
    //do obsługi QThread
    void finished();
    void error(QString err);
    //do komunikacji z progress managerem
    void sendInt(int);
    void sendIntObroty(int);
    void hideProgressWindow();
    void showProgressWindow();
    void killProgressWindow();
    void showAskWindow(int*);
    void showEndCommunicate(bool, int);
private:
    int szybkosc;
    XGrafik* grafikBazowy;
    std::vector<XDyzurantTworzacy*>* tablicaDyzurantowTworzacych;
    int ileIteracji;
    QSemaphore* semafor,* semafor2,* semaforLabel;
    int* result;

    TTimerClass* timerClass;
    QThread* subThreadForTimer;
    bool* decyzjaOSkroceniu;
    int* licznikSkrocen;

};

#endif // TWORKER_H
