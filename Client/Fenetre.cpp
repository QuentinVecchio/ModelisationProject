#include "Fenetre.h"

Fenetre::Fenetre(const int &inf, const int &sup) {
    this->borneInf = inf;
    this->borneSup = sup;
}

Fenetre::Fenetre(const Fenetre &fen) {
    this->borneInf = fen.borneInf;
    this->borneSup = fen.borneSup;
}

Fenetre::~Fenetre(){

}

int Fenetre::getBorneInf() const {
    return this->borneInf;
}

int Fenetre::getBorneSup() const {
    return this->borneSup;
}

void Fenetre::setBorneInf(const int &inf) {
    this->borneInf = inf;
}

void Fenetre::setBorneSup(const int &sup) {
    this->borneSup = sup;
}

string Fenetre::toString() const {
    ostringstream oss;
    oss << "Borne Inferieur : " << this->borneInf << ", Borne Superieur : " << this->borneSup;
    return oss.str();
}
Fenetre* Fenetre::copy() const {
    return new Fenetre(*this);
}

ostream &operator <<(ostream &os, const Fenetre &fen) {
    os << fen.toString();
    return os;
}
