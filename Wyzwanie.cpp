#include "Mecz.h"
#include "Turniej.h"
#include "Wyzwanie.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Wyzwanie::Wyzwanie(string rodz, Druzyna* d1)
    : rodzaj(rodz), druzynaAktywna(d1) {
}

Penalty::Penalty(Druzyna* d1)
    : Wyzwanie("Rzut karny", d1) {
}

Celnosc::Celnosc(Druzyna* d1)
    : Wyzwanie("Gra na cela", d1) {

    pozycje = {
        "|X| | | | |",
        "| |X| | | |",
        "| | |X| | |",
        "| | | |X| |",
        "| | | | |X|"
    };
}



void Penalty::wypiszRodzajWyzwania() const {
    cout << endl << endl;
    cout << "Rodzaj wyzwania: " << rodzaj << endl;
}


void Penalty::obron() {

    int MijesceStrzalu = (rand() % 5) + 1;
    int gdzie = 0;
    cout << "Bronisz rzut karny" << endl;
    cout << R"(
    ----------------------------------------
    |            |            |            | 
    |      1     |            |      3     |
    |            |            |            |
    |------------|      5     |------------|
    |            |            |            |
    |      2     |            |      4     |
    |            |            |            |
    )";
    cout << "Napisz cyfre miejsca w ktore chcesz sie rzucic: ";
    cin >> gdzie;
    if (MijesceStrzalu == gdzie)
    {
        cout << "Strzal obroniony!" << endl;
    }
    else if (MijesceStrzalu == 6)
    {
        cout << "Karny nietrafiony!!!" << endl;
    }
    else
    {
        cout << "Tracisz bramke!" << endl;
        druzynaAktywna->dodajBramke(1);
    }
}

void Penalty::strzelaj() {

    int gdzie = (rand() % 5);
    int MijesceStrzalu = 0;
    cout << "Strzelasz rzut karny" << endl;
    cout << R"(
    ----------------------------------------
    |            |            |            | 
    |      1     |            |      3     |
    |            |            |            |
    |------------|      5     |------------|
    |            |            |            |
    |      2     |            |      4     |
    |            |            |            |
    )";
    cout << "Napisz cyfre miejsca w ktore chcesz sie oddac strzal: ";
    cin >> MijesceStrzalu;
    if (MijesceStrzalu == gdzie)
    {
        cout << "Strzal obroniony!" << endl;
    }
    else if (MijesceStrzalu > 5)
    {
        cout << "Karny nietrafiony!!!" << endl;
    }
    else
    {
        cout << "Zdobywasz bramke!" << endl;
        druzynaAktywna->dodajBramke(1);
    }
}

void Celnosc::wypiszRodzajWyzwania() const {
    cout << endl << endl;
    cout << "Rodzaj wyzwania: " << rodzaj << endl;
}

void Celnosc::wykonajStrzal() {
    cout << "Nacicnij Enter w momencie gdy X bêdzie na srodku!" << endl;

}

Wyzwanie::~Wyzwanie() {}
Penalty::~Penalty() {}
Celnosc::~Celnosc() {}

