
#ifndef UIDODAWANIENOWEGOGRAFIKUWSTEP_H
#define UIDODAWANIENOWEGOGRAFIKUWSTEP_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QComboBox>
#include <vector>

class PDodawanieNowegoGrafiku;
enum Miesiac : int;
enum DzienTygodnia : int;

class UIDodawanieNowegoGrafikuWstep : public QDialog {
    Q_OBJECT
public:
    UIDodawanieNowegoGrafikuWstep(std::vector<Miesiac> tM, std::vector<DzienTygodnia> tDT, PDodawanieNowegoGrafiku* pd);
    ~UIDodawanieNowegoGrafikuWstep() {}
public slots:
    void onButtonDodajClicked();
    void onButtonAnulujClicked();
    void onButtonZapiszClicked();
    void onButtonWczytajClicked();
private:
    PDodawanieNowegoGrafiku* pDodawanieNowegoGrafiku;
    QGridLayout* gridLayout;
    QLabel* labelRok,* labelMiesiac,* labelLiczbaDni,* labelPierwszyDzien,* labelSwieta;
    QLineEdit* editRok,* editLiczbaDni,* editSwieta;
    QComboBox* boxMiesiac,* boxPierwszyDzien;
    QPushButton* buttonDodaj,* buttonAnuluj;
    QPushButton* buttonZapisz,* buttonWczytaj;
    std::vector<Miesiac> tablicaMiesiecy;
    std::vector<DzienTygodnia> tablicaDniTygodnia;

    QString translateEnumToQString(Miesiac m);
    QString translateEnumToQString(DzienTygodnia dt);
};

#endif // UIDODAWANIENOWEGOGRAFIKUWSTEP_H
