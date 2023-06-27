
#ifndef UIEDYCJABAZYDYZURANTOW_H
#define UIEDYCJABAZYDYZURANTOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>

class PEdycjaBazyDyzurantow;


class UIEdycjaBazyDyzurantow : public QMainWindow
{
    Q_OBJECT
public:
    UIEdycjaBazyDyzurantow(PEdycjaBazyDyzurantow* pebd, QWidget *parent = nullptr);
    ~UIEdycjaBazyDyzurantow();
public slots:
    void onButtonDodajDyzurantaClicked();
    void onButtonUpdateDyzurantaClicked();
    void onButtonUsunDyzurantaClicked();
    void onListWidgetClicked(QListWidgetItem* item);
private:
    PEdycjaBazyDyzurantow* pEdycjaBazyDyzurantow;
    QWidget* mainWidget;
    QHBoxLayout* mainLayout;
    QVBoxLayout* leftLayout;
    QGridLayout* rightLayout;
    QGroupBox* groupDyzurant;

    QListWidget* listaDyzurantow;
    QPushButton* buttonDodajDyzuranta;
    QLabel* labelNick;
    QLabel* labelPriorytet;
    QLineEdit* editNick;
    QLineEdit* editPriorytet;
    QPushButton* buttonUpdate;
    QPushButton* buttonUsun;

};

#endif // UIEDYCJABAZYDYZURANTOW_H
