
#ifndef TWORKER_H
#define TWORKER_H


#include <QObject>
#include <vector>
#include <QSemaphore>
#include <QMutex>
#include <QTimer>

class XGrafik;
class XDyzurantTworzacy;
class TTimerClass;
class TTimerThread;

class TWorker : public QObject
{
    Q_OBJECT
public:
    TWorker(XGrafik* g, std::vector<XDyzurantTworzacy*>* tdt, int ile, QSemaphore* sem, QSemaphore* sem2, QSemaphore* sem3, int szybkosc,  bool skracaniePomimoUlozenia, QObject* parent = nullptr);
    ~TWorker();
    //wywoływane przez obiekty XGrafik  - poniższe funkcje wysyłają odpowiednie sygnały
    void pokazLiczbeInteracji(int a);
    void pokazLiczbeObrotow(int a);
    void pokazOknoProgresu();
    void przymknijOknoProgresu();
    int zapytajOKontynuacje(int ileGrafikow);
    void pokazKomunikatZakonczeniaSzukania(bool wynikTworzeniaGrafikow, int ileGrafikow);
    void startTimerX();
    void stopTimerX();

public slots:
    //do obslugi QThread
    void process();
    //do obslugi QTimer
    void timePassed();
    void zasygnalizowanoZakonczenieTworzenia();
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
    void showAskWindow(int*, int);
    void showEndCommunicate(bool, int);
    //do komunikacji z TimerClass
    void startTheTimer();
    void stopTheTimer();
private:
    int szybkosc;
    XGrafik* grafikBazowy;
    std::vector<XDyzurantTworzacy*>* tablicaDyzurantowTworzacych;
    int ileIteracji;
    QSemaphore* semafor,* semafor2,* semaforLabel;
    int* result;
    QMutex* mutexWymuszenieZakonczenia;
    bool* wymuszenieZakonczenia;

    TTimerClass* timerClass;
    TTimerThread* subThreadForTimer;
    bool* decyzjaOSkroceniu;
    int* licznikSkrocen;
    QMutex* mutex;      //do dostępu do informacji czy wychodzić z pętli czy nie
    QTimer* timer;

    int licznikPowtorzenDanegoSkrocenia;
    int aktualneSkrocenie;
    int licznikPetliSkrocen;
    bool skracanieZawsze;

    int obliczIloscSkrocen();

};

#endif // TWORKER_H
