#ifndef INFOARETEVALEUR_H
#define INFOARETEVALEUR_H

#include <iostream>
#include <sstream>

using namespace std;

class Etiquette
{
private:
    string predecesseur;
    int cout;
    int temps;
public:
    Etiquette(const string &pred, const int &cout, const int &temps);
    Etiquette(const Etiquette &i);
    ~Etiquette();

    string getPredecesseur() const;
    int getCout() const;
    int getTemps() const;

    void setPredecesseur(const string &pred);
    void setCout(const int &cout);
    void setTemps(const int &temps);

    string toString() const;
    Etiquette* copy() const;
};

ostream &operator <<(ostream &os, const Etiquette &i);
#endif // INFOARETEVALEUR_H
