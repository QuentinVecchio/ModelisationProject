#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class ValeurArete
{
private:
	int cout;
	int temps;
public:
	ValeurArete(const int &cout, const int &temps);
	ValeurArete(const ValeurArete &i);
	~ValeurArete();

	int getCout() const;
	int getTemps() const;

	void setCout(const int &cout);
	void setTemps(const int &temps);

	string toString() const;
	ValeurArete* copy() const;
};

ostream &operator <<(ostream &os, const ValeurArete &i);



