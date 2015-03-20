#pragma once
#include <iostream>
#include <sstream>

using namespace std;

template <class T>

class PElement
{
private:
	T *v;
	PElement<T> *s;
public:

	PElement<T>() {
		this->v = NULL;
		this->s = NULL;
	}

	PElement<T>(T *v) {
		this->v = v;
		this->s = NULL;
	}

	PElement<T>(T *v, PElement<T> *s) {
		this->v = v;
		this->s = s;
	}

	PElement<T>(const PElement<T>& e) {
		this->v = e.getV();
		this->s = e.getS();
	}

	T* getV() {
		return this->v;
	}

	void setV(T *v)  {
		if (v != NULL)
			this->v = v;
		else
			cout << "La valeur vaut NULL" << endl;
	}

	PElement<T> * getS() {
		return this->s;
	}

	void setS(PElement<T> *s) {
		this->s = s;
	}

	static int taille(const PElement<T> *l) {
		if (l == NULL)
			return 0;
		else
			return 1 + PElement<T>::taille(l->s);
	}

	/*
	*  position fonctionne comme dans un Array, position commence à partir de 0
	*/
	T * getByPosition(int pos) {
		T *r = NULL;
		PElement<T> *p = this;
		int i = 0;
		if (pos < taille(this) && pos >= 0)
		{
			while (p != NULL)
			{
				if (i == pos)
				{
					r = p->getV();
					break;
				}
				i++;
				p = p->getS();
			}
			return r;
		}
		else
			cout << "La position donnée n'existe pas." << endl;
		return NULL;
	}

	static const string toString(PElement<T> &l, const char *debut = "(", const char *separateur = ",", const char *fin = ")") {
		PElement<T> *l1;
		l1 = &l;
		string s = debut;
		while (l1 != NULL)
		{
			ostringstream oss;
			oss << *l1->v;
			s += oss.str();
			if (l1->s != NULL)
				s += *separateur;
			l1 = l1->s;
		}
		s += *fin;
		return s;
	}

	static void insertionOrdonnee(T *a, PElement<T> *&l, bool(*estPlusPetitouEgal)(const T *a1, const T *a2)) {
		if (!l || estPlusPetitouEgal(a, l->v))
			l = new PElement<T>(a, l);
		else
			PElement<T>::insertionOrdonnee(a, l->s, estPlusPetitouEgal);
	}

	static T* depiler(PElement<T> *&l) {
		if (l != NULL)
		{
			PElement<T> *e = l;
			T *v = e->v;
			l = e->s;
			delete e;
			return v;
		}
		else
			return NULL;
	}

	static bool retire(const T * a, PElement<T> *&l) {
		if (l != NULL)
		{
			if (l->getS()->getV() == a)
			{
				PElement<T> *e = l->getS();
				l->setS(e->getS());
				delete e;
				return true;
			}
			else
				return PElement<T>::retire(a, l->s);
		}
		else
			return false;
	}

	static void efface1(PElement<T> *&l) {
		if (l == NULL)
		{
			PElement<T>::efface1(l->s);
			delete l;
			l = NULL;
		}
	}

	static void efface2(PElement<T> *&l) {
		if (l == NULL)
		{
			PElement<T>::efface1(l->s);
			delete l->v;
			delete l;
			l = NULL;
		}
	}

	static bool appartient(const T *v, PElement<T> * &listV) {
		PElement<T> *p = listV;
		while (p != NULL)
		{
			if (p->v == v)
				return true;
			p = p->s;
		}
		return false;
	}
};

template <class T>
ostream &operator <<(ostream &os, PElement<T> &l) {
	os << PElement<T>::toString(l);
	return os;
}
