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

int Turniej::MojaDruzyna = 0;
int Turniej::IloscMeczy = 0;
int Turniej::DlugoscMeczy = 0;

void Turniej::naglowekTabeli() {
    cout << string(26, '=') << " TABELA " << string(26, '=') << endl;
    cout << left
        << setw(5) << "ID" << " "
        << setw(20) << "Nazwa"
        << setw(10) << "Sila"
        << setw(10) << "Punkty" 
        << setw(10) << "Bilans bramek"
        << endl;
    cout << string(60, '-') << endl;
}

void Turniej::wyswietlWybranaDruzyne() const {
    for (const auto& d : druzyny)
    {
        if (d.getID() == Turniej::MojaDruzyna)
        {
            cout << "Twoja wybrana druzyna: ";
            cout << d.getNazwa();
            cout << ", POWODZENIA!!!" << endl << endl << endl;
            return;
        }
    }
    cout << "Nie znaleziono druzyny o podanym ID. Nie bierzesz udzialu :(" << endl;
}

void Turniej::rozpocznij() {
    srand(time(NULL));

    Turniej::naglowekTabeli();
    for (auto& d : druzyny) {
        d.wyswietlDane();
    }

    cout << endl << "Wybierz id swojej druzyny: ";
    cin >> MojaDruzyna;

    while (MojaDruzyna == 2) {
        cout << "Zastanow sie jeszcze raz... ";
        cin >> MojaDruzyna;
    }

    cout << endl << "Wybierz ilosc meczy jaka chcesz zagrac (max 12): ";
    cin >> IloscMeczy;

    cout << endl << "Wybierz ile chcesz maksymalnie wydarzen na mecz: ";
    cin >> DlugoscMeczy;

    wyswietlWybranaDruzyne();

    const int MAX_MECZE = Turniej::IloscMeczy;
    vector<int> meczeNaDruzyne(druzyny.size(), 0);

    // Wygeneruj wszystkie mo¿liwe pary (i < j, ¿eby nie by³o duplikatów)
    vector<pair<int, int>> wszystkiePary;
    for (int i = 0; i < druzyny.size(); i++) {
        for (int j = i + 1; j < druzyny.size(); j++) {
            wszystkiePary.push_back({ i, j });
        }
    }

    // Przetasuj losowo wszystkie pary
    random_shuffle(wszystkiePary.begin(), wszystkiePary.end());

    // Rozgrywanie meczów z zachowaniem limitów
    for (auto& para : wszystkiePary) {
        int i = para.first;
        int j = para.second;

        if (meczeNaDruzyne[i] < MAX_MECZE && meczeNaDruzyne[j] < MAX_MECZE) {
            Mecz mecz(&druzyny[i], &druzyny[j]);
            mecz.rozegraj();
            rozegraneMecze.push_back({ i, j });
            meczeNaDruzyne[i]++;
            meczeNaDruzyne[j]++;
        }
    }
}


void Turniej::wyswietlTabele() {

    cout << endl;
    naglowekTabeli();

    // Kopia druzyn
    vector<Druzyna> posortowaneDruzyny = druzyny;

    // Sortowanie malej¹co po bilansie
    sort(posortowaneDruzyny.begin(), posortowaneDruzyny.end(),
        [](const Druzyna& a, const Druzyna& b) {
            return a.getBilans() > b.getBilans();
        });

    // Sortowanie malej¹co po punktach
    sort(posortowaneDruzyny.begin(), posortowaneDruzyny.end(),
        [](const Druzyna& a, const Druzyna& b) {
            return a.getPunkty() > b.getPunkty();
        });

    // Wyœwietlanie
    int noweID = 1;
    for (auto& d : posortowaneDruzyny) {
        d.aktualizujID(noweID);
        d.wyswietlDane();
        noweID++;
    }

    cout << "Zwyciezca turnieju: " << posortowaneDruzyny[0].getNazwa() << endl;
}

