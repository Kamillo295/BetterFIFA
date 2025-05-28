#include "Mecz.h"
#include "Turniej.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Mecz::Mecz(Druzyna* d1, Druzyna* d2)
    : druzyna1(d1), druzyna2(d2) {
}

void Mecz::rozegraj() {
    int silaD1 = druzyna1->getSila() + (rand() % 21);
    int silaD2 = druzyna2->getSila() + (rand() % 21);

    cout << druzyna1->getNazwa() << " [" << silaD1 << "] vs " 
         << druzyna2->getNazwa() << " [" << silaD2 << "]" << endl;

    if (druzyna1->getID() == Turniej::MojaDruzyna || druzyna2->getID() == Turniej::MojaDruzyna)
    {
        cout << "aaaaaaaa" << endl;
    }

    if (silaD1 > silaD2) {
        //std::cout << "Wygrywa: " << druzyna1->getNazwa() << "\n";
        druzyna1->dodajPunkty(3);
    }
    else if (silaD2 > silaD1) {
        //std::cout << "Wygrywa: " << druzyna2->getNazwa() << "\n";
        druzyna2->dodajPunkty(3);
    }
    else {
        //std::cout << "Remis!\n";
        druzyna1->dodajPunkty(1);
        druzyna2->dodajPunkty(1);
    }

    //std::cout << "------------------------------\n";
}
