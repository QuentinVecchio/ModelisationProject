//
//  InfoSommetCarte.h
//  projet_IA
//
//  Created by Quentin Vecchio on 16/02/2015.
//  Copyright (c) 2015 Quentin Vecchio. All rights reserved.
//

#ifndef __projet_IA__InfoSommetCarte__
#define __projet_IA__InfoSommetCarte__

#include <iostream>
#include "Point2D.h"

using namespace std;

class InfoSommetCarte
{
private:
    string nom;
    Point2D *pos;
public:
    InfoSommetCarte();
    InfoSommetCarte(const string nom,Point2D *position);
    InfoSommetCarte(const InfoSommetCarte &info);
    ~InfoSommetCarte();
    
    string getNom() const;
    Point2D* getPosition() const;
    void setNom(const string s);
    void setPosition(const Point2D position);
    
    string toString() const;
    InfoSommetCarte* copy() const;
};

ostream &operator <<(ostream &os, const InfoSommetCarte &i);
bool operator== (const InfoSommetCarte s1, const InfoSommetCarte s2);
#endif
