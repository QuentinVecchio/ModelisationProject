//
//  InfoSommetCarte.cpp
//  projet_IA
//
//  Created by Quentin Vecchio on 16/02/2015.
//  Copyright (c) 2015 Quentin Vecchio. All rights reserved.
//

#include "InfoSommet.h"

InfoSommetCarte::InfoSommetCarte(const string nom, Point2D *position) {
    this->nom = nom;
    this->pos = position;
}

InfoSommetCarte::InfoSommetCarte() {
    this->nom = "NULL";
    this->pos = NULL;
}

InfoSommetCarte::InfoSommetCarte(const InfoSommetCarte &info) {
    this->nom = info.getNom();
    this->pos = info.getPosition();
}

InfoSommetCarte::~InfoSommetCarte() {
    
}

string InfoSommetCarte::getNom() const {
    return this->nom;
}

Point2D* InfoSommetCarte::getPosition() const {
    return this->pos;
}

void InfoSommetCarte::setNom(const string s) {
    this->nom = s;
}

void InfoSommetCarte::setPosition(const Point2D position) {
    this->pos = position.copy();
}

string InfoSommetCarte::toString() const {
    ostringstream oss;
    oss <<  this->nom << ", position : " << *(this->pos);
    return oss.str();
}

InfoSommetCarte* InfoSommetCarte::copy() const {
    return new InfoSommetCarte(*this);
}

ostream &operator <<(ostream &os, const InfoSommetCarte &i) {
    os << i.toString();
    return os;
}

bool operator== (const InfoSommetCarte s1, const InfoSommetCarte s2) {
    return (s1.getNom() == s2.getNom());
}
