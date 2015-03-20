#ifndef MAIN_CPP
#define MAIN_CPP

#include <QApplication>
#include <iostream>
#include "TestUnitaire.h"

using namespace std;

int main(int argc, char * argv[]) {
    QApplication a(argc, argv);
    cout << "Projet Recherche et modelisation." << endl << "Programme fait par Dylan Koby et Quentin Vecchio" << endl << "Programme datant de 2015" << endl;
    testUnitaireInfoGraphe("/Users/quentinvecchio/Desktop/test.txt");
    cout << "Fini" << endl;
    return a.exec();
}

#endif
