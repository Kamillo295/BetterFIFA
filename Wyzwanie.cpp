#include "Mecz.h"
#include "Turniej.h"
#include "Wyzwanie.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Penalty::Penalty(Druzyna* d1, Druzyna* d2)
    : Wyzwanie("Rzut karny", d1, d2) {
}

void Penalty::wypiszRodzajWyzwania() const {
    cout << "Rodzaj wyzwania: " << rodzaj << endl;
}

void Penalty::obron() {
    int gdzie = 0;
    cout << "Napisz cyfre miejsca w ktore chcesz sie rzucic: ";
    cout << R"(
    ----------------------------------------
    |                                      | 
    |                                      |
    |                                      |
    |                                      |
    |                                      |
    |                                      |
    |                                      |
    )";
    cin >> gdzie;
}

