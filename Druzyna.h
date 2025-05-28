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

public:
	Druzyna(int id, string nazwa, int sila);

	string getNazwa() const;
	int getSila() const;
	int getPunkty() const;
	int getID() const;

	void dodajPunkty(int p);
	void wyswietlDane() const;

};


#endif // !DRUZYNA_H
