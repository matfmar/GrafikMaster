
#ifndef MDYZURANCI_H
#define MDYZURANCI_H

#include <vector>
#include <string>

class DBObslugiwaczBazyDanych;
class XDyzurant;

class MDyzuranci {
public:
    MDyzuranci();
    ~MDyzuranci();
    std::vector<XDyzurant*>* wyciagnijTabliceDyzurantow();
    XDyzurant* pokazDaneJednegoDyzuranta(int id);
    std::vector<XDyzurant*>* dodajNowegoDyzuranta(std::string nick, int priorytet, bool& result);
    std::vector<XDyzurant*>* zrobUpdateDyzuranta(int a, std::string b, int c, bool& result);
    std::vector<XDyzurant*>* usunDyzuranta(int a, bool& result);
private:
    DBObslugiwaczBazyDanych* dbObslugiwaczBazyDanych;
    std::vector<XDyzurant*>* tablicaDyzurantow;

    bool sprawdzCzyIstniejeDanyDyzurant(std::string nick);
};

#endif // MDYZURANCI_H
