
#ifndef PPROGRESS_H
#define PPROGRESS_H


#include <QObject>
#include <QSemaphore>

class UITworzenieProgress;
class PDecydowanieOKontynuacjiSzukaniaGrafikow;

class PProgress : public QObject
{
    Q_OBJECT
public:
    explicit PProgress(QSemaphore* sem, QSemaphore* sem2, QSemaphore* sem3, QObject *parent = nullptr);
    ~PProgress();
    void pokazOknoProgress();
public slots:
    void setLabelOknoProgress(int ileGrafikow);
    void setLabelObrotyOknoProgress(int ileObrotow);
    void przymknijOknoProgress();
    void showOknoProgress();
    void killOknoProgress();
    void showAskWindow(int* result);
    void showEndCommunicate(bool result, int ile);
private:
    //okno do pokazywania progresu
    UITworzenieProgress* uiTworzenieProgress;
    //prezenter do decydowania o kontynuacji tworzenia grafikow
    PDecydowanieOKontynuacjiSzukaniaGrafikow* pDecydowanieOKontynuacjiSzukaniaGrafikow;
    QSemaphore* semafor,* semafor2,* semaforLabel;
};

#endif // PPROGRESS_H
