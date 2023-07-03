
#ifndef PDODAWANIENOWEGOGRAFIKU_H
#define PDODAWANIENOWEGOGRAFIKU_H

class MNoweGrafiki;
class UIDodawanieNowegoGrafikuWstep;
class UIDodawanieNowegoGrafiku;
enum Miesiac : int;
enum DzienTygodnia : int;

class PDodawanieNowegoGrafiku {
public:
    PDodawanieNowegoGrafiku();
    ~PDodawanieNowegoGrafiku();
    void wybranoDodanieInformacjiWstepnychNowegoGrafiku(int r, int ld, Miesiac m, DzienTygodnia dt);
private:
    UIDodawanieNowegoGrafikuWstep* uiDodawanieNowegoGrafikuWstep;
    UIDodawanieNowegoGrafiku* uiDodawanieNowegoGrafiku;
    MNoweGrafiki* mNoweGrafiki;
};

#endif // PDODAWANIENOWEGOGRAFIKU_H
