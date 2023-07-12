
#ifndef UITWORZONEGRAFIKI_H
#define UITWORZONEGRAFIKI_H


#include <QDialog>
#include <QGridLayout>
#include <QListWidget>
#include <QString>
#include <QPushButton>
#include <map>

class XGrafik;
class XDyzurantTworzacy;
class PDodawanieNowegoGrafiku;

class UITworzoneGrafiki : public QDialog {
    Q_OBJECT
public:
    UITworzoneGrafiki(XGrafik* g, PDodawanieNowegoGrafiku* p);
    ~UITworzoneGrafiki() {}
public slots:
    void onButtonOkClicked();
    void onButtonZleClicked();
private:
    QGridLayout* mainLayout;
    QListWidget* listaOstateczni,* listaMozliwi,* listaUnikajacy,* listaMozliwiNieUnikajacy;
    XGrafik* grafik;
    QPushButton* buttonOk,* buttonZle;
    PDodawanieNowegoGrafiku* parent;

    QString zwrocLancuchWynikowy(std::map<int, XDyzurantTworzacy*> mapa);
    QString zwrocDyzurantaOstatecznego(XDyzurantTworzacy* dt);
};

#endif // UITWORZONEGRAFIKI_H
