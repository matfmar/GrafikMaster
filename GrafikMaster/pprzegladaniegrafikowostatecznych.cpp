
#include "pprzegladaniegrafikowostatecznych.h"
#include "uiprzegladaniegrafikowostatecznych.h"
#include "dbobslugiwaczbazydanych.h"
#include "dto.h"
#include <QTextDocument>
#include <QPrinter>

PPrzegladanieGrafikowOstatecznych::PPrzegladanieGrafikowOstatecznych()
    : uiPrzegladanieGrafikowOstatecznych(nullptr), aktualnyGrafik(nullptr), db(nullptr) {
    uiPrzegladanieGrafikowOstatecznych = new UIPrzegladanieGrafikowOstatecznych(this);
    db = new DBObslugiwaczBazyDanych();
}

void PPrzegladanieGrafikowOstatecznych::pokazOknoPrzegladaniaGrafikow() {
    uiPrzegladanieGrafikowOstatecznych->show();
}

void PPrzegladanieGrafikowOstatecznych::usunWyswietlanyGrafik() {
    if (aktualnyGrafik != nullptr) {
        delete aktualnyGrafik;
        aktualnyGrafik = nullptr;
    }
}

int PPrzegladanieGrafikowOstatecznych::wybranoSzukanieGrafikow(int miesiac, int rok) {
    //najpierw czyscimy aktualny grafik
    usunWyswietlanyGrafik();
    //teraz wczytujemy kolejne
    bool result(false);
    std::string wzorNazwy = "w_grafik_" + std::to_string(miesiac) + "_" + std::to_string(rok) + "_";
    std::vector<std::string> listaNazwPlikow = db->wczytajListeNazwPlikowZGrafikamiOstatecznymi(wzorNazwy, result);
    XWyswietlanyGrafik* nowyWyswietlanyGrafik(nullptr);
    int licznikGrafikow(0);
    for (auto it=listaNazwPlikow.begin(); it<listaNazwPlikow.end(); ++it) {
        nowyWyswietlanyGrafik = db->zaladujGrafikOstatecznyOKonkretnejNazwie(*it, miesiac, rok);
        licznikGrafikow++;
    }
    if (licznikGrafikow != 1) {
        return -1;
    }
    aktualnyGrafik = nowyWyswietlanyGrafik;
    uiPrzegladanieGrafikowOstatecznych -> wyswietlKonkretnyGrafik(aktualnyGrafik);
    return licznikGrafikow;
}

bool PPrzegladanieGrafikowOstatecznych::wybranoUsuniecieGrafiku() {
    if (aktualnyGrafik == nullptr) {
        return false;
    }
    std::string nazwaPliku = aktualnyGrafik->nazwaPliku;
    bool resultUsunieciePliku = db->usunPlikGrafikuOstatecznego(nazwaPliku);
    if (!resultUsunieciePliku) {
        return false;
    }
    delete aktualnyGrafik;
    aktualnyGrafik = nullptr;
    return true;
}

QString PPrzegladanieGrafikowOstatecznych::odczytajMiesiac(int m) {
    QString s("");
    switch (m) {
    case 1: s = "styczeń"; break;
        case 2: s = "luty"; break;
    case 3: s = "marzec"; break;
    case 4: s = "kwiecień"; break;
        case 5: s = "maj"; break;
    case 6: s = "czerwiec"; break;
    case 7: s = "lipiec"; break;
    case 8: s = "sierpień"; break;
        case 9: s = "wrzesień"; break;
        case 10: s = "październik"; break;
        case 11: s = "listopad"; break;
    case 12: s = "grudzień"; break;
            default: s = "nie-wiadomo-jaki"; break;
    }
    return s;
}

bool PPrzegladanieGrafikowOstatecznych::zapiszJakoPDF(QString f) {
    if (aktualnyGrafik == nullptr) {
        return false;
    }
    QString miesiacRok = odczytajMiesiac(aktualnyGrafik->miesiac) + " " + QString::number(aktualnyGrafik->rok);
    QString html("<center><table border=\"1\" align=\"center\">");
    html += "<caption>Lista dyżurowa na " + miesiacRok + ": </caption>";
            html += "<tr><th><b>Dzień</b></th><th><b>Dzień Tygodnia</b></th><th><b>Lekarz Dyżurny</b></th></tr>";
    for (auto it = aktualnyGrafik->listaPozycjiGrafiku->begin(); it<aktualnyGrafik->listaPozycjiGrafiku->end(); ++it) {
        if ((*it)->dzienTygodnia == "sobota") {
            html += "<tr bgcolor=\"grey\">";
        }
        else if ((*it)->czySwieto) {
            html += "<tr bgcolor=\"red\">";
        }
        else {
            html += "<tr>";
        }
        html += "<td>" + (*it)->dzien + "</td>";
        html += "<td>" + (*it)->dzienTygodnia + "</td>";
        html += "<td>" + (*it)->dyzurant + "</td>";
        html += "</tr>";
    }
    html += "</table></center>";

    QTextDocument document;
    document.setHtml(html);
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(f);
    document.print(&printer);
    return true;
}

PPrzegladanieGrafikowOstatecznych::~PPrzegladanieGrafikowOstatecznych() {
    if (uiPrzegladanieGrafikowOstatecznych != nullptr) {
        delete uiPrzegladanieGrafikowOstatecznych;
        uiPrzegladanieGrafikowOstatecznych = nullptr;
    }
    if (aktualnyGrafik != nullptr) {
        delete aktualnyGrafik;
        aktualnyGrafik = nullptr;
    }
    if (db != nullptr) {
        delete db;
        db = nullptr;
    }
}

