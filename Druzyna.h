#ifndef DRUZYNA_H
#define DRUZYNA_H

#include <string>
using namespace std;

class Druzyna {
private:
	string nazwa;
	int sila;
	int punkty;
	int id;
	int bramki;
	int bilansBramek;

public:
	Druzyna(int id, string nazwa, int sila);

	string getNazwa() const;
	int getSila() const;
	int getPunkty() const;
	int getID() const;
	int getBramki() const;
	int getBilans() const;

	void dodajPunkty(int p);
	void dodajBramke(int b);
	void aktualizujBilansBramek(int bil);
	void aktualizujID(int noweID);
	void zerowanieBramek();
	void wyswietlDane() const;

};


#endif // !DRUZYNA_H
