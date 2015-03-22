#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "Fenetre.h"
#include "Etiquette.h"

using namespace std;

class InfoSommet
{
private:
	string nom;
	vector<Fenetre *> *bornes;
	vector<Etiquette *> *etiquettes;

public:
	InfoSommet();
	InfoSommet(const string &nom);
	InfoSommet(const InfoSommet &info);
	~InfoSommet();

	string getNom() const;
	Fenetre* getBorneAtId(const int &id) const;
	Etiquette* getEtiquetteAtId(const int &id) const;
	vector<Fenetre *>* getBornes() const;
	vector<Etiquette *>* getEtiquettes() const;

	void setNom(const string &s);
	void setBorneAtId(const int &id, Fenetre *f);
	void setEtiquetteAtId(const int &id, Etiquette *e);
	void setEtiquettes(vector<Etiquette *> *etiquettes);

	void addBorne(Fenetre *f);
	void addEtiquette(Etiquette *);
	void removeBorneAtId(const int &id);
	void removeBorneAll();
	void removeEtiquetteAtId(const int &id);
	void removeEtiquetteAll();
	int nbBornes() const;
	int nbEtiquette() const;

	string toString() const;
	InfoSommet* copy() const;
};

ostream &operator <<(ostream &os, const InfoSommet &i);
bool operator== (const InfoSommet s1, const InfoSommet s2);


