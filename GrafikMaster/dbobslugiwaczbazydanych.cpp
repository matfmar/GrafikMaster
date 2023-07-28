
#include "dbobslugiwaczbazydanych.h"
#include "dto.h"
#include <QDebug>
#include <filesystem>
#include <QDir>
#include <QFile>
#include <QStringList>

DBObslugiwaczBazyDanych::DBObslugiwaczBazyDanych() {}

//Obsluga Dyzurantow
XDyzurant* DBObslugiwaczBazyDanych::parseDyzurant(std::string s, int id) {
    std::vector<std::string> tabStrings;
    std::string currString("");
    for (auto it=s.begin(); it != s.end(); ++it) {
        if (*it != ';') {
            currString += *it;
        }
        else {
            tabStrings.push_back(currString);
            currString = "";
        }
    }
    XDyzurant* dyzurant = new XDyzurant(id, tabStrings[0], std::stoi(tabStrings[1]));
    return dyzurant;
}

std::vector<XDyzurant*>* DBObslugiwaczBazyDanych::getTablicaDyzurantowFull() {
    std::vector<XDyzurant*>* tablicaDyzurantowFull = new std::vector<XDyzurant*>();
    inputFileReader.open("data/dyzuranci/dyzuranci.data");
    if (!inputFileReader.is_open()) {
        qDebug() << "plik nie istnieje";
        return nullptr;
    }
    std::string line("");
    XDyzurant* dyzurant(nullptr);
    int i(0);
    while (getline(inputFileReader, line)) {
        if (line != "") {
            dyzurant = parseDyzurant(line, i);
            tablicaDyzurantowFull -> push_back(dyzurant);
            i++;
        }
    }
    inputFileReader.close();
    return tablicaDyzurantowFull;
}

std::string DBObslugiwaczBazyDanych::dyzurantToString(XDyzurant* d) {
    std::string s("");
    s += d->getNick();
    s += ";";
    s += std::to_string(d->getPriorytet());
    s += ";";
    return s;
}

bool DBObslugiwaczBazyDanych::writeListaDyzurantowFull(std::vector<XDyzurant*>* tdf) {
    if (tdf == nullptr) {
        return false;
    }
    outputFileReader.open("data/dyzuranci/dyzuranci.data", std::ofstream::out | std::ofstream::trunc);
    if (!outputFileReader.is_open()) {
        return false;
    }
    std::string strToWrite("");
    for (auto it=tdf->begin(); it!=tdf->end(); ++it) {
        strToWrite = dyzurantToString(*it);
        outputFileReader << strToWrite << std::endl;
    }
    outputFileReader.close();
    return true;
}

bool DBObslugiwaczBazyDanych::zapiszUlozonyGrafikDoPliku(XGrafik* grafik, int id) {
    if (grafik == nullptr) {
        return false;
    }
    std::string miesiacRokPart = grafik->getMiesiacRok();
    std::string filename = "w_grafik_" + miesiacRokPart + "_" + std::to_string(id) + ".data";    
    outputFileReader.open("data/grafiki_robocze/" + filename, std::ofstream::out | std::ofstream::trunc);
    if (!outputFileReader.is_open()) {
        return false;
    }
    std::vector<XDzien*> tablicaDni = grafik->udostepnijTabliceDni();
    std::string strToWrite("");
    for (auto it = tablicaDni.begin()+1; it<tablicaDni.end()-1; ++it) { //nie bierzemy pod uwagę pustych dni dołożonych dla ułatwienia algorytmu
        strToWrite = std::to_string((*it)->liczbaDnia) + ";" + przeliczDzienTygodniaNaLancuch((*it)->dzienTygodnia) + ";" + (*it)->dyzurantWybrany->getNick() + ";";
        if ((*it)->czySwieto) {
            strToWrite += "1;";
        }
        else {
            strToWrite += "0;";
        }
        outputFileReader << strToWrite << std::endl;
    }
    outputFileReader.close();
    return true;
}

bool DBObslugiwaczBazyDanych::zapiszUstawieniaDyzurantaTworzacego(std::vector<std::string> dane, std::string dyzurant) {
    std::string filename = dyzurant + ".data";
    outputFileReader.open("data/zapisane_warunki/" + filename, std::ofstream::out | std::ofstream::trunc);
    if (!outputFileReader.is_open()) {
        return false;
    }
    for (auto it = dane.begin(); it<dane.end(); ++it) {
        outputFileReader << *it << std::endl;
    }
    outputFileReader.close();
    return true;
}

bool DBObslugiwaczBazyDanych::zapiszNicki(std::vector<std::string> nicki) {
    std::string filename = "nicki.data";
    outputFileReader.open("data/zapisane_warunki/" + filename, std::ofstream::out | std::ofstream::trunc);
    if (!outputFileReader.is_open()) {
        return false;
    }
    for (auto it = nicki.begin(); it<nicki.end(); ++it) {
        outputFileReader << *it << std::endl;
    }
    outputFileReader.close();
    return true;
}

std::vector<std::string> DBObslugiwaczBazyDanych::wczytajNicki(bool& result) {
    std::vector<std::string> v;
    inputFileReader.open("data/zapisane_warunki/nicki.data");
    if (!inputFileReader.is_open()) {
        result = false;
        return v;
    }
    std::string line("");
    while (getline(inputFileReader, line)) {
        v.push_back(line);
    }
    inputFileReader.close();
    result = true;
    return v;
}

bool DBObslugiwaczBazyDanych::usunWszystkiePlikiZUstawieniami() {
    std::string dir_path = "data/zapisane_warunki/";
    for (const auto& entry : std::filesystem::directory_iterator(dir_path))
        std::filesystem::remove_all(entry.path());
    return true;
}

std::vector<std::string> DBObslugiwaczBazyDanych::wczytajDyzurantaTworzacego(std::string nick, bool& result) {
    std::vector<std::string> v;
    std::string filename = nick + ".data";
    inputFileReader.open("data/zapisane_warunki/" + filename);
    if (!inputFileReader.is_open()) {
        result = false;
        return v;
    }
    std::string line("");
    while (getline(inputFileReader, line)) {
        v.push_back(line);
    }
    inputFileReader.close();
    result = true;
    return v;
}

XWyswietlanyGrafik* DBObslugiwaczBazyDanych::zaladujGrafikOKonkretnejNazwie(std::string nazwa, int miesiac, int rok) {
    nazwa = "data/grafiki_robocze/" + nazwa;
    inputFileReader.open(nazwa.c_str());
    if (!inputFileReader.is_open()) {
        return nullptr;
    }
    XWyswietlanyGrafik* nowyWyswietlanyGrafik = new XWyswietlanyGrafik(nazwa, miesiac, rok);
    XWyswietlanyGrafik::XPozycjaGrafiku* nowaPozycjaGrafiku(nullptr);
    std::string line(""), subline("");
    QString dz(""), dt(""), dy("");
    bool cs(false);
    int licznikSrednikow(0);
    while (getline(inputFileReader, line)) {
        for (char c : line) {
            if (c != ';') {
                subline += c;
            }
            else {
                if (licznikSrednikow == 0) {
                    dz = QString::fromStdString(subline);
                    subline = "";
                    licznikSrednikow++;
                }
                else if (licznikSrednikow == 1) {
                    dt = QString::fromStdString(subline);
                    subline = "";
                    licznikSrednikow++;
                }
                else if (licznikSrednikow == 2) {
                    dy = QString::fromStdString(subline);
                    subline = "";
                    licznikSrednikow++;
                }
                else if (licznikSrednikow >= 3) {
                    if (subline == "0") {
                        cs = false;
                    }
                    else {
                        cs = true;
                    }
                    subline = "";
                    licznikSrednikow++;
                }
            }
        }
        subline = "";
        licznikSrednikow = 0;
        nowaPozycjaGrafiku = new XWyswietlanyGrafik::XPozycjaGrafiku(dz, dt, dy, cs);
        nowyWyswietlanyGrafik->listaPozycjiGrafiku->push_back(nowaPozycjaGrafiku);
    }
    inputFileReader.close();
    return nowyWyswietlanyGrafik;
}

bool DBObslugiwaczBazyDanych::przekopiujPlikDoOstatecznych(std::string nazwaPliku) {
    QString filename = QString::fromStdString(nazwaPliku);
    QFile file(filename);
    QString filename2 = filename.remove("data/grafiki_robocze/");
    filename2 = "data/grafiki_ostateczne/" + filename2;
    return (file.copy(filename2));
}

bool DBObslugiwaczBazyDanych::usunPlikGrafikuRoboczego(std::string nazwaPliku) {
    QString filename = QString::fromStdString(nazwaPliku);
    QFile file(filename);
    bool result = file.remove();
    return result;
}

std::vector<std::string> DBObslugiwaczBazyDanych::wczytajListeNazwPlikowZGrafikamiRoboczymi(std::string wzorNazwy, bool& result) {
    QDir* dir = new QDir("data/grafiki_robocze");
    std::vector<std::string> listaNazw;
    QStringList filters;
    std::string filtr = wzorNazwy + "*.data";
    filters << QString::fromStdString(filtr);
    dir->setNameFilters(filters);
    QStringList listaNazwQ = dir->entryList(QDir::Files);
    for (auto it=listaNazwQ.begin(); it<listaNazwQ.end(); ++it) {
        listaNazw.push_back((*it).toStdString());
    }
    delete dir;
    result = true;
    return listaNazw;
}

DBObslugiwaczBazyDanych::~DBObslugiwaczBazyDanych() {

}
