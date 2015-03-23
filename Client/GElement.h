#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class GElement
{
private:
	int clef;
protected:
	GElement(const int);
public:
	virtual ~GElement();

	int getClef() const;
	void setClef(const int);

	virtual string toString() const;
};
ostream &operator <<(ostream &os, const GElement &e);

