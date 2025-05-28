#include "Turniej.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

Turniej::Turniej() {
    druzyny = {
        Druzyna(1, "FC Barcelona", 90),
        Druzyna(2, "Real Madryt", 87),
        Druzyna(3, "Atletico Madryt", 80),
        Druzyna(4, "Manchester City", 85),
        Druzyna(5, "Manchester United", 70),
        Druzyna(6, "Liverpool FC", 90),
        Druzyna(7, "Inter Mediolan", 88),
        Druzyna(8, "Juventus", 83),
        Druzyna(9, "Bayern Monachium", 82),
        Druzyna(10, "Bayer Leverkusen", 80),
        Druzyna(11, "Chelsea Londyn", 75),
        Druzyna(12, "Napoli FC", 84),
        Druzyna(13, "AC Milan", 75),
        Druzyna(14, "Borussia Dortmund", 75),
        Druzyna(15, "PSG", 90),
        Druzyna(16, "LKS Przelom Kaniow", 30)
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

    for (auto& d : druzyny)
    {
        d.wyswietlDane();
    }
    cout << "Wybierz id swojej druzyny: ";
    cin >> MojaDruzyna;

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
    std::cout << "\n=== TABELA KONCOWA (POSORTOWANA) ===\n";
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
        std::cout << miejsce + 1 << ". ";
        d.wyswietlDane();
        miejsce++;
    }
}

