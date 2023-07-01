
#ifndef PDODAWANIENOWEGOGRAFIKU_H
#define PDODAWANIENOWEGOGRAFIKU_H

class MNoweGrafiki;

class UIDodawanieNowegoGrafikuWstep;

class PDodawanieNowegoGrafiku {
public:
    PDodawanieNowegoGrafiku();
    ~PDodawanieNowegoGrafiku();
private:
    UIDodawanieNowegoGrafikuWstep* uiDodawanieNowegoGrafikuWstep;
    MNoweGrafiki* mNoweGrafiki;
};

#endif // PDODAWANIENOWEGOGRAFIKU_H
