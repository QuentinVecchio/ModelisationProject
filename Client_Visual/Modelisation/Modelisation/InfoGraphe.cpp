#include "InfoGraphe.h"
#include "Fonctions.h"

InfoGraphe::InfoGraphe(const char *lienVersFichier) {
	this->nbRessource = 0;
	this->puit = "";
	this->source = "";
	this->graphe = new Graphe<InfoArete, InfoSommet>();
	ifstream file(lienVersFichier);
	if (file) {
		string line;
		while (getline(file, line)) {
			if (enleveEspace(line) == "sectionSommets") {
				while (getline(file, line)) {
					getline(file, line);
					if (enleveEspace(line) == "") //On passe dans une nouvelle section 
						break;
					else {
						vector<string> *informations = splitString(line, ' ');
						cout << informations->size()  << endl;
						if (informations->size() != (1 + this->nbRessource * 2)) {
							cout << "Impossible de creer un sommet, fichier corrompu." << endl;
							return;
						}
						else {
							string name = informations->at(0);
							int i = 0;
							this->graphe->creeSommet(new InfoSommet(name));
							Sommet<InfoSommet> *s = this->getSommetByValue(informations->at(0));
							while (i != this->nbRessource) {
								int bI = atoi((informations->at(i * 2 + 1).c_str()));
								int bS = atoi(informations->at(i * 2 + 2).c_str());
								s->getV()->addBorne(new Fenetre(bI, bS));
								i++;
							}
						}
					}
				}
			}
			else if (enleveEspace(line) == "sectionArcs") {
				while (getline(file, line)) {
					getline(file, line);
					if (line == "") //On passe dans une nouvelle section
						break;
					else {
						vector<string> *informations = splitString(line, ' ');
						if (informations->size() != (3 + 2 * this->nbRessource)) {
							cout << "Impossible de créer une arete, fichier corrompu." << endl;
							return;
						}
						else {
							string name = informations->at(0);
							Sommet<InfoSommet> * s1 = this->getSommetByValue(informations->at(1));
							Sommet<InfoSommet> * s2 = this->getSommetByValue(informations->at(2));
							if (s1 == NULL || s2 == NULL) {
								cout << "Impossible de créer une arete, fichier corrompu." << endl;
								return;
							}
							Arete<InfoArete, InfoSommet> * are = this->graphe->creeArete(s1, s2, new InfoArete(name));
							int i = 0;
							while (i != this->nbRessource) {
								int c = atoi((informations->at(3 + i * 2).c_str()));
								int temps = atoi(informations->at(4 + i * 2).c_str());
								are->getV()->addValeur(new ValeurArete(c, temps));
								i++;
							}
						}
					}
				}
			}
			else if (enleveEspace(line) == "sources") {
				getline(file, line);
				getline(file, line);
				if (this->getSommetByValue(enleveEspace(line)))
					this->source = enleveEspace(line);
				else
					cout << "La source n'est pas dans le graphe, fichier corrompu." << endl;
			}
			else if (enleveEspace(line) == "puits") {
				getline(file, line);
				getline(file, line);
				if (this->getSommetByValue(enleveEspace(line)))
					this->puit = enleveEspace(line);
				else
					cout << "Le puit n'est pas dans le graphe, fichier corrompu." << endl;
			}
			else if (contient(line, "ressources") == true) {
				string res = "ressources";
				string resultat = extraitStringDansIntervalle(line, res.length(), line.length());
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
	if (n >= 0)
		this->nbRessource = n;
}

vector<PElement<Sommet<InfoSommet> >*>* InfoGraphe::algorithmeACorrectionEtiquette(InfoGraphe * ig) {
	//Déclarations des variables
	PElement<Sommet<InfoSommet> >* list = NULL;//LIST
	vector<PElement<Sommet<InfoSommet> >*>* chemins = new vector<PElement<Sommet<InfoSommet> >*>();//Chemin que l'on renvoit
	list = new PElement<Sommet<InfoSommet> >(ig->getSource(), list); //LIST←{xo};
	ig->getSource()->getV()->addEtiquette(new Etiquette("null", 0, 0));//ETIQ(o)←{"",0,0}
	while (PElement<Sommet<InfoSommet> >::taille(list) != 0) { //tant que LIST est pas vide faire
		cout << "Taille liste : " << PElement<Sommet<InfoSommet> >::taille(list) << endl;
		PElement<Sommet<InfoSommet> >::reverse(list);
		Sommet<InfoSommet>* xi = PElement<Sommet<InfoSommet> >::depiler(list);//Choisir xi ∈ LIST; LIST ← LIST − {xi};
		cout << "Sommet depile : " << xi->getV()->getNom() << endl;
		PElement< pair< Sommet<InfoSommet>*, Arete<InfoArete, InfoSommet>* > > *voisins = ig->graphe->adjacences(xi);
		while (voisins != NULL) { //pour tous les xj ∈ successeurs(xi) faire
			cout << "Voisin de " << xi->getV()->getNom() << " -> " << voisins->getV()->first->getV()->getNom() << endl;
			for (int index = 0; index<xi->getV()->nbEtiquette(); index++) { //pour tous les E ∈ ETIQ(i) faire
				int E0 = xi->getV()->getEtiquetteAtId(index)->getCout();
				int E1 = xi->getV()->getEtiquetteAtId(index)->getTemps();
				int vij = ig->graphe->getAreteParSommets(xi, voisins->getV()->first)->getV()->getValeurAtId(0)->getCout();
				int wij = ig->graphe->getAreteParSommets(xi, voisins->getV()->first)->getV()->getValeurAtId(0)->getTemps();
				int bj = voisins->getV()->first->getV()->getBorneAtId(0)->getBorneSup();//Borne sup du sommet xj
				int aj = voisins->getV()->first->getV()->getBorneAtId(0)->getBorneInf();//Borne inf du sommet xj
				cout << "E0 : " << E0 << " E1 : " << E1 << " vij : " << vij << " wij : " << wij << " bj : " << voisins->getV()->first->getV()->getBorneAtId(0)->getBorneSup() << endl;
				if ((E1 + wij) <= bj && (E1 + wij) >= aj) { //si E1 + wij ≤ bj et E1 + wij => aj alors
					Etiquette *E = new Etiquette(xi->getV()->getNom(), E0 + vij, E1 + wij);//E′ ←(E0 +vij,E1 +wij);
					voisins->getV()->first->getV()->addEtiquette(E);//ETIQ(j) ← Pareto(ET IQ(j) ∪ {E′});
					cout << "Size avant Pareto : " << voisins->getV()->first->getV()->nbEtiquette() << endl;
					voisins->getV()->first->getV()->setEtiquettes(ig->Pareto(voisins->getV()->first->getV()->getEtiquettes()));
					cout << "Size apres Pareto : " << voisins->getV()->first->getV()->nbEtiquette() << endl;
					if (isInVector(voisins->getV()->first->getV()->getEtiquettes(), E)) {
						if (PElement<Sommet<InfoSommet> >::appartient(voisins->getV()->first, list) == false) {
							cout << "ajout de " << voisins->getV()->first->getV()->getNom() << " dans la liste" << endl;
							list = new PElement<Sommet<InfoSommet> >(voisins->getV()->first, list);
						}	
					}
				}
			}
			voisins = voisins->getS();
		}
	}

	cout << endl << endl << endl;
	int nbMaxEtiquette = 0;
	PElement<Sommet<InfoSommet> > *sommets = ig->graphe->getListeSommets();
	while (sommets != NULL) {
		cout << "Etiquette du sommet " << sommets->getV()->getV()->getNom() << " : " << endl;
		if (sommets->getV()->getV()->nbEtiquette() > nbMaxEtiquette)
			nbMaxEtiquette = sommets->getV()->getV()->nbEtiquette();
		for (int i = 0; i < sommets->getV()->getV()->nbEtiquette(); i++) {
			cout << *sommets->getV()->getV()->getEtiquetteAtId(i) << endl;
		}
		cout << endl;
		sommets = sommets->getS();
	}
	for (int i = 0; i < nbMaxEtiquette; i++)
		chemins->push_back(NULL);

	parcour(ig->getPuit(), ig->getSource(), chemins, 0, ig);
	return chemins;
}

	
void InfoGraphe::parcour(Sommet<InfoSommet>* depart, Sommet<InfoSommet>* arrive, vector<PElement<Sommet<InfoSommet> >*>* chemins, int n, InfoGraphe * ig){
	chemins->at(n) = new PElement<Sommet<InfoSommet> >(depart, chemins->at(n));//Ajout du nouveau sommet dans le chemin
	Sommet<InfoSommet>* sommetAPrendre = NULL;//Projet sommet à visiter.
	if (depart->getV()->getNom() == arrive->getV()->getNom()) {
		cout << "fini" << endl;//On arrete on est à la fin.
	}
	else{
		for (int i = 0; i < depart->getV()->getEtiquettes()->size(); i++){
			sommetAPrendre = ig->getSommetByValue(depart->getV()->getEtiquetteAtId(i)->getPredecesseur());
			cout << "Sommet a visite : " << sommetAPrendre->getV()->getNom() << endl;
			parcour(sommetAPrendre, arrive, chemins, n+i, ig);
		}
	}
}

vector<Etiquette *>* InfoGraphe::Pareto(vector<Etiquette *>* ensemble) {
	vector<Etiquette *>* nouvelEnsemble = new vector<Etiquette *>();
	if (ensemble->size() == 1)
		return ensemble;
	for (int i = 0; i <ensemble->size(); i++) {
		for (int y = 0; y < ensemble->size(); y++) {
			if (i != y) {
				cout << "On traite i : " << *ensemble->at(i) << endl;
				cout << "On traite y : " << *ensemble->at(y) << endl;
				bool cas1 = ((ensemble->at(i)->getTemps() <= ensemble->at(y)->getTemps()) && (ensemble->at(i)->getCout() <= ensemble->at(y)->getCout())) == false;//Cas où (E0 < E'0) et (E1 < E'1)
				bool cas2 = true;//Cas où 
				if (cas1){
					if (isInVector(nouvelEnsemble, ensemble->at(y)) == false)
						nouvelEnsemble->push_back(ensemble->at(y));
					cout << "On ajoute : " << *ensemble->at(y)  << endl;
				}
			}
		}
	}
	return nouvelEnsemble;
}

Sommet<InfoSommet>* InfoGraphe::getSommetByValue(const string &nom) const {
	PElement<Sommet<InfoSommet> > *ptr = this->graphe->getListeSommets();
	while (ptr != NULL) {
		if (ptr->getV()->getV()->getNom() == nom)
			return ptr->getV();
		ptr = ptr->getS();
	}
	return NULL;
}

string InfoGraphe::toString() const {
	ostringstream oss;
	oss << *this->graphe << endl;
	return oss.str();
}

InfoGraphe* InfoGraphe::copy() const {
	return new InfoGraphe(*this);
}

ostream &operator <<(ostream &os, const InfoGraphe &i) {
	os << i.toString();
	return os;
}
