#ifndef WYZWANIE_H
#define WYZWANIE_H

#include "Druzyna.h"

using namespace std;

class Wyzwanie {
protected:
	string rodzaj;		//karny, quiz, celnosc
	Druzyna* druzynaAktywna;	

public:
	Wyzwanie(string rodz, Druzyna* d1);

	virtual void wypiszRodzajWyzwania() const = 0;

	virtual ~Wyzwanie();

};

class Penalty : public Wyzwanie {
public:
	Penalty(Druzyna* d1);

	void wypiszRodzajWyzwania() const override;
	void obron();
	void strzelaj();

	~Penalty() override;
};

class Celnosc : public Wyzwanie {
private:
	Druzyna* druzynaNieaktywna;
	vector<string> pozycje;

public:
	Celnosc(Druzyna* d1, Druzyna* d2);
	void wypiszRodzajWyzwania() const override;
	void wykonajStrzal();

	~Celnosc() override;
};

#endif // !WYZWANIE_H
