
#include "pprzegladaniegrafikowroboczych.h"
#include "uiprzegladaniegrafikowroboczych.h"

PPrzegladanieGrafikowRoboczych::PPrzegladanieGrafikowRoboczych()
    : uiPrzegladanieGrafikowRoboczych(nullptr) {

}

void PPrzegladanieGrafikowRoboczych::wybranoSzukanieGrafikow(int miesiac, int rok) {
    
}
    
void PPrzegladanieGrafikowRoboczych::wybranoGrafikWLewo() {
    
}

void PPrzegladanieGrafikowRoboczych::wybranoGrafikWPrawo() {
    
}
 
void PPrzegladanieGrafikowRoboczych::wybranoZamkniecie() {
    
}

PPrzegladanieGrafikowRoboczych::~PPrzegladanieGrafikowRoboczych() {
    if (uiPrzegladanieGrafikowRoboczych != nullptr) {
        delete uiPrzegladanieGrafikowRoboczych;
        uiPrzegladanieGrafikowRoboczych = nullptr;
    }
}
