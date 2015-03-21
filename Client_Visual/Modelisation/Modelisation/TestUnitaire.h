#include "InfoGraphe.h"
#include "InfoSommet.h"
#include "InfoArete.h"
#include "Sommet.h"
#include "Arete.h"
#include "Graphe.h"
#include "InfoGraphe.h"
#include "ValeurArete.h"
#include "Fenetre.h"

void testUnitaireInfoSommet() {
	InfoSommet *info = new InfoSommet("test");
	info->addBorne(new Fenetre(0, 7));
	cout << *info << endl;
}

void testUnitaireInfoArete() {
	InfoArete *info = new InfoArete("arete1");
	info->addValeur(new ValeurArete(20, 10));
	cout << *info << endl;
}

void testUnitaireSommet() {
	Sommet<InfoSommet> *s = new Sommet<InfoSommet>(0, new InfoSommet("test"));
	s->getV()->addBorne(new Fenetre(0, 7));
	cout << *s << endl;
}

void testUnitaireArete() {
	Sommet<InfoSommet> *s1 = new Sommet<InfoSommet>(0, new InfoSommet("s1"));
	s1->getV()->addBorne(new Fenetre(0, 7));
	Sommet<InfoSommet> *s2 = new Sommet<InfoSommet>(1, new InfoSommet("s2"));
	s2->getV()->addBorne(new Fenetre(2, 7));
	Arete<InfoArete, InfoSommet> *a = new Arete<InfoArete, InfoSommet>(2, s1, s2, new InfoArete("arete1"));
	a->getV()->addValeur(new ValeurArete(20, 10));
	cout << *a << endl;
}

void testUnitaireGraphe() {
	Graphe<InfoArete, InfoSommet> *g = new Graphe<InfoArete, InfoSommet>();
	Sommet<InfoSommet> *s1 = g->creeSommet(new InfoSommet("s1"));
	s1->getV()->addBorne(new Fenetre(0, 7));
	Sommet<InfoSommet> *s2 = g->creeSommet(new InfoSommet("s2"));
	s2->getV()->addBorne(new Fenetre(2, 7));
	Arete<InfoArete, InfoSommet> *a = g->creeArete(s1, s2, new InfoArete("arete1"));
	a->getV()->addValeur(new ValeurArete(20, 10));
	cout << *g << endl;
}

void testUnitaireInfoGraphe(const char *lien) {
	InfoGraphe *g = new InfoGraphe(lien);
	cout << *g << endl;
	//PElement<Sommet<InfoSommet> > *chemin = InfoGraphe::algorithmeACorrectionEtiquette(g);
	//cout << *chemin << endl;
}
