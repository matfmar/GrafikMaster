
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
#include <vector>

class PEdycjaBazyDyzurantow;
class XDyzurant;

class UIEdycjaBazyDyzurantow : public QMainWindow {
    Q_OBJECT
public:
    UIEdycjaBazyDyzurantow(std::vector<XDyzurant*>* tablicaDyzurantow, PEdycjaBazyDyzurantow* pebd, QWidget *parent = nullptr);
    ~UIEdycjaBazyDyzurantow();
    void aktualizujTabeleDyzurantow(std::vector<XDyzurant*>* tablicaDyzurantow, bool resultOfAddingNew);
    void zablokujMozliwoscUpdate();
    void wyczyscPolaUpdate();
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

    void wypelnijListeDyzurantami(std::vector<XDyzurant*>* tab);

};

#endif // UIEDYCJABAZYDYZURANTOW_H
