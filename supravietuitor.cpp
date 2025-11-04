#include "Supravietuitor.h"
#include <iostream>

// Constructor de initializare
Supravietuitor::Supravietuitor(const std::string& nume, int viata, int energie, 
                               int x, int y, bool cristal)
    : jucator(nume, viata, energie, x, y), areCristal(cristal), 
      puncteLumina(10), cristaleActivate(0) {
    initializeazaAbilitatiSpeciale();
}

// Functie privata pentru abilitati speciale
void Supravietuitor::initializeazaAbilitatiSpeciale() {
    // Supravietuitorii au abilitati defensive/luminoase
    jucator.getAbilitati().clear(); // Sterge abilitatile standard
    // Adauga abilitati specifice supravietuitorilor
}

// Activeaza cristal - FUNCTIE COMPLEXA
bool Supravietuitor::activeazaCristal() {
    if (jucator.getEnergie() >= 20 && !areCristal) {
        areCristal = true;
        puncteLumina += 15;
        cristaleActivate++;
        
        // Bonus la viata pentru activare cristal
        jucator.setViata(jucator.getViata() + 10);
        jucator.setEnergie(jucator.getEnergie() - 20);
        
        std::cout << "Cristal activat de " << jucator.getNume() 
                  << "! Cristale activate: " << cristaleActivate << std::endl;
        return true;
    }
    return false;
}

// Repara cristal
void Supravietuitor::reparaCristal() {
    if (areCristal && jucator.getEnergie() >= 10) {
        puncteLumina += 5;
        jucator.setEnergie(jucator.getEnergie() - 10);
        std::cout << jucator.getNume() << " a reparat cristalul!" << std::endl;
    }
}

// Calculeaza bonus lumina - FUNCTIE COMPLEXA
int Supravietuitor::calculeazaBonusLumina() const {
    int bonus = puncteLumina;
    
    // Bonus pentru cristale activate
    bonus += cristaleActivate * 5;
    
    // Bonus pentru viata mare
    if (jucator.getViata() > 80) {
        bonus += 10;
    }
    
    // Bonus pentru energie mare
    if (jucator.getEnergie() > 40) {
        bonus += 5;
    }
    
    return bonus;
}

// Operator <<
std::ostream& operator<<(std::ostream& os, const Supravietuitor& supravietuitor) {
    os << "=== SUPRAVIETUITOR ===\n"
       << supravietuitor.jucator
       << "Are cristal: " << (supravietuitor.areCristal ? "Da" : "Nu") << "\n"
       << "Puncte lumina: " << supravietuitor.puncteLumina << "\n"
       << "Cristale activate: " << supravietuitor.cristaleActivate << "\n"
       << "Bonus lumina: " << supravietuitor.calculeazaBonusLumina();
    return os;
}
