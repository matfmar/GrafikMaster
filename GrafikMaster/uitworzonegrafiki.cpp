
#include "uitworzonegrafiki.h"
#include "dto.h"

UITworzoneGrafiki::UITworzoneGrafiki(XGrafik* g, QWidget *parent) : QMainWindow{parent} {
    setWindowTitle(tr("Podglad grafikow"));
    mainWidget = new QWidget(this);

    listaOstateczni = new QListWidget(this);
    listaMozliwi = new QListWidget(this);
    listaUnikajacy = new QListWidget(this);
    listaMozliwiNieUnikajacy = new QListWidget(this);
    listaOstateczni -> addItem("OSTATECZNI");
    listaMozliwi -> addItem("MOŻLIWI");
    listaUnikajacy -> addItem("UNIKAJĄCY");
    listaMozliwiNieUnikajacy -> addItem("MOŻLIWI NIE UNIKAJĄCY");
    mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(listaOstateczni);
    mainLayout->addWidget(listaMozliwi);
    mainLayout->addWidget(listaUnikajacy);
    mainLayout->addWidget(listaMozliwiNieUnikajacy);
    mainWidget -> setLayout(mainLayout);
    setCentralWidget(mainWidget);
    setFixedSize(800, 800);

    grafik = g;
    std::vector<XDzien*> tablicaDni = grafik->udostepnijTabliceDni();
    for (auto it = tablicaDni.begin(); it < tablicaDni.end(); ++it) {
        listaOstateczni->addItem(QString::number((*it)->liczbaDnia) + ". " + zwrocDyzurantaOstatecznego((*it)->dyzurantWybrany));
        listaMozliwi->addItem(QString::number((*it)->liczbaDnia) + ". " + zwrocLancuchWynikowy((*it)->mozliwiDyzuranci));
        listaUnikajacy->addItem(QString::number((*it)->liczbaDnia) + ". " + zwrocLancuchWynikowy((*it)->unikajacyDyzuranci));
        listaMozliwiNieUnikajacy->addItem(QString::number((*it)->liczbaDnia) + ". " + zwrocLancuchWynikowy((*it)->mozliwiNieUnikajacyDyzuranci));
    }

}

QString UITworzoneGrafiki::zwrocLancuchWynikowy(std::map<int, XDyzurantTworzacy*> mapa) {
    auto it = mapa.begin();
    QString s("");
    while (it != mapa.end()) {
        s = s + QString::fromStdString(it->second->getNick()) + ", ";
        ++it;
    }
    return s;
}

QString UITworzoneGrafiki::zwrocDyzurantaOstatecznego(XDyzurantTworzacy* dt) {
    if (dt == nullptr) {
        return "";
    }
    return QString::fromStdString(dt->getNick());
}
