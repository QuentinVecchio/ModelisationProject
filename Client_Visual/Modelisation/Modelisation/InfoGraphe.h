#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include "Graphe.h"
#include "InfoArete.h"
#include "InfoSommet.h"
#include "Sommet.h"
#include "PElement.h"

using namespace std;

class InfoGraphe
{
private:
	Graphe<InfoArete, InfoSommet> *graphe;
	string source;
	string puit;
	int nbRessource;
public:
	InfoGraphe(const char *lienVersFichier);
	InfoGraphe(const InfoGraphe &i);
	virtual ~InfoGraphe();

	Graphe<InfoArete, InfoSommet> * getGraphe() const;
	Sommet<InfoSommet>* getSource() const;
	Sommet<InfoSommet>* getPuit() const;
	int getNbRessource() const;

	void setGraphe(Graphe<InfoArete, InfoSommet> *g);
	void setSource(Sommet<InfoSommet>* source);
	void setPuit(Sommet<InfoSommet>* puit);
	void setRessource(const int &n);

	static vector<PElement<Sommet<InfoSommet> >*>* algorithmeACorrectionEtiquette(InfoGraphe * ig);
	static void parcour(Sommet<InfoSommet>* depart, Sommet<InfoSommet>* arrive, vector<PElement<Sommet<InfoSommet> >*>* chemins, int n, InfoGraphe * ig);
	vector<Etiquette *>* Pareto(vector<Etiquette *>* ensemble);
	Sommet<InfoSommet>* getSommetByValue(const string &nom) const;
	string toString() const;
	InfoGraphe* copy() const;
	static bool estPlusPetitOuEgalClef(const pair< Sommet<InfoSommet>*, Arete<InfoArete, InfoSommet>* > * p1, const pair< Sommet<InfoSommet>*, Arete<InfoArete, InfoSommet>* > * p2);
	static PElement< pair< Sommet<InfoSommet>*, Arete<InfoArete, InfoSommet>* > >  *voisinsSelonClef(Sommet<InfoSommet> * s);
	static bool estPlusPetitOuEgalNom(const pair< Sommet<InfoSommet>*, Arete<InfoArete, InfoSommet>* > * p1, const pair< Sommet<InfoSommet>*, Arete<InfoArete, InfoSommet>* > * p2);
	static PElement< pair< Sommet<InfoSommet>*, Arete<InfoArete, InfoSommet>* > >  *voisinsSelonNom(Sommet<InfoSommet> * s);
};

ostream &operator <<(ostream &os, const InfoGraphe &i);

