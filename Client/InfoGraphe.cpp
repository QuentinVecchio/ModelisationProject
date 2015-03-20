#include "InfoGraphe.h"
#include "Fonctions.h"

InfoGraphe::InfoGraphe(const char *lienVersFichier) {
    this->nbRessource = 0;
    this->puit = "";
    this->source = "";
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
                        if(informations->size() != (1 + this->nbRessource*2)) {
                            cout << "Impossible de créer un sommet, fichier corrompu." << endl;
                            return;
                        } else {
                            string name = informations->at(0);
                            int i = 0;
                            this->graphe->creeSommet(new InfoSommet(name));
                            Sommet<InfoSommet> *s = this->getSommetByValue(informations->at(0));
                            while(i != this->nbRessource) {
                                int bI = atoi((informations->at(i*2+1).c_str()));
                                int bS = atoi(informations->at(i*2+2).c_str());
                                s->getV()->addBorne(new Fenetre(bI,bS));
                                i++;
                            }
                        }
                    }
                }
            } else if (enleveEspace(line) == "sectionArcs") {
                while(getline(file,line)) {
                    if(line == "") //On passe dans une nouvelle section
                        break;
                    else {
                        vector<string> *informations = splitString(line,' ');
                        if(informations->size() != (3 + 2 * this->nbRessource)) {
                            cout << "Impossible de créer une arete, fichier corrompu." << endl;
                            return;
                        } else {
                            string name = informations->at(0);
                            Sommet<InfoSommet> * s1 = this->getSommetByValue(informations->at(1));
                            Sommet<InfoSommet> * s2 = this->getSommetByValue(informations->at(2));
                            if(s1 == NULL || s2 == NULL) {
                                cout << "Impossible de créer une arete, fichier corrompu." << endl;
                                return;
                            }
                            Arete<InfoArete, InfoSommet> * are = this->graphe->creeArete(s1, s2, new InfoArete(name));
                            int i = 0;
                            while(i != this->nbRessource) {
                                int c = atoi((informations->at(3+i*2).c_str()));
                                int temps = atoi(informations->at(4+i*2).c_str());
                                are->getV()->addValeur(new ValeurArete(c, temps));
                                i++;
                            }
                        }
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
            } else if (contient(line, "ressource") == true) {
                string res = "ressource";
                string resultat = extraitStringDansIntervalle(line,res.length(),line.length());
                this->nbRessource = atoi(resultat.c_str());
                cout << "Nombre de ressource : " << this->nbRessource << endl;
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

int InfoGraphe::getNbRessource() const {
    return this->nbRessource;
}

void InfoGraphe::setGraphe(Graphe<InfoArete, InfoSommet> *g) {
    this->graphe = g;
}

void InfoGraphe::setSource(Sommet<InfoSommet> *source) {
    this->source = source->getV()->getNom();
}

void InfoGraphe::setPuit(Sommet<InfoSommet> *puit) {
    this->puit = puit->getV()->getNom();
}

void InfoGraphe::setRessource(const int &n) {
    if(n >= 0)
        this->nbRessource = n;
}

PElement<Sommet<InfoSommet> >* InfoGraphe::algorithmeACorrectionEtiquette(InfoGraphe *ig) {
    //Déclarations des variables
    vector<Etiquette *>* etiq[ig->graphe->nombreSommets()];//ETIQ
    PElement<Sommet<InfoSommet> >* list = NULL;//LIST
    PElement<Sommet<InfoSommet> >* chemin = NULL;//LIST
    int i = 0;//Les clefs commence à 1
    for(int i = 0;i<ig->graphe->nombreSommets();i++) {
        etiq[i] = new vector<Etiquette *>(); //ETIQ(i) ← vide;
    }
    list = new PElement<Sommet<InfoSommet> >(ig->getSource(),list); //LIST←{xo};
    chemin = new PElement<Sommet<InfoSommet> >(ig->getSource(),chemin);
    etiq[ig->getSource()->getClef()]->push_back(new Etiquette("",0,0));//ETIQ(o)←{0}
    while(PElement<Sommet<InfoSommet> >::taille(list) != 0) { //tant que LIST est pas vide faire
        cout << "Taille liste : " << PElement<Sommet<InfoSommet> >::taille(list) << endl;
        Sommet<InfoSommet>* xi = PElement<Sommet<InfoSommet> >::depiler(list);//Choisir xi ∈ LIST; LIST ← LIST − {xi};
        Sommet<InfoSommet>* xd = NULL;
        cout << "Sommet depilé : " << xi->getV()->getNom() << endl;
        PElement< pair< Sommet<InfoSommet>*, Arete<InfoArete, InfoSommet>* > > *voisins = ig->graphe->adjacences(xi);
        i = xi->getClef();
        while(voisins != NULL) { //pour tous les xj ∈ successeurs(xi) faire
            for(int index = 0;index<etiq[i]->size();index++) { //pour tous les E ∈ ETIQ(i) faire
                int E0 = etiq[i]->at(index)->getCout();
                int E1 = etiq[i]->at(index)->getTemps();
                int vij = ig->graphe->getAreteParSommets(xi,voisins->getV()->first)->getV()->getValeurAtId(0)->getCout();
                int wij = ig->graphe->getAreteParSommets(xi,voisins->getV()->first)->getV()->getValeurAtId(0)->getTemps();
                cout << "E0 : " << E0 << " E1 : " << E1 << " vij : " << vij << " wij : " << wij  << " bj : " << voisins->getV()->first->getV()->getBorneAtId(0)->getBorneSup() << endl;
                if((E1 + wij) <= voisins->getV()->first->getV()->getBorneAtId(0)->getBorneSup()) { //si E1 + wij ≤ bj alors
                    Etiquette *E = new Etiquette(xi->getV()->getNom(),E0 + vij,E1 + wij);//E′ ←(E0 +vij,E1 +wij);
                    etiq[voisins->getV()->first->getClef()]->push_back(E);//ET IQ(j) ← Pareto(ET IQ(j) ∪ {E′});
                    cout << "Size avant Pareto : " << etiq[voisins->getV()->first->getClef()]->size() << endl;
                    etiq[voisins->getV()->first->getClef()] = ig->Pareto(etiq[voisins->getV()->first->getClef()]);
                    cout << "Size apres Pareto : " << etiq[voisins->getV()->first->getClef()]->size() << endl;
                    if(isInVector(etiq[voisins->getV()->first->getClef()], E)) {
                        cout << " ajoute" << endl;
                        list = new PElement<Sommet<InfoSommet> >(voisins->getV()->first,list);
                    }
                }
            }
            voisins = voisins->getS();
        }
        chemin = new PElement<Sommet<InfoSommet> >(xd,chemin);
    }
    return chemin;
}

vector<Etiquette *>* InfoGraphe::Pareto(vector<Etiquette *>* ensemble) {
    vector<Etiquette *>* nouvelEnsemble = new vector<Etiquette *>();
    if(ensemble->size() == 1)
        return ensemble;
    for(int i=0; i <ensemble->size(); i++) {
        for(int y=i; y < ensemble->size(); y++) {
            if(i != y) {
                if(((ensemble->at(i)->getTemps() < ensemble->at(y)->getTemps()) && (ensemble->at(i)->getCout()  < ensemble->at(y)->getCout())) == false)
                    nouvelEnsemble->push_back(ensemble->at(y));
            }
        }
    }
    return nouvelEnsemble;
}

Sommet<InfoSommet>* InfoGraphe::getSommetByValue(const string &nom) const {
    PElement<Sommet<InfoSommet> > *ptr = this->graphe->getListeSommets();
    while(ptr != NULL) {
        if(ptr->getV()->getV()->getNom() == nom)
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
