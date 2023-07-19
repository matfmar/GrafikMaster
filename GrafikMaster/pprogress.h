
#ifndef PPROGRESS_H
#define PPROGRESS_H


class UITworzenieProgress;

class PProgress {
public:
    PProgress();
    ~PProgress();
    void pokazOknoProgress();
    void setLabelOknoProgress(int ileGrafikow);
    void zamknijOknoProgress();
private:
    UITworzenieProgress* uiTworzenieProgress;
};

#endif // PPROGRESS_H
