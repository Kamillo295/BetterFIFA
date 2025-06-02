#ifndef QUIZ_H
#define QUIZ_H

#include "Druzyna.h"
#include <vector>
using namespace std;

class Quiz {
protected:
	string rodzaj;	 //otwarte, zamkniête
	string poprawnaOdpowiedz;

public:
	virtual ~Quiz();
	virtual void odczytajTyp() const = 0;
	virtual void odczytajPytanie() const = 0;
	virtual void sprawdzOdpowiedz() const = 0;

};


class PytanieZamkniete :public Quiz {
	vector<string> odpowiedzi;
	int indeks;
	string pytanie;
};







#endif // !QUIZ_H
