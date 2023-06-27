
#ifndef UIDODAWANIENOWEGODYZURANTA_H
#define UIDODAWANIENOWEGODYZURANTA_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class UIDodawanieNowegoDyzuranta : public QDialog {
    Q_OBJECT
public:
    UIDodawanieNowegoDyzuranta();
    ~UIDodawanieNowegoDyzuranta();
public slots:
    void onButtonOKClicked();
    void onButtonAnulujClicked();
private:
    QGridLayout* layout;
    QLabel* labelNick;
    QLabel* labelPriorytet;
    QLineEdit* editNick;
    QLineEdit* editPriorytet;
    QPushButton* buttonOK;
    QPushButton* buttonAnuluj;


};

#endif // UIDODAWANIENOWEGODYZURANTA_H
