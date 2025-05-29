#ifndef WYZWANIE_H
#define WYZWANIE_H

#include "Mecz.h"
#include "Druzyna.h"

using namespace std;

class Wyzwanie {
protected:
	string rodzaj;		//karny, quiz, rzut wolny
	Druzyna* druzyna1;	
	Druzyna* druzyna2;

public:
	Wyzwanie(string rodz, Druzyna* d1, Druzyna* d2)
		: rodzaj(rodz), druzyna1(d1), druzyna2(d2) {}

	virtual void wypiszRodzajWyzwania() const = 0;

	virtual ~Wyzwanie();

};

class Penalty : public Wyzwanie {
public:
	Penalty(Druzyna* d1, Druzyna* d2);

	void wypiszRodzajWyzwania() const override;
	void obron();
	void strzelaj();

	//~Penalty() override;
};

#endif // !WYZWANIE_H
