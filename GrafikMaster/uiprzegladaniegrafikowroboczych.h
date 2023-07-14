
#ifndef UIPRZEGLADANIEGRAFIKOWROBOCZYCH_H
#define UIPRZEGLADANIEGRAFIKOWROBOCZYCH_H


#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>

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
