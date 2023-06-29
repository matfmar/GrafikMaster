
#ifndef UIDODAWANIENOWEGODYZURANTA_H
#define UIDODAWANIENOWEGODYZURANTA_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class PEdycjaBazyDyzurantow;

class UIDodawanieNowegoDyzuranta : public QDialog {
    Q_OBJECT
public:
    UIDodawanieNowegoDyzuranta(PEdycjaBazyDyzurantow* pebd);
    ~UIDodawanieNowegoDyzuranta();
public slots:
    void onButtonOKClicked();
    void onButtonAnulujClicked();
private:
    PEdycjaBazyDyzurantow* pEdycjaBazyDyzurantow;
    QGridLayout* layout;
    QLabel* labelNick;
    QLabel* labelPriorytet;
    QLineEdit* editNick;
    QLineEdit* editPriorytet;
    QPushButton* buttonOK;
    QPushButton* buttonAnuluj;


};

#endif // UIDODAWANIENOWEGODYZURANTA_H
