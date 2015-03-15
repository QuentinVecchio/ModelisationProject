#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <vector>

using namespace std;

vector<string>* splitString(const string &chaine, const char &separateur) {
    vector<string> *strings = new vector<string>();
    string newChaine = "";
    for(int i = 0; i < chaine.length(); i++) {
        if(chaine[i] != separateur) {
            newChaine += chaine[i];
        } else {
            if(newChaine != " " || newChaine != "") {
                strings->push_back(newChaine);
            }
            newChaine = "";
        }
    }
    if(newChaine != " " || newChaine != "") {
        strings->push_back(newChaine);
    }
    return strings;
}

string enleveEspace(const string &s) {
    string newS;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != ' ') {
            newS += s[i];
        }
    }
    return newS;
}

#endif // FONCTIONS_H
