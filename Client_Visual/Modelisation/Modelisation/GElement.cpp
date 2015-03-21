#include "GElement.h"

GElement::GElement(const int c) {
	this->setClef(c);
}

GElement::~GElement() {

}

int GElement::getClef() const {
	return this->clef;
}

void GElement::setClef(const int c) {
	this->clef = c;
}

string GElement::toString() const {
	ostringstream oss;
	oss << "Clef : " << this->getClef();
	return oss.str();
}

ostream &operator <<(ostream &os, const GElement &e) {
	os << e.toString();
	return os;
}
