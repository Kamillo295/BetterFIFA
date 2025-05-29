#ifndef WYZWANIE_H
#define WYZWANIE_H

#include "Druzyna.h"

using namespace std;

class Wyzwanie {
protected:
	string rodzaj;		//karny, quiz, rzut wolny
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

#endif // !WYZWANIE_H
