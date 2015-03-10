//
//  Erreur.h
//  projet_IA
//
//  Created by Quentin Vecchio on 19/02/2015.
//  Copyright (c) 2015 Quentin Vecchio. All rights reserved.
//

#ifndef __projet_IA__Erreur__
#define __projet_IA__Erreur__

#include <iostream>

using namespace std;

void Erreur(string s) {
    cout << s << endl;
}

void ErreurExit(string s) {
    cout << s << endl;
    exit(1);
}
#endif
