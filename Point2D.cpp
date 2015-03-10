//
//  Point2D.cpp
//  projet_IA
//
//  Created by Quentin Vecchio on 16/02/2015.
//  Copyright (c) 2015 Quentin Vecchio. All rights reserved.
//

#include "Point2D.h"

Point2D::Point2D(const double x, const double y) {
    this->x = x;
    this->y = y;
}

Point2D::Point2D(const Point2D &p) {
    this->x = p.x;
    this->y = p.y;
}

Point2D::~Point2D() {
    
}

double Point2D::getX() const {
    return this->x;
}

double Point2D::getY() const {
    return this->y;
}

void Point2D::setX(const double x) {
    this->x = x;
}

void Point2D::setY(const double y) {
    this->y = y;
}

const Point2D Point2D::operator - (const Point2D & u) const {
    return Point2D( this->x - u.x, this->y - u.y);
}

const Point2D Point2D::operator + (const Point2D & u) const {
    return Point2D( this->x+u.x, this->y+u.y);
}

const Point2D Point2D::operator * (const double & a) const{
      return Point2D( this->x*a, this->y*a);
}

const Point2D Point2D::operator * (const Point2D & u) const{
      return Point2D( this->x*u.x, this->y*u.y);
}

string Point2D::toString() const {
    ostringstream oss;
    oss << "( " << this->x << ", " << this->y << ")";
    return oss.str();
}

Point2D* Point2D::copy() const {
    return new Point2D(*this);
}

ostream &operator <<(ostream &os, const Point2D &p) {
    os << p.toString();
    return os;
}
