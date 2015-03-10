//
//  InfoAreteCarte.cpp
//  projet_IA
//
//  Created by Quentin Vecchio on 16/02/2015.
//  Copyright (c) 2015 Quentin Vecchio. All rights reserved.
//

#include "InfoArete.h"

InfoAreteCarte::InfoAreteCarte(const double c) {
    this->setCout(c);
}

InfoAreteCarte::InfoAreteCarte() {
    this->setCout(0);
}

InfoAreteCarte::InfoAreteCarte(const InfoAreteCarte &i) {
    this->cout = i.cout;
}

InfoAreteCarte::~InfoAreteCarte() {
    
}

double InfoAreteCarte::getCout() const {
    return this->cout;
}

void InfoAreteCarte::setCout(const double cout) {
    if(cout >= 0.0)
        this->cout = cout;
}

string InfoAreteCarte::toString() const {
    ostringstream oss;
    oss << this->cout;
    return oss.str();
}

InfoAreteCarte* InfoAreteCarte::copy() const {
    return new InfoAreteCarte(*this);
}

ostream &operator <<(ostream &os, const InfoAreteCarte &i) {
    os << i.toString();
    return os;
}
