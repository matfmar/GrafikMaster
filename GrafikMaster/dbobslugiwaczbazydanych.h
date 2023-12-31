
#ifndef DBOBSLUGIWACZBAZYDANYCH_H
#define DBOBSLUGIWACZBAZYDANYCH_H

#include <fstream>
#include <vector>
#include <string>
#include <QString>

class XDyzurant;
class XGrafik;
class XWyswietlanyGrafik;

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
    bool zapiszParametryGrafikuDoPliku(std::vector<QString> daneDoZapisu);
    std::vector<QString> wczytajParametryGrafikuZPliku(bool& result);

    //ObslugaSwiezoTworzonychGrafikow
    bool zapiszUlozonyGrafikDoPliku(XGrafik* grafik, int id);

    //ObslugaPrzegladaniaGrafikowRoboczych
    std::vector<std::string> wczytajListeNazwPlikowZGrafikamiRoboczymi(std::string wzorNazwy, bool& result);    //wzorNazwy do (i włącznie z) podkreślnikiem przed id
    XWyswietlanyGrafik* zaladujGrafikOKonkretnejNazwie(std::string nazwa, int miesiac, int rok);
    bool usunPlikGrafikuRoboczego(std::string nazwaPliku);
    bool przekopiujPlikDoOstatecznych(std::string nazwaPliku);

    //ObslugaPrzegladaniaGrafikowOstatecznych
    std::vector<std::string> wczytajListeNazwPlikowZGrafikamiOstatecznymi(std::string wzorNazwy, bool& result);    //wzorNazwy do (i włącznie z) podkreślnikiem przed id
    XWyswietlanyGrafik* zaladujGrafikOstatecznyOKonkretnejNazwie(std::string nazwa, int miesiac, int rok);
    bool usunPlikGrafikuOstatecznego(std::string nazwaPliku);
private:
    std::ifstream inputFileReader;
    std::ofstream outputFileReader;

    //ObslugaDyzurantow
    XDyzurant* parseDyzurant(std::string s, int id);
    std::string dyzurantToString(XDyzurant* d);
};

#endif // DBOBSLUGIWACZBAZYDANYCH_H
