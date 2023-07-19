
#ifndef DBOBSLUGIWACZBAZYDANYCH_H
#define DBOBSLUGIWACZBAZYDANYCH_H

#include <fstream>
#include <vector>
#include <string>

class XDyzurant;
class XGrafik;

class DBObslugiwaczBazyDanych {
public:
    DBObslugiwaczBazyDanych();
    ~DBObslugiwaczBazyDanych();

    //ObslugaDyzurantow
    std::vector<XDyzurant*>* getTablicaDyzurantowFull();
    bool writeListaDyzurantowFull(std::vector<XDyzurant*>* tdf);
    bool zapiszUlozonyGrafikDoPliku(XGrafik* grafik, int id);
    bool zapiszUstawieniaDyzurantaTworzacego(std::vector<std::string> dane, std::string dyzurant);
    bool zapiszNicki(std::vector<std::string> nicki);
    std::vector<std::string> wczytajNicki(bool& result);
    std::vector<std::string> wczytajDyzurantaTworzacego(std::string nick, bool& result);
    bool usunWszystkiePlikiZUstawieniami();
private:
    std::ifstream inputFileReader;
    std::ofstream outputFileReader;

    //ObslugaDyzurantow
    XDyzurant* parseDyzurant(std::string s, int id);
    std::string dyzurantToString(XDyzurant* d);
};

#endif // DBOBSLUGIWACZBAZYDANYCH_H
