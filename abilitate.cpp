#include "Abilitate.h"


Abilitate::Abilitate(const std::string& nume, int damage, int costEnergie, int cooldown)
    : nume(nume), damage(damage), costEnergie(costEnergie), cooldown(cooldown) {}


Abilitate::Abilitate(const Abilitate& other)
    : nume(other.nume), damage(other.damage), costEnergie(other.costEnergie), cooldown(other.cooldown) {
    std::cout << "Constructor copiere Abilitate: " << nume << std::endl;
}


Abilitate& Abilitate::operator=(const Abilitate& other) {
    if (this != &other) {
        nume = other.nume;
        damage = other.damage;
        costEnergie = other.costEnergie;
        cooldown = other.cooldown;
    }
    std::cout << "Operator= Abilitate: " << nume << std::endl;
    return *this;
}


Abilitate::~Abilitate() {
    std::cout << "Destructor Abilitate: " << nume << std::endl;
}


bool Abilitate::poateFiFolosita(int energieJucator) const {
    return energieJucator >= costEnergie && cooldown == 0;
}


void Abilitate::foloseste() {
    std::cout << "Abilitate " << nume << " folosita!" << std::endl;
    cooldown = 3; 
}


std::ostream& operator<<(std::ostream& os, const Abilitate& abilitate) {
    os << "Abilitate: " << abilitate.nume 
       << " | Damage: " << abilitate.damage 
       << " | Cost: " << abilitate.costEnergie 
       << " | Cooldown: " << abilitate.cooldown;
    return os;
}
