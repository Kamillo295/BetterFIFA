#ifndef TURNIEJ_H
#define TURNIEJ_H

#include "Druzyna.h"
#include "Mecz.h"
#include <vector>

class Turniej {
private:
    int miejsce;
    int MojaDruzyna;
    std::vector<Druzyna> druzyny;
    std::vector<std::pair<int, int>> rozegraneMecze;

    bool czyMeczJuzRozegrany(int id1, int id2);

public:
    Turniej();
    void rozpocznij();
    void wyswietlTabele();
};

#endif // TURNIEJ_H
