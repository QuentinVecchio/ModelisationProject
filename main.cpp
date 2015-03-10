//
//  main.cpp
//  projet_IA
//
//  Created by Quentin Vecchio on 07/02/2015.
//  Copyright (c) 2015 Quentin Vecchio. All rights reserved.
//

#include <QApplication>
#include <iostream>
#include <fstream>
#include "PElement.h"
#include "Arete.h"
#include "Sommet.h"
#include "Graphe.h"
#include "TestUnitaire.h"

using namespace std;

int main(int argc, char * argv[]) {
     QApplication a(argc, argv);
    cout << "Projet Recherche et modelisation." << endl << "Programme fait par Dylan Koby et Quentin Vecchio" << endl << "Programme datant de 2015" << endl;
    return a.exec();
}
