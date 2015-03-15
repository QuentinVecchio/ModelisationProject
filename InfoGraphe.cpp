#include "InfoGraphe.h"
#include "Fonctions.h"

InfoGraphe::InfoGraphe(const char *lienVersFichier) {
    this->graphe = new Graphe<InfoArete, InfoSommet>();
    ifstream file(lienVersFichier);
    if(file) {
        string line;
        while(getline(file, line)) {
            if(enleveEspace(line) == "sectionSommets") {
                while(getline(file,line)) {
                    if(line == "") //On passe dans une nouvelle section
                        break;
                    else {
                        vector<string> *informations = splitString(line,' ');
                        cout << informations->size() << endl;
                        if(informations->size() != 3) {
                            cout << "Impossible de créer un sommet, fichier corrompu." << endl;
                            return;
                        } else {
                            string name = informations->at(0);
                            int bI = atoi((informations->at(1).c_str()));
                            int bS = atoi(informations->at(2).c_str());
                            this->graphe->creeSommet(InfoSommet(name, bI, bS));
                        }
                        cout << informations->at(0) << endl;
                    }
                }
            } else if (enleveEspace(line) == "sectionArcs") {
                cout << "ok" << endl;
                while(getline(file,line)) {
                    if(line == "") //On passe dans une nouvelle section
                        break;
                    else {
                        vector<string> *informations = splitString(line,' ');
                        if(informations->size() != 5) {
                            cout << "Impossible de créer une arete, fichier corrompu." << endl;
                            return;
                        } else {
                            string name = informations->at(0);
                            cout << "ici : " << informations->at(0) << endl;
                            Sommet<InfoSommet> * s1 = this->getSommetByValue(informations->at(1));
                            Sommet<InfoSommet> * s2 = this->getSommetByValue(informations->at(2));
                            if(s1 == NULL || s2 == NULL) {
                                cout << "Impossible de créer une arete, fichier corrompu." << endl;
                                return;
                            }
                            int cout = atoi((informations->at(3).c_str()));
                            int temps = atoi(informations->at(4).c_str());
                            this->graphe->creeArete(s1, s2, InfoArete(name, cout, temps));
                        }
                        cout << informations->at(0) << endl;
                    }
                }
            } else if (enleveEspace(line) == "source") {
                getline(file,line);
                if(this->getSommetByValue(enleveEspace(line)))
                    this->source = enleveEspace(line);
                else
                    cout << "La source n'est pas dans le graphe, fichier corrompu." << endl;
            } else if (enleveEspace(line) == "puit") {
                getline(file,line);
                if(this->getSommetByValue(enleveEspace(line)))
                    this->puit = enleveEspace(line);
                else
                    cout << "Le puit n'est pas dans le graphe, fichier corrompu." << endl;
            } else if (enleveEspace(line) == "sectionGraphe") {

            }
        }
    }
    else
        cout << "Fichier introuvable, creation du graphe impossible." << endl;
}

InfoGraphe::InfoGraphe(const InfoGraphe &i){
    this->graphe = i.graphe;
}

InfoGraphe::~InfoGraphe() {
    delete this->graphe;
}

Graphe<InfoArete, InfoSommet>* InfoGraphe::getGraphe() const {
    return this->graphe;
}

Sommet<InfoSommet>* InfoGraphe::getSource() const {
    return this->getSommetByValue(this->source);
}

Sommet<InfoSommet>* InfoGraphe::getPuit() const {
    return this->getSommetByValue(this->puit);
}

void InfoGraphe::setGraphe(Graphe<InfoArete, InfoSommet> *g) {
    this->graphe = g;
}

void InfoGraphe::setSource(Sommet<InfoSommet> *source) {
    this->source = source->getV().getNom();
}

void InfoGraphe::setPuit(Sommet<InfoSommet> *puit) {
    this->puit = puit->getV().getNom();
}

Sommet<InfoSommet>* InfoGraphe::getSommetByValue(const string &nom) {
    PElement<Sommet<InfoSommet> > *ptr = this->graphe->getListeSommets();
    while(ptr != NULL) {
        if(ptr->getV()->getV().getNom() == nom)
            return ptr->getV();
        ptr = ptr->getS();
    }
    return NULL;
}

string InfoGraphe::toString() const {
    ostringstream oss;
    oss <<  *this->graphe << endl;
    return oss.str();
}

InfoGraphe* InfoGraphe::copy() const {
    return new InfoGraphe(*this);
}

ostream &operator <<(ostream &os, const InfoGraphe &i) {
    os << i.toString();
    return os;
}
