
#ifndef PPRZEGLADANIEGRAFIKOWROBOCZYCH_H
#define PPRZEGLADANIEGRAFIKOWROBOCZYCH_H


class UIPrzegladanieGrafikowRoboczych;

class PPrzegladanieGrafikowRoboczych
{
public:
    PPrzegladanieGrafikowRoboczych();
    ~PPrzegladanieGrafikowRoboczych();
    void wybranoSzukanieGrafikow(int miesiac, int rok);
    void wybranoGrafikWLewo();
    void wybranoGrafikWPrawo();
    void wybranoZamkniecie();
private:
    UIPrzegladanieGrafikowRoboczych* uiPrzegladanieGrafikowRoboczych;
};

#endif // PPRZEGLADANIEGRAFIKOWROBOCZYCH_H
