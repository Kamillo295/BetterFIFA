#ifndef TURNIEJ_H
#define TURNIEJ_H

#include "Druzyna.h"
#include "Mecz.h"
#include <vector>

class Turniej {
private:
    vector<Druzyna> druzyny;
    vector<pair<int, int>> rozegraneMecze;

public:
    static int MojaDruzyna;

    Turniej();
    void rozpocznij();
    void wyswietlTabele();
    void naglowekTabeli();
    void wyswietlWybranaDruzyne() const;
};

#endif // TURNIEJ_H
