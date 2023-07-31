
#ifndef UIPRZEGLADANIEGRAFIKOWOSTATECZNYCH_H
#define UIPRZEGLADANIEGRAFIKOWOSTATECZNYCH_H


#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QTableWidget>
#include <QComboBox>

class PPrzegladanieGrafikowOstatecznych;
class XWyswietlanyGrafik;
enum Miesiac : int;

class UIPrzegladanieGrafikowOstatecznych : public QMainWindow {
    Q_OBJECT
public:
    explicit UIPrzegladanieGrafikowOstatecznych(PPrzegladanieGrafikowOstatecznych* p, QWidget *parent = nullptr);
    ~UIPrzegladanieGrafikowOstatecznych() {}
    //void ableUsunButton(bool how);
    void wyswietlKonkretnyGrafik(XWyswietlanyGrafik* grafikDoWyswietlenia);
    void wyczyscTabele();
public slots:
    void onButtonSzukajClicked();
    void onButtonCloseClicked();
    void onButtonUsunClicked();
    void onButtonZapiszJakoPDFClicked();
private:
    std::vector<Miesiac> tablicaMiesiecy;
    PPrzegladanieGrafikowOstatecznych* pPrzegladanieGrafikowOstatecznych;
    QWidget* mainWidget;

    QGroupBox* groupMiesiacRok;
    QLabel* labelMiesiac,* labelRok;
    QLineEdit* editMiesiac,* editRok;
    QPushButton* buttonSzukaj;
    QGridLayout* layoutGroup;

    QPushButton* buttonUsun,* buttonDrukujPDF;
    QComboBox* comboDniTygodnia;
    QHBoxLayout* layoutChoice;

    QTableWidget* tableGrafik;
    QPushButton* buttonClose;
    QVBoxLayout* mainLayout;

    QString translateEnumToQString(Miesiac m);

};

#endif // UIPRZEGLADANIEGRAFIKOWOSTATECZNYCH_H
