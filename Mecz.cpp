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
    int silaD1 = druzyna1->getSila();
    int silaD2 = druzyna2->getSila();

    cout << druzyna1->getNazwa() << " [" << silaD1 << "] vs " 
         << druzyna2->getNazwa() << " [" << silaD2 << "]" << endl;

    int iloscZdarzen = (rand() % 7) + 2;

    if (druzyna1->getID() == Turniej::MojaDruzyna || druzyna2->getID() == Turniej::MojaDruzyna)
    {
        for (int i = 0; i < iloscZdarzen; i++)
        {
            silaD1 = druzyna1->getSila() + (rand() % 21);
            silaD2 = druzyna2->getSila() + (rand() % 21);

            if (silaD1 > silaD2) {
                druzyna1->dodajBramke(1);
            }
            else {
                druzyna2->dodajBramke(1);
            }
        }

        int bramkiD1 = druzyna1->getBramki();
        int bramkiD2 = druzyna2->getBramki();

        if (bramkiD1 > bramkiD2) {
            cout << "Wygrywa: " << druzyna1->getNazwa() << "\t" << bramkiD1 << " : " << bramkiD2 << endl;
            druzyna1->dodajPunkty(3);
            int binals = bramkiD1 - bramkiD2;
            druzyna1->aktualizujBilansBramek(binals);
            druzyna2->aktualizujBilansBramek(binals * (-1));
        }
        else if (bramkiD2 > bramkiD1) {
            cout << "Wygrywa: " << druzyna2->getNazwa() << "\t" << bramkiD2 << " : " << bramkiD1 << endl;
            druzyna2->dodajPunkty(3);
            int binals = bramkiD2 - bramkiD1;
            druzyna2->aktualizujBilansBramek(binals);
            druzyna1->aktualizujBilansBramek(binals * (-1));
        }
        else {
            cout << "Remis!" << "\t" << bramkiD1 << " : " << bramkiD2 << endl;
            druzyna1->dodajPunkty(1);
            druzyna2->dodajPunkty(1);
        }
        druzyna1->zerowanieBramek();
        druzyna2->zerowanieBramek();
    }
    else
    {
        for (int i = 0; i < iloscZdarzen; i++)
        {
            silaD1 = druzyna1->getSila() + (rand() % 21);
            silaD2 = druzyna2->getSila() + (rand() % 21);

            if (silaD1 > silaD2) {
                druzyna1->dodajBramke(1);
            }
            else {
                druzyna2->dodajBramke(1);
            }
        }

        int bramkiD1 = druzyna1->getBramki();
        int bramkiD2 = druzyna2->getBramki();

        if (bramkiD1 > bramkiD2) {
            cout << "Wygrywa: " << druzyna1->getNazwa() << "\t" << bramkiD1 << " : " << bramkiD2 << endl;
            druzyna1->dodajPunkty(3);
            int binals = bramkiD1 - bramkiD2;
            druzyna1->aktualizujBilansBramek(binals);
            druzyna2->aktualizujBilansBramek(binals * (-1));
        }
        else if (bramkiD2 > bramkiD1) {
            cout << "Wygrywa: " << druzyna2->getNazwa() << "\t" << bramkiD2 << " : " << bramkiD1 << endl;
            druzyna2->dodajPunkty(3);
            int binals = bramkiD2 - bramkiD1;
            druzyna2->aktualizujBilansBramek(binals);
            druzyna1->aktualizujBilansBramek(binals * (-1));
        }
        else {
            cout << "Remis!" << "\t" << bramkiD1 << " : " << bramkiD2 << endl;
            druzyna1->dodajPunkty(1);
            druzyna2->dodajPunkty(1);
        }
        druzyna1->zerowanieBramek();
        druzyna2->zerowanieBramek();
    }

    

    cout << string(50, '-') << endl;
}
