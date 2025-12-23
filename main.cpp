#include <iostream>
#include <vector>
#include "Entitate.h"
#include "Jucator.h"
#include "Om.h"       
#include "Cristal.h"  

int main() {
    // Cerința Tema 2: Container STL care stochează pointeri la clasa de bază
    std::vector<Entitate*> elementeHarta;

    try {
        // Adăugăm obiecte diferite în același vector
        elementeHarta.push_back(new Om("Florin", 100, 50, 0, 0));
        elementeHarta.push_back(new Cristal(5, 5));

        std::cout << "--- Starea Initiala a Hartii ---\n";
        for (auto ent : elementeHarta) {
            // Apel polimorfic (se execută afisarea specifică fiecărei clase)
            std::cout << *ent << std::endl; 
        }

        // Exemplu de RTTI (dynamic_cast) - Cerință Tema 2
        std::cout << "\n--- Interactiuni Specifice ---\n";
        for (auto ent : elementeHarta) {
            // Verificăm dacă entitatea este un Om
            Om* jucatorOm = dynamic_cast<Om*>(ent);
            if (jucatorOm) {
                std::cout << "Am gasit un om: " << jucatorOm->getNume() << ". Se deplaseaza...\n";
                jucatorOm->deplasare(1, 1);
            }

            // Verificăm dacă este un Cristal
            Cristal* c = dynamic_cast<Cristal*>(ent);
            if (c) {
                std::cout << "Am gasit un cristal. Interactionam cu el!\n";
                c->interactioneaza();
            }
        }

    } catch (const std::exception& e) {
        // Gestionarea excepțiilor - Cerință Tema 2
        std::cerr << "Eroare in joc: " << e.what() << std::endl;
    }

    // Curățarea memoriei (OBLIGATORIU pentru pointeri)
    for (auto ent : elementeHarta) {
        delete ent;
    }
    elementeHarta.clear();

    return 0;
}
