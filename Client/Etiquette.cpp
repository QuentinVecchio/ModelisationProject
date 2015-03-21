#include "Etiquette.h"

Etiquette::Etiquette(const string &pred, const int &cout, const int &temps) {
    this->predecesseur = pred;
    this->cout = cout;
    this->temps = temps;
}

Etiquette::Etiquette(const Etiquette &i) {
    this->predecesseur = i.predecesseur;
    this->cout = i.cout;
    this->temps = i.temps;
}

Etiquette::~Etiquette() {

}

string Etiquette::getPredecesseur() const {
    return this->predecesseur;
}

int Etiquette::getCout() const {
    return this->cout;
}

int Etiquette::getTemps() const {
    return this->temps;
}

void Etiquette::setPredecesseur(const string &pred) {
    this->predecesseur = pred;
}

void Etiquette::setCout(const int &cout) {
    this->cout = cout;
}

void Etiquette::setTemps(const int &temps) {
    this->temps = temps;
}

string Etiquette::toString() const {
    ostringstream oss;
    oss << "(" << this->predecesseur << "," << this->cout << "," << this->temps << ")";
    return oss.str();
}

Etiquette* Etiquette::copy() const {
    return new Etiquette(*this);
}

ostream &operator <<(ostream &os, const Etiquette &i) {
    os << i.toString();
    return os;
}
