
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
    bool zapiszNicki(std::vector<std::string> nicki);
    std::vector<std::string> wczytajNicki(bool& result);
    std::vector<std::string> wczytajDyzurantaTworzacego(std::string nick, bool& result);

    //ObslugaZapisywanychDanych
    bool zapiszUstawieniaDyzurantaTworzacego(std::vector<std::string> dane, std::string dyzurant);
    bool usunWszystkiePlikiZUstawieniami();

    //ObslugaSwiezoTworzonychGrafikow
    bool zapiszUlozonyGrafikDoPliku(XGrafik* grafik, int id);

    //ObslugaPrzegladaniaGrafikowRoboczych
    std::vector<std::string> wczytajListeNazwPlikowZGrafikamiRoboczymi(std::string wzorNazwy, bool& result);    //wzorNazwy do (i włącznie z) podkreślnikiem przed id
private:
    std::ifstream inputFileReader;
    std::ofstream outputFileReader;

    //ObslugaDyzurantow
    XDyzurant* parseDyzurant(std::string s, int id);
    std::string dyzurantToString(XDyzurant* d);
};

#endif // DBOBSLUGIWACZBAZYDANYCH_H
