
#include "pdodawanienowegografiku.h"
#include "uidodawanienowegografikuwstep.h"
#include "mnowegrafiki.h"
#include "dto.h"

PDodawanieNowegoGrafiku::PDodawanieNowegoGrafiku()
    : uiDodawanieNowegoGrafikuWstep(nullptr), mNoweGrafiki(nullptr) {
    mNoweGrafiki = new MNoweGrafiki();
    std::vector<Miesiac> tabMiesiace;
    std::vector<DzienTygodnia> tabDniTygodnia;
    mNoweGrafiki -> wyciagnijTabliceMiesiecyIDniTygodnia(tabMiesiace, tabDniTygodnia);
    uiDodawanieNowegoGrafikuWstep = new UIDodawanieNowegoGrafikuWstep(tabMiesiace, tabDniTygodnia, this);
    uiDodawanieNowegoGrafikuWstep -> show();
}

PDodawanieNowegoGrafiku::~PDodawanieNowegoGrafiku() {
    if (mNoweGrafiki != nullptr) {
        delete mNoweGrafiki;
        mNoweGrafiki = nullptr;
    }
    if (uiDodawanieNowegoGrafikuWstep != nullptr) {
        delete uiDodawanieNowegoGrafikuWstep;
        uiDodawanieNowegoGrafikuWstep = nullptr;
    }
}
