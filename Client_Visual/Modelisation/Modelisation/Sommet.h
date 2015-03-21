#pragma once
#include "GElement.h"

template <class T>
class Sommet : public GElement
{
private:
	int degre;
	T *v;
public:
	Sommet<T>(const int clef, T *v) : GElement(clef) {
		this->setDegre(0);
		this->setV(v);
	}

	Sommet<T>(const Sommet<T> &s) : GElement(s.getClef()) {
		this->setDegre(0);
		this->setV(s.v);
	}

	~Sommet<T>() {

	}

	int getDegre() const {
		return this->degre;
	}

	T* getV() const {
		return this->v;
	}

	void setDegre(const int degre) {
		this->degre = degre;
	}

	void setV(T *v) {
		this->v = v;
	}

	string toString() const {
		ostringstream oss;
		oss << "Clef : " << this->getClef() << ", Degré : " << this->getDegre() << ", Valeur : " << *this->v << endl;
		return oss.str();
	}

	bool hasTheSameValue(const Sommet<T> * s) const {
		return this->v == s->v;
	}
};

template <class T>
bool operator == (Sommet<T> s1, Sommet<T> s2) {
	return (s1->getClef() == s2->getClef()) && (s1->getV() == s2->getV());
}

template <class T>
ostream &operator <<(ostream &os, const Sommet<T> &s){
	os << s.toString();
	return os;
}
