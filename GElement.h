#ifndef projet_IA_GElement_h
#define projet_IA_GElement_h

#include <iostream>
#include <sstream>

using namespace std;

class GElement
{
private:
    int clef;
protected:
    GElement(const int);
public:
    ~GElement();
    
    int getClef() const;
    void setClef(const int);
    
    virtual string toString() const;
};
ostream &operator <<(ostream &os, const GElement &e);

#endif
