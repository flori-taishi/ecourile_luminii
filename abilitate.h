#ifndef ABILITATE_H
#define ABILITATE_H

#include <string>
#include <iostream>

class Abilitate {
private:
    std::string nume;
    int damage;
    int costEnergie;
    int cooldown;

public:
    // Constructor de initializare
    Abilitate(const std::string& nume = "", int damage = 0, int costEnergie = 0, int cooldown = 0);
    
    // Constructor de copiere
    Abilitate(const Abilitate& other);
    
    // Operator= de copiere
    Abilitate& operator=(const Abilitate& other);
    
    // Destructor
    ~Abilitate();

    // Getters const
    std::string getNume() const { return nume; }
    int getDamage() const { return damage; }
    int getCostEnergie() const { return costEnergie; }
    int getCooldown() const { return cooldown; }

    // Setters
    void setNume(const std::string& nume) { this->nume = nume; }
    void setDamage(int damage) { this->damage = damage; }
    void setCostEnergie(int cost) { this->costEnergie = cost; }
    void setCooldown(int cd) { this->cooldown = cd; }

    // Functii membre
    bool poateFiFolosita(int energieJucator) const;
    void foloseste();
    
    // Operator <<
    friend std::ostream& operator<<(std::ostream& os, const Abilitate& abilitate);
};

#endif
