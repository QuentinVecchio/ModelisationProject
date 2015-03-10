//
//  Arete.h
//  projet_IA
//
//  Created by Quentin Vecchio on 07/02/2015.
//  Copyright (c) 2015 Quentin Vecchio. All rights reserved.
//

#ifndef projet_IA_Arete_h
#define projet_IA_Arete_h

#include "GElement.h"
#include "Sommet.h"

template <class S, class T>

class Arete : public GElement {
private:
    Sommet<T> *initial;
    Sommet<T> *final;
    S v;
public:
    Arete<S,T>(const int clef ,Sommet<T> *init, Sommet<T> *fin, const S v) : GElement(clef) {
        this->setInitial(init);
        this->initial->setDegre(this->initial->getDegre() + 1);
        this->setFinal(fin);
        this->final->setDegre(this->final->getDegre() + 1);
        this->setV(v);
    }
    
    Arete<S,T>(const Arete<S,T>& a) : GElement(a.getClef()) {
        this->setInitial(a.init);
        this->initial->setDegre(this->initial->getDegre() + 1);
        this->setFinal(a.init);
        this->final->setDegre(this->final->getDegre() + 1);
        this->setV(a.getV());
    }

    ~Arete<S,T>() {

    }
    
    bool estEgal(const Sommet<T> * s1, const Sommet<T> * s2) const {
        return (s1 == this->initial && s2 == this->final) || (s2 == this->initial && s1 == this->final);
    }
    
    S getV() const {
        return this->v;
    }
    
    void setV(const S v) {
        this->v  = v;
    }
    
    Sommet<T>* getInital() const {
        return this->initial;
    }
    
    void setInitial(Sommet<T> *s) {
        if(s != NULL)
            this->initial = s;
    }
    
    Sommet<T>* getFinal() const {
        return this->final;
    }
    
    void setFinal(Sommet<T> *s) {
        if(s != NULL)
            this->final = s;
    }
    
    string toString() const {
        ostringstream oss;
        oss << "Clef : " << this->getClef() << ", Sommet Inital : [" <<  *this->getInital() << "], Sommet Final : [" << *this->getFinal() << "] , Valeur : " << this->getV() << endl;
        return oss.str();
    }
};
#endif
