
#include "uitworzonegrafiki.h"
#include "pdodawanienowegografiku.h"
#include "dto.h"

UITworzoneGrafiki::UITworzoneGrafiki(XGrafik* g, PDodawanieNowegoGrafiku* p) {
    setWindowTitle(tr("Podglad grafikow"));
    parent = p;

    listaOstateczni = new QListWidget(this);
    listaMozliwi = new QListWidget(this);
    listaUnikajacy = new QListWidget(this);
    listaMozliwiNieUnikajacy = new QListWidget(this);
    listaOstateczni -> addItem("OSTATECZNI");
    listaMozliwi -> addItem("MOŻLIWI");
    listaUnikajacy -> addItem("UNIKAJĄCY");
    listaMozliwiNieUnikajacy -> addItem("MOŻLIWI NIE UNIKAJĄCY");
    buttonOk = new QPushButton(tr("Jest dobrze"), this);
    buttonZle = new QPushButton(tr("Jest źle, poprawiamy"), this);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(listaOstateczni, 0, 0);
    mainLayout->addWidget(listaMozliwi, 0, 1);
    mainLayout->addWidget(listaUnikajacy, 0, 2);
    mainLayout->addWidget(listaMozliwiNieUnikajacy, 0, 3);
    mainLayout->addWidget(buttonOk, 1, 0);
    mainLayout->addWidget(buttonZle, 1, 1);

    setLayout(mainLayout);
    setFixedSize(800, 800);

    QObject::connect(buttonOk, SIGNAL(clicked()), this, SLOT(onButtonOkClicked()));
    QObject::connect(buttonZle, SIGNAL(clicked()), this, SLOT(onButtonZleClicked()));

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

void UITworzoneGrafiki::onButtonOkClicked() {
    parent->wybranoDecyzjeWarunkowPoczatkowychGrafiku(1);
    close();
}

void UITworzoneGrafiki::onButtonZleClicked() {
    parent->wybranoDecyzjeWarunkowPoczatkowychGrafiku(0);
    close();
}

