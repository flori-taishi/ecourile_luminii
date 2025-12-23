#include "Jucator.h"
#include <iostream>
#include <stdexcept>

// Clasa de exceptie custom
class EnergieInsuficienta : public std::runtime_error {
public:
    EnergieInsuficienta() : std::runtime_error("Eroare: Energie insuficienta pentru a folosi abilitatea!") {}
};

// Constructor de initializare
// Apelam constructorul clasei de baza Entitate(nume, x, y)
Jucator::Jucator(const std::string& nume, int viata, int energie, int x, int y)
    : Entitate(nume, x, y), viata(viata), energie(energie) {
    initializeazaAbilitatiStandard();
    std::cout << "Constructor Jucator apelat pentru: " << nume << std::endl;
}

// Constructor de copiere
Jucator::Jucator(const Jucator& other)
    : Entitate(other), viata(other.viata), energie(other.energie), abilitati(other.abilitati) {
    std::cout << "Constructor de copiere Jucator apelat pentru: " << nume << std::endl;
}

// Operator= de copiere (Cerinta Tema 2)
Jucator& Jucator::operator=(const Jucator& other) {
    if (this != &other) {
        // Apelam operatorul de atribuire din clasa de baza
        Entitate::operator=(other);
        this->viata = other.viata;
        this->energie = other.energie;
        this->abilitati = other.abilitati;
    }
    return *this;
}

// Destructor virtual
Jucator::~Jucator() {
    std::cout << "Destructor Jucator apelat pentru: " << nume << std::endl;
}

// Functii membre
void Jucator::deplasare(int deltaX, int deltaY) {
    // Folosim x si y mosteniti din Entitate (protected)
    this->x += deltaX;
    this->y += deltaY;
    std::cout << nume << " s-a deplasat la pozitia (" << x << ", " << y << ")\n";
}

bool Jucator::esteInViata() const {
    return viata > 0;
}

void Jucator::folosesteAbilitate(int indexAbilitate) {
    if (indexAbilitate < 0 || indexAbilitate >= (int)abilitati.size()) {
        throw std::out_of_range("Index abilitate invalid!");
    }

    // Exemplu de aruncare a exceptiei custom (Cerinta Tema 2)
    if (energie < 10) { 
        throw EnergieInsuficienta();
    }

    energie -= 10;
    std::cout << nume << " a folosit abilitatea " << abilitati[indexAbilitate].getNume() << std::endl;
}

void Jucator::initializeazaAbilitatiStandard() {
}
