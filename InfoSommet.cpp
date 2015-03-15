#include "InfoSommet.h"

InfoSommet::InfoSommet(const string &nom, const int &borneInfFenetre, const int &borneSupFenetre) {
    this->nom = nom;
    this->borneInfFenetre = borneInfFenetre;
    this->borneSupFenetre = borneSupFenetre;
}

InfoSommet::InfoSommet() {
    this->nom = "NULL";
    this->borneInfFenetre = this->borneSupFenetre = 0;
}

InfoSommet::InfoSommet(const InfoSommet &info) {
    this->nom = info.getNom();
    this->borneInfFenetre = info.getBorneInfFenetre();
    this->borneSupFenetre = info.getBorneSupFenetre();
}

InfoSommet::~InfoSommet() {
    
}

string InfoSommet::getNom() const {
    return this->nom;
}

int InfoSommet::getBorneInfFenetre() const {
    return this->borneInfFenetre;
}

int InfoSommet::getBorneSupFenetre() const {
    return this->borneSupFenetre;
}

void InfoSommet::setNom(const string &s) {
    this->nom = s;
}

void InfoSommet::setBorneInfFenetre(const int &b) {
    this->borneInfFenetre = b;
}

void InfoSommet::setBorneSupFenetre(const int &b) {
    this->borneSupFenetre = b;
}

string InfoSommet::toString() const {
    ostringstream oss;
    oss <<  this->nom << ", borne Inf : " << this->borneInfFenetre << ", borne Sup : " << this->borneSupFenetre;
    return oss.str();
}

InfoSommet* InfoSommet::copy() const {
    return new InfoSommet(*this);
}

ostream &operator <<(ostream &os, const InfoSommet &i) {
    os << i.toString();
    return os;
}

bool operator== (const InfoSommet s1, const InfoSommet s2) {
    return (s1.getNom() == s2.getNom());
}
