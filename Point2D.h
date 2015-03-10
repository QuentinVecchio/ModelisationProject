//
//  Point2D.h
//  projet_IA
//
//  Created by Quentin Vecchio on 16/02/2015.
//  Copyright (c) 2015 Quentin Vecchio. All rights reserved.
//

#ifndef __projet_IA__Point2D__
#define __projet_IA__Point2D__

#include <iostream>
#include <sstream>

using namespace std;

class Point2D
{
private:
    double x;
    double y;
public:
    Point2D(const double x, const double y);
    Point2D(const Point2D &p);
    ~Point2D();
    
    double getX() const;
    double getY() const;
    void setX(const double x);
    void setY(const double y);
    
    string toString() const;
    Point2D* copy() const;

    const Point2D operator + (const Point2D & u) const;
    const Point2D operator * (const double & a) const;
    const Point2D operator - (const Point2D & u) const;
    const Point2D operator * (const Point2D & u) const;
};
ostream &operator <<(ostream &os, const Point2D &p);
#endif 
