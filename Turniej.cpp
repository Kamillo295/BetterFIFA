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
    miejsce = 1;
}

int Turniej::MojaDruzyna = 0;

bool Turniej::czyMeczJuzRozegrany(int id1, int id2) {
    for (auto& m : rozegraneMecze) {
        if ((m.first == id1 && m.second == id2) ||
            (m.first == id2 && m.second == id1)) {
            return true;
        }
    }
    return false;
}

void Turniej::naglowekTabeli() {
    cout << endl << string(20, '=') << " TABELA " << string(20, '=') << endl;
    cout << left
        << setw(3) << "ID" << " "
        << setw(20) << "Nazwa"
        << setw(10) << "Sila"
        << setw(10) << "Punkty" << endl;
    cout << string(45, '-') << endl;
}

void Turniej::wyswietlWybranaDruzyne() const {
    for (const auto& d : druzyny)
    {
        if (d.getID() == Turniej::MojaDruzyna)
        {
            cout << "Twoja wybrana druzyna: ";
            cout << d.getNazwa();
            cout <<", POWODZENIA!!!" << endl;
            return;
        }
    }
    cout << "Nie znaleziono druzyny o podanym ID. Nie bierzesz udzialu :(" << endl;
}

void Turniej::rozpocznij() {
    srand(time(NULL));

    Turniej::naglowekTabeli();
    for (auto& d : druzyny)
    {
        d.wyswietlDane();
    }
    cout << endl << "Wybierz id swojej druzyny: ";
    cin >> MojaDruzyna;

    while (MojaDruzyna == 2)
    {
        cout << "Zastanow sie jeszcze raz... ";
        cin >> MojaDruzyna;
    }

    wyswietlWybranaDruzyne();

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

    naglowekTabeli();

    // Kopia druzyn
    vector<Druzyna> posortowaneDruzyny = druzyny;

    // Sortowanie malej¹co po punktach
    sort(posortowaneDruzyny.begin(), posortowaneDruzyny.end(),
        [](const Druzyna& a, const Druzyna& b) {
            return a.getPunkty() > b.getPunkty();
        });

    // Wyœwietlanie
    for (const auto& d : posortowaneDruzyny) {
        cout << "(" << miejsce << ") ";
        d.wyswietlDane();
        miejsce++;
    }
}

