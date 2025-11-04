#include "Player.h"
#include <iostream>
#include <stdexcept>

// Constructor de initializare
Jucator::Jucator(const std::string& nume, int viata, int energie, int x, int y)
    : nume(nume), viata(viata), energie(energie), pozitieX(x), pozitieY(y) {
    initializeazaAbilitatiStandard();
}

// Constructor de copiere
Jucator::Jucator(const Jucator& other)
    : nume(other.nume), viata(other.viata), energie(other.energie),
      pozitieX(other.pozitieX), pozitieY(other.pozitieY), abilitati(other.abilitati) {
    std::cout << "Constructor copiere Jucator: " << nume << std::endl;
}

// Operator= de copiere
Jucator& Jucator::operator=(const Jucator& other) {
    if (this != &other) {
        nume = other.nume;
        viata = other.viata;
        energie = other.energie;
        pozitieX = other.pozitieX;
        pozitieY = other.pozitieY;
        abilitati = other.abilitati;
    }
    std::cout << "Operator= Jucator: " << nume << std::endl;
    return *this;
}

// Destructor
Jucator::~Jucator() {
    std::cout << "Destructor Jucator: " << nume << std::endl;
}

// Functie privata pentru initializare abilitati
void Jucator::initializeazaAbilitatiStandard() {
    abilitati.push_back(Abilitate("Atac Basic", 10, 5, 1));
    abilitati.push_back(Abilitate("Fortificare", 0, 10, 2));
    abilitati.push_back(Abilitate("Ultimul Sus", 25, 20, 5));
}

// Seteaza pozitia
void Jucator::setPozitie(int x, int y) {
    pozitieX = x;
    pozitieY = y;
}

// Verifica daca jucatorul este in viata
bool Jucator::esteInViata() const {
    return viata > 0;
}

// Deplasare pe harta
void Jucator::deplasare(int deltaX, int deltaY) {
    pozitieX += deltaX;
    pozitieY += deltaY;
    energie -= 1; // Consuma energie la deplasare
    if (energie < 0) energie = 0;
}

// Verifica daca poate folosi o abilitate
bool Jucator::poateFolosiAbilitate(int indexAbilitate) const {
    if (indexAbilitate < 0 || indexAbilitate >= abilitati.size()) {
        return false;
    }
    return abilitati[indexAbilitate].poateFiFolosita(energie);
}

// Foloseste o abilitate
void Jucator::folosesteAbilitate(int indexAbilitate) {
    if (indexAbilitate < 0 || indexAbilitate >= abilitati.size()) {
        throw std::out_of_range("Index abilitate invalid");
    }
    
    if (poateFolosiAbilitate(indexAbilitate)) {
        abilitati[indexAbilitate].foloseste();
        energie -= abilitati[indexAbilitate].getCostEnergie();
    }
}

// Operator <<
std::ostream& operator<<(std::ostream& os, const Jucator& jucator) {
    os << "Jucator: " << jucator.nume 
       << " | Viata: " << jucator.viata 
       << " | Energie: " << jucator.energie 
       << " | Pozitie: (" << jucator.pozitieX << "," << jucator.pozitieY << ")"
       << "\nAbilitati:\n";
    
    for (size_t i = 0; i < jucator.abilitati.size(); ++i) {
        os << "  " << i << ". " << jucator.abilitati[i] << "\n";
    }
    
    return os;
}
