
#include "pprzegladaniegrafikowroboczych.h"
#include "uiprzegladaniegrafikowroboczych.h"
#include "dbobslugiwaczbazydanych.h"
#include "dto.h"

PPrzegladanieGrafikowRoboczych::PPrzegladanieGrafikowRoboczych()
    : uiPrzegladanieGrafikowRoboczych(nullptr), aktualnaListaGrafikow(nullptr), db(nullptr), 
    ileGrafikowNaLiscie(0), ktoryWyswietlamy(-1) {
    uiPrzegladanieGrafikowRoboczych = new UIPrzegladanieGrafikowRoboczych(this);
    aktualnaListaGrafikow = new std::vector<XWyswietlanyGrafik*>();
    db = new DBObslugiwaczBazyDanych();
}

void PPrzegladanieGrafikowRoboczych::pokazOknoPrzegladaniaGrafikow() {
    uiPrzegladanieGrafikowRoboczych->show();
}

void PPrzegladanieGrafikowRoboczych::wyczyscAktualnaListeGrafikow() {
    XWyswietlanyGrafik* grafikDoUsuniecia(nullptr);
    for (auto it=aktualnaListaGrafikow->begin(); it<aktualnaListaGrafikow->end(); ++it) {
        if ((*it) != nullptr) {
            grafikDoUsuniecia = *it;
            delete grafikDoUsuniecia;
            grafikDoUsuniecia = nullptr;
            *it = nullptr;
        }
    }
    aktualnaListaGrafikow->clear();
    ileGrafikowNaLiscie = 0;
    ktoryWyswietlamy = -1;
}

int PPrzegladanieGrafikowRoboczych::wybranoSzukanieGrafikow(int miesiac, int rok) {
    //najpierw czyscimy liste juz zaladowanych grafikow
    wyczyscAktualnaListeGrafikow();
    //teraz wczytujemy kolejne
    bool result(false);
    std::string wzorNazwy = "w_grafik_" + std::to_string(miesiac) + "_" + std::to_string(rok) + "_";
    listaNazwPlikow = db->wczytajListeNazwPlikowZGrafikamiRoboczymi(wzorNazwy, result);
    XWyswietlanyGrafik* nowyWyswietlanyGrafik(nullptr);
    int licznikGrafikow(0);
    for (auto it=listaNazwPlikow.begin(); it<listaNazwPlikow.end(); ++it) {
        nowyWyswietlanyGrafik = db->zaladujGrafikOKonkretnejNazwie(*it);
        aktualnaListaGrafikow->push_back(nowyWyswietlanyGrafik);
        licznikGrafikow++;
    }
    ileGrafikowNaLiscie = licznikGrafikow;
    uiPrzegladanieGrafikowRoboczych->ableLeftButton(false);
    uiPrzegladanieGrafikowRoboczych->ableRightButton(true);
    return licznikGrafikow;
}

bool PPrzegladanieGrafikowRoboczych::wybranoUsuniecieWszystkichGrafikow() {
    if (ileGrafikowNaLiscie <= 0) {
        return false;
    }
    bool resultUsuniecia(false);
    for (auto it=listaNazwPlikow.begin(); it<listaNazwPlikow.end(); ++it) {
        resultUsuniecia = db->usunPlikGrafikuRoboczego
    }
}

bool PPrzegladanieGrafikowRoboczych::wybranoUsuniecieGrafiku(bool& czyCosZostaje) {
    if (ktoryWyswietlamy == -1 || ktoryWyswietlamy > ileGrafikowNaLiscie - 1) {
        return false;
    }
    std::string nazwaPliku = (*aktualnaListaGrafikow)[ktoryWyswietlamy]->nazwaPliku;
    bool resultUsunieciePliku = db->usunPlikGrafikuRoboczego(nazwaPliku);
    if (!resultUsunieciePliku) {
        return false;
    }
    auto itDoUsuniecia = aktualnaListaGrafikow->begin() + ktoryWyswietlamy;
    aktualnaListaGrafikow->erase(itDoUsuniecia);
    ileGrafikowNaLiscie--;
    if (ileGrafikowNaLiscie == 0) {
        czyCosZostaje = false;
        uiPrzegladanieGrafikowRoboczych->ableRightButton(false);
        uiPrzegladanieGrafikowRoboczych->ableLeftButton(false);
        uiPrzegladanieGrafikowRoboczych->ableUsunButton(false);
        ktoryWyswietlamy = -1;
        uiPrzegladanieGrafikowRoboczych->wyczyscTabele();
        return true;
    }
    else if (ileGrafikowNaLiscie == 1) {
        czyCosZostaje = true;
        uiPrzegladanieGrafikowRoboczych->ableRightButton(false);
        uiPrzegladanieGrafikowRoboczych->ableLeftButton(false);
        uiPrzegladanieGrafikowRoboczych->ableUsunButton(true);
        ktoryWyswietlamy = 0;
        uiPrzegladanieGrafikowRoboczych->wyswietlKonkretnyGrafik((*aktualnaListaGrafikow)[0], 1, 1);
        return true;
    }
    else {
        if (ktoryWyswietlamy == 0) {
            czyCosZostaje = true;
            uiPrzegladanieGrafikowRoboczych->ableRightButton(true);
            uiPrzegladanieGrafikowRoboczych->ableLeftButton(false);
            uiPrzegladanieGrafikowRoboczych->ableUsunButton(true);            
            ktoryWyswietlamy = 0;
            uiPrzegladanieGrafikowRoboczych->wyswietlKonkretnyGrafik((*aktualnaListaGrafikow)[0], 1, ileGrafikowNaLiscie);
        }
        else if (ktoryWyswietlamy == ileGrafikowNaLiscie) {
            czyCosZostaje = true;
            uiPrzegladanieGrafikowRoboczych->ableRightButton(false);
            uiPrzegladanieGrafikowRoboczych->ableLeftButton(true);
            uiPrzegladanieGrafikowRoboczych->ableUsunButton(true);                
            ktoryWyswietlamy = ileGrafikowNaLiscie - 1;
            uiPrzegladanieGrafikowRoboczych->wyswietlKonkretnyGrafik((*aktualnaListaGrafikow)[ktoryWyswietlamy], ileGrafikowNaLiscie, ileGrafikowNaLiscie);
        }
        else {
            czyCosZostaje = true;
            uiPrzegladanieGrafikowRoboczych->ableRightButton(true);
            uiPrzegladanieGrafikowRoboczych->ableLeftButton(true);
            uiPrzegladanieGrafikowRoboczych->ableUsunButton(true);
            uiPrzegladanieGrafikowRoboczych->wyswietlKonkretnyGrafik((*aktualnaListaGrafikow)[ktoryWyswietlamy], ktoryWyswietlamy+1, ileGrafikowNaLiscie);
        }
        return true;
    }
    return true;
}
    
XWyswietlanyGrafik* PPrzegladanieGrafikowRoboczych::wybranoGrafikWLewo(int& ktory, int& ileWszystkich) {
    if ((aktualnaListaGrafikow == nullptr || ktoryWyswietlamy == 0) || (*aktualnaListaGrafikow)[ktoryWyswietlamy-1] == nullptr) {
        return nullptr;
    }
    ktoryWyswietlamy--;
    if (ktoryWyswietlamy == ileGrafikowNaLiscie-1) {
        uiPrzegladanieGrafikowRoboczych->ableRightButton(false);
        uiPrzegladanieGrafikowRoboczych->ableLeftButton(true);
        uiPrzegladanieGrafikowRoboczych->ableUsunButton(true);
    }
    else if (ktoryWyswietlamy == 0) {
        uiPrzegladanieGrafikowRoboczych->ableRightButton(true);
        uiPrzegladanieGrafikowRoboczych->ableLeftButton(false);
        uiPrzegladanieGrafikowRoboczych->ableUsunButton(true);
    }
    else {
        uiPrzegladanieGrafikowRoboczych->ableRightButton(true);
        uiPrzegladanieGrafikowRoboczych->ableLeftButton(true);
        uiPrzegladanieGrafikowRoboczych->ableUsunButton(true);
    }
    ktory = ktoryWyswietlamy+1;
    ileWszystkich = ileGrafikowNaLiscie;
    return (*aktualnaListaGrafikow)[ktoryWyswietlamy];
}

XWyswietlanyGrafik* PPrzegladanieGrafikowRoboczych::wybranoGrafikWPrawo(int& ktory, int& ileWszystkich) {
    if ((aktualnaListaGrafikow == nullptr || ktoryWyswietlamy == ileGrafikowNaLiscie-1) || (*aktualnaListaGrafikow)[ktoryWyswietlamy+1] == nullptr) {
        return nullptr;
    }
    ktoryWyswietlamy++;
    if (ktoryWyswietlamy == ileGrafikowNaLiscie-1) {
        uiPrzegladanieGrafikowRoboczych->ableRightButton(false);
        uiPrzegladanieGrafikowRoboczych->ableLeftButton(true);
        uiPrzegladanieGrafikowRoboczych->ableUsunButton(true);
    }
    else if (ktoryWyswietlamy == 0) {
        uiPrzegladanieGrafikowRoboczych->ableRightButton(true);
        uiPrzegladanieGrafikowRoboczych->ableLeftButton(false);        
        uiPrzegladanieGrafikowRoboczych->ableUsunButton(true);
    }
    else if (ileGrafikowNaLiscie == 1) {
        uiPrzegladanieGrafikowRoboczych->ableRightButton(false);
        uiPrzegladanieGrafikowRoboczych->ableLeftButton(false);           
        uiPrzegladanieGrafikowRoboczych->ableUsunButton(true);
    }
    else {
        uiPrzegladanieGrafikowRoboczych->ableRightButton(true);
        uiPrzegladanieGrafikowRoboczych->ableLeftButton(true);
        uiPrzegladanieGrafikowRoboczych->ableUsunButton(true);
    }
    ktory = ktoryWyswietlamy+1;
    ileWszystkich = ileGrafikowNaLiscie;
    return (*aktualnaListaGrafikow)[ktoryWyswietlamy];
}
 
void PPrzegladanieGrafikowRoboczych::wybranoZamkniecie() {

}

PPrzegladanieGrafikowRoboczych::~PPrzegladanieGrafikowRoboczych() {
    if (uiPrzegladanieGrafikowRoboczych != nullptr) {
        delete uiPrzegladanieGrafikowRoboczych;
        uiPrzegladanieGrafikowRoboczych = nullptr;
    }
    if (aktualnaListaGrafikow != nullptr) {
        XWyswietlanyGrafik* grafikDoUsuniecia(nullptr);
        for (auto it=aktualnaListaGrafikow->begin(); it<aktualnaListaGrafikow->end(); ++it) {
            if ((*it) != nullptr) {
                grafikDoUsuniecia = *it;
                delete grafikDoUsuniecia;
                grafikDoUsuniecia = nullptr;
                *it = nullptr;
            }
        }
        delete aktualnaListaGrafikow;
    }
    if (db != nullptr) {
        delete db;
        db = nullptr;
    }
}
