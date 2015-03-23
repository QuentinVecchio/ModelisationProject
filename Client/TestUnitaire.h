#include "InfoGraphe.h"
#include "InfoSommet.h"
#include "InfoArete.h"
#include "Sommet.h"
#include "Arete.h"
#include "Graphe.h"
#include "InfoGraphe.h"
#include "ValeurArete.h"
#include "Fenetre.h"

Sommet<InfoSommet>* depilageFifo(PElement<Sommet<InfoSommet> >*&list){
//	cout << "Depilage selon FIFO" << endl;
	PElement<Sommet<InfoSommet> >::reverse(list);
	return PElement<Sommet<InfoSommet> >::depiler(list);
}

Sommet<InfoSommet>* depilageClef(PElement<Sommet<InfoSommet> >*&list){
//	cout << "Depilage selon la clef" << endl;
	PElement<Sommet<InfoSommet> >* l;
	Sommet<InfoSommet> * min;
	min = list->getByPosition(0);
	for (l = list; l; l = l->getS()){
		if (l->getV()->getClef() < min->getClef()){
			min = l->getV();
		}
	}
	PElement<Sommet<InfoSommet> >::retire(min, list);
	return min;
}

Sommet<InfoSommet>* depilageNom(PElement<Sommet<InfoSommet> >*&list){
//	cout << "Depilage selon le nom" << endl;
	PElement<Sommet<InfoSommet> >* l;
	Sommet<InfoSommet> * min;
	min = list->getByPosition(0);
	for (l = list; l; l = l->getS()){
		if (l->getV()->getV()->getNom() < min->getV()->getNom()){
			min = l->getV();
		}
	}
	PElement<Sommet<InfoSommet> >::retire(min, list);
	return min;
}

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
    //vector<PElement<Sommet<InfoSommet> >*>* chemins = InfoGraphe::algorithmeACorrectionEtiquette(g, depilageFifo);
    //vector<PElement<Sommet<InfoSommet> >*>* chemins = InfoGraphe::algorithmeACorrectionEtiquette(g, depilageClef);
	//vector<PElement<Sommet<InfoSommet> >*>* chemins = InfoGraphe::algorithmeACorrectionEtiquette(g, depilageNom);
	//for (int i = 0; i < chemins->size();i++)
	//	cout << *chemins->at(i) << endl;
}

void testUnitaireListe() {
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	PElement<int> *liste = new PElement<int>(&a, new PElement<int>(&b, new PElement<int>(&c, new PElement<int>(&d, NULL))));
	cout << *liste << endl;
	PElement<int>::reverse(liste);
	cout << *liste << endl;
}
