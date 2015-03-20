#pragma once
#include <vector>
#include "Etiquette.h"

using namespace std;

vector<string>* splitString(const string &chaine, const char &separateur) {
	vector<string> *strings = new vector<string>();
	string newChaine = "";
	for (int i = 0; i < chaine.length(); i++) {
		if (chaine[i] != separateur) {
			newChaine += chaine[i];
		}
		else {
			if (newChaine != " " || newChaine != "") {
				strings->push_back(newChaine);
			}
			newChaine = "";
		}
	}
	if (newChaine != " " || newChaine != "") {
		strings->push_back(newChaine);
	}
	return strings;
}

string enleveEspace(const string &s) {
	string newS;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			newS += s[i];
		}
	}
	return newS;
}

string extraitStringDansIntervalle(const string &s, const int &borneInf, const int &borneSup) {
	string newS;
	for (int i = borneInf; i < borneSup; i++)
		newS += s[i];
	return newS;
}

bool contient(const string &chaine, const string &motCherche) {
	std::size_t found = chaine.find(motCherche);
	if (found != std::string::npos)
		return true;
	else
		return false;
}

bool isInVector(vector<Etiquette *>* ensemble, Etiquette * valeur) {
	for (int i = 0; i<ensemble->size(); i++) {
		if (ensemble->at(i) == valeur)
			return true;
	}
	return false;
}