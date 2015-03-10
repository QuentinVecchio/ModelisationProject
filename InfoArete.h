//
//  InfoAreteCarte.h
//  projet_IA
//
//  Created by Quentin Vecchio on 16/02/2015.
//  Copyright (c) 2015 Quentin Vecchio. All rights reserved.
//

#ifndef __projet_IA__InfoAreteCarte__
#define __projet_IA__InfoAreteCarte__

#include <iostream>
#include <sstream>

using namespace std;

class InfoAreteCarte
{
private:
    double cout;
public:
    InfoAreteCarte();
    InfoAreteCarte(const double c);
    InfoAreteCarte(const InfoAreteCarte &i);
    ~InfoAreteCarte();
    
    double getCout() const;
    void setCout(const double cout);
    
    string toString() const;
    InfoAreteCarte* copy() const;
};

ostream &operator <<(ostream &os, const InfoAreteCarte &i);
#endif
