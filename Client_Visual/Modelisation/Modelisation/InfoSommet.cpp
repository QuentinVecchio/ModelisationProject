#include "InfoSommet.h"

InfoSommet::InfoSommet(const string &nom) {
	this->nom = nom;
	this->bornes = new vector<Fenetre *>();
	this->etiquettes = new vector<Etiquette *>();
}

InfoSommet::InfoSommet() {
	this->nom = "NULL";
	this->bornes = new vector<Fenetre *>();
	this->etiquettes = new vector<Etiquette *>();
}

InfoSommet::InfoSommet(const InfoSommet &info) {
	this->nom = info.getNom();
	this->bornes = info.bornes;
	this->etiquettes = info.etiquettes;
}

InfoSommet::~InfoSommet() {
	this->bornes->clear();
	this->etiquettes->clear();
}

string InfoSommet::getNom() const {
	return this->nom;
}

vector<Fenetre *>* InfoSommet::getBornes() const {
	return this->bornes;
}

vector<Etiquette *>* InfoSommet::getEtiquettes() const {
	return this->etiquettes;
}

Fenetre* InfoSommet::getBorneAtId(const int &id) const {
	if (id >= 0 && id < this->bornes->size())
		return this->bornes->at(id);
	else
		return NULL;
}

Etiquette* InfoSommet::getEtiquetteAtId(const int &id) const {
	if (id >= 0 && id < this->etiquettes->size())
		return this->etiquettes->at(id);
	else
		return NULL;
}

int InfoSommet::nbBornes() const {
	return this->bornes->size();
}

int InfoSommet::nbEtiquette() const {
	return this->etiquettes->size();
}

void InfoSommet::setNom(const string &s) {
	this->nom = s;
}

void InfoSommet::setEtiquettes(vector<Etiquette *> *etiquettes){
	if (etiquettes != NULL)
		this->etiquettes = etiquettes;
}

void InfoSommet::setBorneAtId(const int &id, Fenetre *f) {
	if (id >= 0 && id < this->bornes->size() && f != NULL)
		this->bornes->at(id) = f;
}

void InfoSommet::setEtiquetteAtId(const int &id, Etiquette *e) {
	if (id >= 0 && id < this->etiquettes->size() && e != NULL)
		this->etiquettes->at(id) = e;
}

void InfoSommet::addBorne(Fenetre *f) {
	if (f != NULL)
		this->bornes->push_back(f);
}

void InfoSommet::addEtiquette(Etiquette *e) {
	if (e != NULL)
		this->etiquettes->push_back(e);
}

void InfoSommet::removeBorneAtId(const int &id) {

}

void InfoSommet::removeEtiquetteAtId(const int &id) {

}

void InfoSommet::removeBorneAll() {
	this->bornes->clear();
}

void InfoSommet::removeEtiquetteAll() {
	this->etiquettes->clear();
}


string InfoSommet::toString() const {
	ostringstream oss;
	oss << this->nom << endl << "Bornes : " << endl;
	for (int i = 0; i < this->nbBornes(); i++)
		oss << *this->bornes->at(i) << " ";
	oss << endl << "Etiquettes : " << endl;
	for (int i = 0; i < this->nbEtiquette(); i++)
		oss << *this->etiquettes->at(i) << " ";
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
