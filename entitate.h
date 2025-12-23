#ifndef ENTITATE_H
#define ENTITATE_H

#include <string>
#include <iostream>

class Entitate {
protected:
    std::string nume;
    int x, y;

public:
    // Constructor
    Entitate(std::string nume = "", int x = 0, int y = 0);

    // Destructor Virtual (OBLIGATORIU pentru Tema 2)
    virtual ~Entitate();

    // Metode Virtuale Pure (fac clasa abstracta)
    virtual void afisare(std::ostream& os) const = 0;
    virtual Entitate* clone() const = 0; 
    virtual void interactioneaza() = 0;

    // Getteri comuni
    std::string getNume() const { return nume; }
    int getX() const { return x; }
    int getY() const { return y; }
    
    // Operatorul << polimorfic
    friend std::ostream& operator<<(std::ostream& os, const Entitate& e);
};

#endif
