#include "Entitate.h"

Entitate::Entitate(std::string nume, int x, int y) 
    : nume(nume), x(x), y(y) {}


Entitate::~Entitate() {}

std::ostream& operator<<(std::ostream& os, const Entitate& e) {
    e.afisare(os);
    return os;
}
