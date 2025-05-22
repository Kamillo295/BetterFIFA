#include "Turniej.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>

Turniej::Turniej() {
    druzyny = {
        Druzyna("FC Thunder", 85),
        Druzyna("Red Wolves", 80),
        Druzyna("Blue Sharks", 78),
        Druzyna("Golden Eagles", 90),
        Druzyna("Black Panthers", 88),
        Druzyna("White Bears", 76),
        Druzyna("Silver Foxes", 82),
        Druzyna("Green Dragons", 83),
        Druzyna("Iron Bulls", 79),
        Druzyna("Crimson Lions", 87),
        Druzyna("Purple Hawks", 81),
        Druzyna("Sky Kings", 77),
        Druzyna("Night Owls", 75),
        Druzyna("Fire Tigers", 86),
        Druzyna("Ocean Dolphins", 80),
        Druzyna("Desert Cobras", 84)
    };
}

bool Turniej::czyMeczJuzRozegrany(int id1, int id2) {
    for (auto& m : rozegraneMecze) {
        if ((m.first == id1 && m.second == id2) ||
            (m.first == id2 && m.second == id1)) {
            return true;
        }
    }
    return false;
}

void Turniej::rozpocznij() {
    srand(time(NULL));

    for (int i = 0; i < druzyny.size(); i++) {
        int meczeRozegrane = 0;

        while (meczeRozegrane < 4) 
        {
            int przeciwnik = rand() % druzyny.size();
            if (przeciwnik != i && !czyMeczJuzRozegrany(i, przeciwnik)) 
            {
                Mecz mecz(&druzyny[i], &druzyny[przeciwnik]);
                mecz.rozegraj();
                rozegraneMecze.push_back({ i, przeciwnik });
                meczeRozegrane++;
            }
        }
    }
}

void Turniej::wyswietlTabele() {
    std::cout << "\n=== TABELA KOÑCOWA (POSORTOWANA) ===\n";
    std::cout << std::left << std::setw(20) << "Nazwa"
        << std::setw(10) << "Sila"
        << std::setw(10) << "Punkty" << std::endl;
    std::cout << std::string(40, '-') << std::endl;

    // Kopia druzyn
    std::vector<Druzyna> posortowaneDruzyny = druzyny;

    // Sortowanie malej¹co po punktach
    std::sort(posortowaneDruzyny.begin(), posortowaneDruzyny.end(),
        [](const Druzyna& a, const Druzyna& b) {
            return a.getPunkty() > b.getPunkty();
        });

    // Wyœwietlanie
    for (const auto& d : posortowaneDruzyny) {
        d.wyswietlDane();
    }
}

