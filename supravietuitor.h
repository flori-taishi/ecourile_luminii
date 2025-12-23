#ifndef SUPRAVIETUITOR_H
#define SUPRAVIETUITOR_H

#include "Player.h"

class Supravietuitor : public Jucator {
public:
    
    Supravietuitor(std::string nume, int x, int y) 
        : Jucator(nume, 100, 50, x, y) {}

  
    void afisare(std::ostream& os) const override {
        os << "[SUPRAVIETUITOR] " << nume << " | HP: " << viata 
           << " | Poz: (" << x << "," << y << ")";
    }

    void interactioneaza() override {
        std::cout << nume << " cauta resurse sau repara un cristal...\n";
    }

  
    Entitate* clone() const override {
        return new Supravietuitor(*this);
    }
};

#endif
