#include "ValeurArete.h"

ValeurArete::ValeurArete(const int &cout, const int &temps) {
    this->cout = cout;
    this->temps = temps;
}

ValeurArete::ValeurArete(const ValeurArete &i) {
    this->cout = i.cout;
    this->temps = i.temps;
}

ValeurArete::~ValeurArete() {

}

int ValeurArete::getCout() const {
    return this->cout;
}

int ValeurArete::getTemps() const {
    return this->temps;
}

void ValeurArete::setCout(const int &cout) {
    this->cout = cout;
}

void ValeurArete::setTemps(const int &temps) {
    this->temps = temps;
}

string ValeurArete::toString() const {
    ostringstream oss;
    oss << "(" << this->cout << "," << this->temps << ")";
    return oss.str();
}

ValeurArete* ValeurArete::copy() const {
    return new ValeurArete(*this);
}

ostream &operator <<(ostream &os, const ValeurArete &i) {
    os << i.toString();
    return os;
}
