#ifndef MECZ_H
#define MECZ_H

#include "Druzyna.h"

class Mecz {
private:
    Druzyna* druzyna1;
    Druzyna* druzyna2;

public:
    Mecz(Druzyna* d1, Druzyna* d2);
    void rozegraj();
    void symulacja();
};

#endif // MECZ_H
