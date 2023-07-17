
#include "dbobslugiwaczbazydanych.h"
#include "dto.h"
#include <QDebug>

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
        strToWrite = std::to_string((*it)->liczbaDnia) + ". (" + przeliczDzienTygodniaNaLancuch((*it)->dzienTygodnia) + "): " + (*it)->dyzurantWybrany->getNick();
        outputFileReader << strToWrite << std::endl;
    }
    outputFileReader.close();
    return true;
}


/*
        if ((*it)->getCzyWpisywanieGdzieMoze()) {
            dane.push_back("1");    //1. wers - czy moze czy nie moze
            s = (*it)->getKiedyMoze();
        }
        else {
            dane.push_back("0");    //1. wers
            s = (*it)->getKiedyNieMoze();
        }
        dane.push_back(s);        //2. wers - kiedy moze lub kiedy nie moze
        dane.push_back((*it)->getKiedyChce());    //3. wers - kiedy chce
        dane.push_back((*it)->getKiedyUnika());    //4. wers - kiedy unika
        dane.push_back(std::to_string((*it)->getMaksymalnie()));    //5. wers - maksymalnie
        dane.push_back(std::to_string((*it)->getMinimalnie()));       //6. wers - minimalnie
        dane.push_back(std::to_string((*it)->getMaksymalnieSoboty()));    //7. wers- maks soboty
        dane.push_back(std::to_string((*it)->getMaksymalnieNiedziele()));    //8. wers - maks niedziele
        dane.push_back(std::to_string((*it)->getMaksymalnieWeekendy()));    //9. wers - maks weekendy
        dane.push_back(std::to_string((*it)->getUnikaniePodRzad()));        //10. wers - unikanie pod rząd
*/



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

DBObslugiwaczBazyDanych::~DBObslugiwaczBazyDanych() {

}
