#ifndef CRISTAL_H
#define CRISTAL_H

#include "Entitate.h"

class Cristal : public Entitate {
private:
    bool esteActivat;
    int energieRamasa;

public:
    Cristal(int x = 0, int y = 0) 
        : Entitate("Cristal Solar", x, y), esteActivat(false), energieRamasa(100) {}

    // Implementarea metodelor virtuale pure din Entitate
    void afisare(std::ostream& os) const override {
        os << "[CRISTAL] Pozitie: (" << x << "," << y << ") | Stare: " 
           << (esteActivat ? "ACTIVAT" : "DEZACTIVAT");
    }

    void interactioneaza() override {
        esteActivat = true;
        std::cout << "Lumina cristalului straluceste din nou!\n";
    }

    Entitate* clone() const override {
        return new Cristal(*this);
    }
};

#endif
