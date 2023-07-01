
#include "pdodawanienowegografiku.h"
#include "uidodawanienowegografikuwstep.h"
#include "mnowegrafiki.h"

PDodawanieNowegoGrafiku::PDodawanieNowegoGrafiku()
    : uiDodawanieNowegoGrafikuWstep(nullptr), mNoweGrafiki(nullptr) {
    mNoweGrafiki = new MNoweGrafiki();
    uiDodawanieNowegoGrafikuWstep = new UIDodawanieNowegoGrafikuWstep(this);
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
