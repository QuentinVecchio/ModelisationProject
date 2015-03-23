#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Fenetre
{
private:
	int borneInf;
	int borneSup;
public:
	Fenetre(const int &inf, const int &sup);
	Fenetre(const Fenetre &fen);
	~Fenetre();

	int getBorneInf() const;
	int getBorneSup() const;

	void setBorneInf(const int &inf);
	void setBorneSup(const int &sup);

	string toString() const;
	Fenetre* copy() const;
};

ostream &operator <<(ostream &os, const Fenetre &fen);

