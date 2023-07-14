
#ifndef UIPRZEGLADANIEGRAFIKOWROBOCZYCH_H
#define UIPRZEGLADANIEGRAFIKOWROBOCZYCH_H


#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QTableWidget>

class PPrzegladanieGrafikowRoboczych;

class UIPrzegladanieGrafikowRoboczych : public QMainWindow {
    Q_OBJECT
public:
    UIPrzegladanieGrafikowRoboczych(PPrzegladanieGrafikowRoboczych* p, QWidget *parent = nullptr);
    ~UIPrzegladanieGrafikowRoboczych() {}
public slots:

private:
    PPrzegladanieGrafikowRoboczych* pPrzegladanieGrafikowRoboczych;
    QWidget* mainWidget;

};

#endif // UIPRZEGLADANIEGRAFIKOWROBOCZYCH_H
