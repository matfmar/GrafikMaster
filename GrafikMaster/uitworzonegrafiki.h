
#ifndef UITWORZONEGRAFIKI_H
#define UITWORZONEGRAFIKI_H


#include <QMainWindow>
#include <QHBoxLayout>
#include <QListWidget>
#include <QString>
#include <map>

class XGrafik;
class XDyzurantTworzacy;

class UITworzoneGrafiki : public QMainWindow {
    Q_OBJECT
public:
    UITworzoneGrafiki(XGrafik* g, QWidget *parent = nullptr);
    ~UITworzoneGrafiki() {}
private:
    QWidget* mainWidget;
    QHBoxLayout* mainLayout;
    QListWidget* listaOstateczni,* listaMozliwi,* listaUnikajacy,* listaMozliwiNieUnikajacy;
    XGrafik* grafik;

    QString zwrocLancuchWynikowy(std::map<int, XDyzurantTworzacy*> mapa);
    QString zwrocDyzurantaOstatecznego(XDyzurantTworzacy* dt);
};

#endif // UITWORZONEGRAFIKI_H
