#ifndef __projet_IA__InfoArete__
#define __projet_IA__InfoArete__

#include <iostream>
#include <sstream>

using namespace std;

class InfoArete
{
private:
    string name;
    int cout;
    int temps;
public:
    InfoArete();
    InfoArete(const string &nom, const int &c, const int &t);
    InfoArete(const InfoArete &i);
    ~InfoArete();

    string getNom() const;
    int getCout() const;
    int getTemps() const;

    void setNom(const string &name);
    void setCout(const int &cout);
    void setTemps(const int &temps);

    string toString() const;
    InfoArete* copy() const;
};

ostream &operator <<(ostream &os, const InfoArete &i);
#endif
