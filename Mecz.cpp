#include "Mecz.h"
#include "Turniej.h"
#include "Wyzwanie.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

Mecz::Mecz(Druzyna* d1, Druzyna* d2)
    : druzyna1(d1), druzyna2(d2) {
}

void Mecz::symulacja() {
    int iloscZdarzen = (rand() % Turniej::DlugoscMeczy);
    for (int i = 0; i < iloscZdarzen; i++)
    {
        int silaD1 = druzyna1->getSila() + (rand() % 21);
        int silaD2 = druzyna2->getSila() + (rand() % 21);

        int sumaSil = silaD1 + silaD2;
        int szansa = rand() % sumaSil;

        if (szansa < silaD1) {
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

void showRodzajWyzwania(Wyzwanie* wyzw) {
    wyzw->wypiszRodzajWyzwania();

    cout << "-----------------------\n";
}

int iloscMinut(int &podzial, int addMins) {
    cout << "Minuta: " << podzial << endl;
    podzial += addMins;
    return podzial;
}

void Mecz::rozegraj() {
    
    int silaD1 = druzyna1->getSila();
    int silaD2 = druzyna2->getSila();

    cout << druzyna1->getNazwa() << " [" << silaD1 << "] vs " 
         << druzyna2->getNazwa() << " [" << silaD2 << "]" << endl;

    int iloscZdarzen = (rand() % 7) + 2;

    if (druzyna1->getID() == Turniej::MojaDruzyna || druzyna2->getID() == Turniej::MojaDruzyna)
    {
        int iloscZdarzen = (rand() % Turniej::DlugoscMeczy);
        int minuta = 0;
        int podzialNaMinuty = 0;

        if (iloscZdarzen == 0)
            podzialNaMinuty = 0;

        else
            podzialNaMinuty = 90 / iloscZdarzen;

        int dodaneMinuty = podzialNaMinuty;
        for (int i = 0; i < iloscZdarzen; i++)
        {
            int silaD1 = druzyna1->getSila() + (rand() % 21);
            int silaD2 = druzyna2->getSila() + (rand() % 21);
            
            int sumaSil = silaD1 + silaD2;
            int szansa = rand() % sumaSil;
            iloscMinut(podzialNaMinuty, dodaneMinuty);
            //int rodzajWyzwania = (rand() % 2) + 1;
            int rodzajWyzwania = 2;
            cout << endl;

            switch (rodzajWyzwania)
            {
            case 1:
                if (druzyna1->getID() == Turniej::MojaDruzyna) {
                    if (szansa < silaD1) {
                        Penalty pen(druzyna1);
                        showRodzajWyzwania(&pen);
                        pen.strzelaj();
                    }
                    else {
                        Penalty pen(druzyna2);
                        showRodzajWyzwania(&pen);
                        pen.obron();
                    }
                }

                if (druzyna2->getID() == Turniej::MojaDruzyna) {
                    if (szansa < silaD2) {
                        Penalty pen(druzyna2);
                        showRodzajWyzwania(&pen);
                        pen.strzelaj();
                    }
                    else {
                        Penalty pen(druzyna1);
                        showRodzajWyzwania(&pen);
                        pen.obron();
                    }
                }
                break;
                
            case 2:

                if (druzyna1->getID() == Turniej::MojaDruzyna) {
                    if (szansa < silaD1) {
                        cout << "Twoja druzyna strzela!" << endl;
                        Celnosc cel(druzyna1, druzyna2);
                        cel.wykonajStrzal();
                    }
                    else {
                        cout << "Obron strzal przeciwnika!" << endl;
                        /*Celnosc cel(druzyna2, druzyna1);
                        cel.wykonajStrzal();*///
                    }
                }

                if (druzyna2->getID() == Turniej::MojaDruzyna) {
                    if (szansa < silaD2) {
                        cout << "Twoja druzyna strzela!" << endl;
                        Celnosc cel(druzyna2, druzyna1);
                        cel.wykonajStrzal();
                    }
                    else {
                        cout << "Obron strzal przeciwnika!" << endl;
                       /* Celnosc cel(druzyna1, druzyna2);
                        cel.wykonajStrzal();*/
                    }
                }
                break;

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
        Sleep(2000);
    }
    else
    {
        symulacja();
    }

    

    cout << string(50, '-') << endl;
}
