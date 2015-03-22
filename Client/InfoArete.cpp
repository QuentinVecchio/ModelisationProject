#include "InfoArete.h"

InfoArete::InfoArete(const string &nom) {
    this->setNom(nom);
    this->valeurs = new vector<ValeurArete *>();
}

InfoArete::InfoArete() {
    this->setNom("");
    this->valeurs = new vector<ValeurArete *>();
}

InfoArete::InfoArete(const InfoArete &i) {
    this->name = i.name;
    this->valeurs = i.valeurs;
}

InfoArete::~InfoArete() {
    this->valeurs->clear();
}

string InfoArete::getNom() const {
    return this->name;
}

vector<ValeurArete *>* InfoArete::getValeurs() const {
    return this->valeurs;
}

ValeurArete* InfoArete::getValeurAtId(const int &id) const {
    if(id >=  0 && id < this->valeurs->size())
        return this->valeurs->at(id);
    else
        return NULL;
}

void InfoArete::setNom(const string &name) {
    this->name = name;
}

void InfoArete::setValeurAtId(const int &id, ValeurArete *i) {
    if(id >=  0 && id < this->valeurs->size() && i != NULL)
        this->valeurs->at(id) = i;
}

int InfoArete::nbValeurs() const {
    return this->valeurs->size();
}

void InfoArete::addValeur(ValeurArete *f) {
    if(f != NULL)
        this->valeurs->push_back(f);
}

void InfoArete::removeAtId(const int &id) {

}

void InfoArete::removeAll() {
    this->valeurs->clear();
}

string InfoArete::toString() const {
    ostringstream oss;
    oss << this->name << " ";
    for(int i = 0; i < this->nbValeurs(); i++)
        oss << *this->valeurs->at(i) << " ";
    return oss.str();
}

InfoArete* InfoArete::copy() const {
    return new InfoArete(*this);
}

ostream &operator <<(ostream &os, const InfoArete &i) {
    os << i.toString();
    return os;
}
