#ifndef DRUZYNA_H
#define DRUZYNA_H

#include <string>
using namespace std;

class Druzyna {
private:
	string nazwa;
	int sila;
	int punkty;

public:
	Druzyna(string nazwa, int sila);

	string getNazwa() const;
	int getSila() const;
	int getPunkty() const;

	void dodajPunkty(int p);
	void wyswietlDane() const;

};


#endif // !DRUZYNA_H
