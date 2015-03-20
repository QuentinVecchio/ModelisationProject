#ifndef __projet_IA__InfoArete__
#define __projet_IA__InfoArete__

#include <iostream>
#include <sstream>
#include <vector>
#include "ValeurArete.h"

using namespace std;

class InfoArete
{
private:
    string name;
    vector<ValeurArete *> *valeurs;

public:
    InfoArete();
    InfoArete(const string &nom);
    InfoArete(const InfoArete &i);
    ~InfoArete();

    string getNom() const;
    ValeurArete* getValeurAtId(const int &id) const;
    vector<ValeurArete *>* getValeurs() const;

    void setNom(const string &name);
    void setValeurAtId(const int &id, ValeurArete *i);

    int nbValeurs() const;
    void addValeur(ValeurArete *f);
    void removeAtId(const int &id);
    void removeAll();
    string toString() const;
    InfoArete* copy() const;
};

ostream &operator <<(ostream &os, const InfoArete &i);
#endif
