#ifndef __projet_IA__InfoSommet__
#define __projet_IA__InfoSommet__

#include <iostream>
#include <sstream>

using namespace std;

class InfoSommet
{
private:
    string nom;
    int borneInfFenetre;
    int borneSupFenetre;

public:
    InfoSommet();
    InfoSommet(const string &nom, const int &borneInfFenetre, const int &borneSupFenetre);
    InfoSommet(const InfoSommet &info);
    ~InfoSommet();
    
    string getNom() const;
    int getBorneInfFenetre() const;
    int getBorneSupFenetre() const;

    void setNom(const string &s);
    void setBorneInfFenetre(const int &b);
    void setBorneSupFenetre(const int &b);

    string toString() const;
    InfoSommet* copy() const;
};

ostream &operator <<(ostream &os, const InfoSommet &i);
bool operator== (const InfoSommet s1, const InfoSommet s2);
#endif
