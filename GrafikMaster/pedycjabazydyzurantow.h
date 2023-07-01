
#ifndef PEDYCJABAZYDYZURANTOW_H
#define PEDYCJABAZYDYZURANTOW_H

#include <vector>
#include <QString>

class UIEdycjaBazyDyzurantow;
class UIDodawanieNowegoDyzuranta;
class MDyzuranci;
class XDyzurant;

class PEdycjaBazyDyzurantow {
public:
    PEdycjaBazyDyzurantow();
    ~PEdycjaBazyDyzurantow();

    void wybranoDodanieNowegoDyzuranta();
    void wybranoPrawdziweDodanieNowegoDyzuranta(QString nick, int priorytet);
    void wybranoUpdateDyzuranta(int a, QString b, int c);
    void wybranoUsuniecieDyzuranta();
    XDyzurant* wybranoPokazanieSzczegolowDyzuranta(int id);
private:
    UIEdycjaBazyDyzurantow* uiEdycjaBazyDyzurantow;
    UIDodawanieNowegoDyzuranta* uiDodawanieNowegoDyzuranta;
    MDyzuranci* mDyzuranci;
};

#endif // PEDYCJABAZYDYZURANTOW_H
