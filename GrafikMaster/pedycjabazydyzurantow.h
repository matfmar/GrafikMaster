
#ifndef PEDYCJABAZYDYZURANTOW_H
#define PEDYCJABAZYDYZURANTOW_H

class UIEdycjaBazyDyzurantow;

class PEdycjaBazyDyzurantow {
public:
    PEdycjaBazyDyzurantow();
    ~PEdycjaBazyDyzurantow();

    void wybranoDodanieNowegoDyzuranta();
    void wybranoUpdateDyzuranta();
    void wybranoUsuniecieDyzuranta();
private:
    UIEdycjaBazyDyzurantow* uiEdycjaBazyDyzurantow;
};

#endif // PEDYCJABAZYDYZURANTOW_H
