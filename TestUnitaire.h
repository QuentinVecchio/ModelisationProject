#ifndef projet_IA_TestUnitaire_h
#define projet_IA_TestUnitaire_h

//#include "InfoGraphe.h"
#include "InfoSommet.h"
#include "InfoArete.h"
#include "Sommet.h"
#include "Arete.h"
#include "Graphe.h"
#include "InfoGraphe.h"

void testUnitaireInfoSommet() {
    InfoSommet *info = new InfoSommet("test", 0, 7);
    cout << *info << endl;
}

void testUnitaireInfoArete() {
    InfoArete *info = new InfoArete("arete1", 20, 10);
    cout << *info << endl;
}

void testUnitaireSommet() {
    Sommet<InfoSommet> *s = new Sommet<InfoSommet>(0, InfoSommet("test", 0, 7));
    cout << *s << endl;
}

void testUnitaireArete() {
    Sommet<InfoSommet> *s1 = new Sommet<InfoSommet>(0, InfoSommet("s1", 0, 7));
    Sommet<InfoSommet> *s2 = new Sommet<InfoSommet>(1, InfoSommet("s2", 2, 7));
    Arete<InfoArete, InfoSommet> *a = new Arete<InfoArete, InfoSommet>(2,s1,s2, InfoArete("arete1", 20, 10));
    cout << *a << endl;
}

void testUnitaireGraphe() {
    Graphe<InfoArete, InfoSommet> *g = new Graphe<InfoArete, InfoSommet>();
    Sommet<InfoSommet> *s1 = g->creeSommet(InfoSommet("s1", 0, 7));
    Sommet<InfoSommet> *s2 = g->creeSommet(InfoSommet("s2", 2, 7));
    Arete<InfoArete, InfoSommet> *a = g->creeArete(s1, s2, InfoArete("arete1", 20, 10));
    cout << *g << endl;
}

void testUnitaireInfoGraphe(const char *lien) {
    InfoGraphe *g = new InfoGraphe(lien);
    cout << *g << endl;
}

#endif
