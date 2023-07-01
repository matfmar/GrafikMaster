
#ifndef UIDODAWANIENOWEGOGRAFIKUWSTEP_H
#define UIDODAWANIENOWEGOGRAFIKUWSTEP_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QComboBox>

class PDodawanieNowegoGrafiku;

class UIDodawanieNowegoGrafikuWstep : public QDialog {
    Q_OBJECT
public:
    UIDodawanieNowegoGrafikuWstep(PDodawanieNowegoGrafiku* pd);
    ~UIDodawanieNowegoGrafikuWstep() {}
public slots:
    void onButtonDodajClicked();
    void onButtonAnulujClicked();
private:
    PDodawanieNowegoGrafiku* pDodawanieNowegoGrafiku;
    QGridLayout* gridLayout;
    QLabel* labelRok,* labelMiesiac,* labelLiczbaDni,* labelPierwszyDzien;
    QLineEdit* editRok,* editLiczbaDni;
    QComboBox* boxMiesiac,* boxPierwszyDzien;
    QPushButton* buttonDodaj,* buttonAnuluj;
};

#endif // UIDODAWANIENOWEGOGRAFIKUWSTEP_H
