#include "Mecz.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Mecz::Mecz(Druzyna* d1, Druzyna* d2)
    : druzyna1(d1), druzyna2(d2) {
}

void Mecz::rozegraj() {
    int silaD1 = druzyna1->getSila() + (rand() % 21 - 10);
    int silaD2 = druzyna2->getSila() + (rand() % 21 - 10);

    std::cout << druzyna1->getNazwa() << " [" << silaD1 << "] vs "
        << druzyna2->getNazwa() << " [" << silaD2 << "]\n";

    if (silaD1 > silaD2) {
        std::cout << "Wygrywa: " << druzyna1->getNazwa() << "\n";
        druzyna1->dodajPunkty(3);
    }
    else if (silaD2 > silaD1) {
        std::cout << "Wygrywa: " << druzyna2->getNazwa() << "\n";
        druzyna2->dodajPunkty(3);
    }
    else {
        std::cout << "Remis!\n";
        druzyna1->dodajPunkty(1);
        druzyna2->dodajPunkty(1);
    }

    std::cout << "------------------------------\n";
}
