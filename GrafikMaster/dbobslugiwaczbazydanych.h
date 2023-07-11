
#ifndef DBOBSLUGIWACZBAZYDANYCH_H
#define DBOBSLUGIWACZBAZYDANYCH_H

#include <fstream>
#include <vector>

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
private:
    std::ifstream inputFileReader;
    std::ofstream outputFileReader;

    //ObslugaDyzurantow
    XDyzurant* parseDyzurant(std::string s, int id);
    std::string dyzurantToString(XDyzurant* d);
};

#endif // DBOBSLUGIWACZBAZYDANYCH_H
