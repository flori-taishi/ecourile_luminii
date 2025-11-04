#include "Monstru.h"
#include "Supravietuitor.h"
#include <iostream>

// Constructor de initializare
Monstru::Monstru(const std::string& nume, int viata, int energie, 
                 int x, int y, int putereUmbra)
    : jucator(nume, viata, energie, x, y), putereUmbra(putereUmbra), 
      energieAbsorbita(0), esteInvizibil(false) {
    initializeazaAbilitatiIntuneric();
}

// Functie privata pentru abilitati intuneric
void Monstru::initializeazaAbilitatiIntuneric() {
    // Monștrii au abilitati offensive/umbră
    jucator.getAbilitati().clear(); // Sterge abilitatile standard
    // Adauga abilitati specifice monștrilor
}

// Absorbe energie - FUNCTIE COMPLEXA
void Monstru::absorbeEnergie(Supravietuitor& target) {
    if (!esteInvizibil && target.getJucator().getEnergie() > 0) {
        int energieAbsorbita = target.getJucator().getEnergie() / 3;
        
        this->energieAbsorbita += energieAbsorbita;
        jucator.setEnergie(jucator.getEnergie() + energieAbsorbita);
        putereUmbra += energieAbsorbita / 2;
        
        // Scade energia target-ului
        target.getJucator().setEnergie(target.getJucator().getEnergie() - energieAbsorbita);
        
        std::cout << jucator.getNume() << " a absorbit " << energieAbsorbita 
                  << " energie de la " << target.getJucator().getNume() << "!" << std::endl;
    }
}

// Devine invizibil
void Monstru::devineInvizibil() {
    if (jucator.getEnergie() >= 15 && !esteInvizibil) {
        esteInvizibil = true;
        jucator.setEnergie(jucator.getEnergie() - 15);
        std::cout << jucator.getNume() << " a devenit invizibil!" << std::endl;
    }
}

// Calculeaza putere atac - FUNCTIE COMPLEXA
int Monstru::calculeazaPutereAtac() const {
    int putere = putereUmbra;
    
    // Bonus pentru energie absorbita
    putere += energieAbsorbita / 5;
    
    // Bonus pentru invizibilitate
    if (esteInvizibil) {
        putere += 10;
    }
    
    // Bonus pentru viata scazuta (furia)
    if (jucator.getViata() < 30) {
        putere += 15;
    }
    
    return putere;
}

// Operator <<
std::ostream& operator<<(std::ostream& os, const Monstru& monstru) {
    os << "=== MONSTRU ===\n"
       << monstru.jucator
       << "Putere umbra: " << monstru.putereUmbra << "\n"
       << "Energie absorbita: " << monstru.energieAbsorbita << "\n"
       << "Invizibil: " << (monstru.esteInvizibil ? "Da" : "Nu") << "\n"
       << "Putere atac totala: " << monstru.calculeazaPutereAtac();
    return os;
}
