#include "InfoArete.h"

InfoArete::InfoArete(const string &nom, const int &c, const int &t) {
    this->setCout(c);
    this->setNom(nom);
    this->setTemps(t);
}

InfoArete::InfoArete() {
    this->setCout(0);
}

InfoArete::InfoArete(const InfoArete &i) {
    this->cout = i.cout;
    this->name = i.name;
    this->temps = i.temps;
}

InfoArete::~InfoArete() {
    
}

string InfoArete::getNom() const {
    return this->name;
}

int InfoArete::getCout() const {
    return this->cout;
}

int InfoArete::getTemps() const {
    return this->temps;
}

void InfoArete::setNom(const string &name) {
    this->name = name;
}

void InfoArete::setCout(const int &cout) {
    if(cout >= 0)
        this->cout = cout;
}

void InfoArete::setTemps(const int &temps) {
    if(temps >= 0)
        this->temps = temps;
}

string InfoArete::toString() const {
    ostringstream oss;
    oss << this->name << " (" << this->cout << "," << this->temps << ")";
    return oss.str();
}

InfoArete* InfoArete::copy() const {
    return new InfoArete(*this);
}

ostream &operator <<(ostream &os, const InfoArete &i) {
    os << i.toString();
    return os;
}
