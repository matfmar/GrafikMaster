
#include "pprzegladaniegrafikowroboczych.h"
#include "uiprzegladaniegrafikowroboczych.h"
#include "dto.h"

PPrzegladanieGrafikowRoboczych::PPrzegladanieGrafikowRoboczych()
    : uiPrzegladanieGrafikowRoboczych(nullptr), aktualnaListaGrafikow(nullptr), db(nullptr), 
    ileGrafikowNaLiscie(0), ktoryWyswietlamy(0) {
    aktualnaListaGrafikow = new std::vector<XWyswietlanyGrafik*>();
    db = new DBObslugiwaczBazyDanych();
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
    ktoryWyswietlamy = 0;
}

int PPrzegladanieGrafikowRoboczych::wybranoSzukanieGrafikow(int miesiac, int rok) {
    //najpierw czyscimy liste juz zaladowanych grafikow
    wyczyscAktualnaListeGrafikow();
    //teraz wczytujemy kolejne
    bool result(false);
    std::string wzorNazwy = "w_grafik_" + std::to_string(miesiac) + "_" + std::to_string(rok) + "_";
    std::vector<std::string> listaNazwPlikow = db->wczytajListeNazwPlikowZGrafikamiRoboczymi(wzorNazwy, result);
    XWyswietlanyGrafik* nowyWyswietlanyGrafik(nullptr);
    int licznikGrafikow(0);
    for (auto it=listaNazwPlikow.begin(); it<listaNazwPlikow.end(); ++it) {
        nowyWyswietlanyGrafik = db->zaladujGrafikOKonkretnejNazwie(*it);
        aktualnaListaGrafikow->push_back(nowyWyswietlanyGrafik);
        licznikGrafikow++;
    }
    ileGrafikowNaLiscie = licznikGrafikow;
    return licznikGrafikow;
}
    
void PPrzegladanieGrafikowRoboczych::wybranoGrafikWLewo() {
    
}

XWyswietlanyGrafik* PPrzegladanieGrafikowRoboczych::wybranoGrafikWPrawo(int& ktory, int& ileWszystkich) {
    
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
