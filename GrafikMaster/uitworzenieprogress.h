
#ifndef UITWORZENIEPROGRESS_H
#define UITWORZENIEPROGRESS_H


#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

class PProgress;

class UITworzenieProgress : public QDialog {
    Q_OBJECT
public:
    UITworzenieProgress(PProgress* p);
    ~UITworzenieProgress() {}
    void setLabelIleGrafikow(int ileGrafikow);
    void setLabelIleObrotow(int ileObrotow);
public slots:
    void onButtonZakonczClicked();
signals:
    void buttonZakonczClicked();
private:
    QLabel* labelTekst,* labelTekstObroty;
    QLabel* labelIleGrafikow,* labelIleObrotow;
    QPushButton* buttonZakoncz;
    QVBoxLayout* layout;

    PProgress* parent;
};

#endif // UITWORZENIEPROGRESS_H
