//
//  Sommet.h
//  projet_IA
//
//  Created by Quentin Vecchio on 07/02/2015.
//  Copyright (c) 2015 Quentin Vecchio. All rights reserved.
//

#ifndef projet_IA_Sommet_h
#define projet_IA_Sommet_h

#include "GElement.h"

template <class T>

class Sommet : public GElement
{
private:
    int degre;
    T v;
public:
    Sommet<T>(const int clef, const T &v) : GElement(clef) {
        this->setDegre(0);
        this->setV(v);
    }
    
    Sommet<T>(const Sommet<T> &s) : GElement(s.getClef()) {
        this->setDegre(0);
        this->setV(s.v);
    }
    
    ~Sommet<T>() {
        
    }
    
    int getDegre() const {
        return this->degre;
    }
    
    T getV() const {
        return this->v;
    }
    
    void setDegre(const int degre) {
        this->degre = degre;
    }
    
    void setV(const T v) {
        this->v = v;
    }
    
    string toString() const {
        ostringstream oss;
        oss << "Clef : " << this->getClef() << ", Degré : " <<  this->getDegre() << ", Valeur : " << this->v << endl;
        return oss.str();
    }

    bool hasTheSameValue(const Sommet<T> * s) const {
        return this->v == s->v;
    }
};

template <class T>
bool operator== (Sommet<T> const *s1, Sommet<T> const *s2) {
    return (s1->getClef() == s2->getClef()) && (s1->getV() == s2->getV());
}
#endif
