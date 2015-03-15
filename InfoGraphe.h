#ifndef __projet_IA__InfoGraphe__
#define __projet_IA__InfoGraphe__

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
     string source = "";
     string puit = "";
public:
    InfoGraphe(const char *lienVersFichier);
    InfoGraphe(const InfoGraphe &i);
    ~InfoGraphe();

    Graphe<InfoArete, InfoSommet> * getGraphe() const;
    Sommet<InfoSommet>* getSource() const;
    Sommet<InfoSommet>* getPuit() const;

    void setGraphe(Graphe<InfoArete, InfoSommet> *g);
    void setSource(Sommet<InfoSommet>* source);
    void setPuit(Sommet<InfoSommet>* puit);

    Sommet<InfoSommet>* getSommetByValue(const string &nom);
    string toString() const;
    InfoGraphe* copy() const;
};

ostream &operator <<(ostream &os, const InfoGraphe &i);
#endif
