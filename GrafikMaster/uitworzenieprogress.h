
#ifndef UITWORZENIEPROGRESS_H
#define UITWORZENIEPROGRESS_H


#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>

class PProgress;

class UITworzenieProgress : public QDialog {
public:
    UITworzenieProgress(PProgress* p);
    ~UITworzenieProgress() {}
    void setLabelIleGrafikow(int ileGrafikow);
private:
    QLabel* labelTekst;
    QLabel* labelIleGrafikow;
    QVBoxLayout* layout;

    PProgress* parent;
};

#endif // UITWORZENIEPROGRESS_H
