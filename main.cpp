#include <iostream>
#include "Map.h"
#include "Supravietuitor.h"
#include "Monstru.h"

using namespace std;

int main() {
    cout << "=== ECOURILE LUMINII - JOC DE STRATEGIE ===" << endl;
    
    // 1. Creare harta
    Harta harta(8);
    
    // 2. Creare supravietuitori
    Supravietuitor erou1("Alex", 100, 50, 1, 1);
    Supravietuitor erou2("Maria", 90, 60, 2, 3);
    
    // 3. Creare monstri
    Monstru monstru1("Umbra", 80, 70, 6, 6, 15);
    Monstru monstru2("Fantomă", 70, 80, 5, 4, 12);
    
    // 4. Adaugare pe harta
    harta.adaugaSupravietuitor(erou1);
    harta.adaugaSupravietuitor(erou2);
    harta.adaugaMonstru(monstru1);
    harta.adaugaMonstru(monstru2);
    
    // 5. Afisare starea initiala
    cout << "\n--- STARE INITIALA ---" << endl;
    harta.afiseazaHarta();
    cout << erou1 << endl;
    cout << erou2 << endl;
    cout << monstru1 << endl;
    cout << monstru2 << endl;
    
    // 6. Testare functionalitati
    cout << "\n--- TESTARE FUNCTIONALITATI ---" << endl;
    
    // Supravietuitorii activeaza cristale
    erou1.getJucator().setPozitie(2, 2); // Pozitioneaza pe cristal
    if (erou1.activeazaCristal()) {
        cout << "Cristal activat cu succes!" << endl;
    }
    
    erou1.reparaCristal();
    
    // Monștrii folosesc abilitati
    monstru1.devineInvizibil();
    monstru1.absorbeEnergie(erou2);
    
    // 7. Deplasari si interactiuni
    cout << "\n--- DEPLASARI SI INTERACTIUNI ---" << endl;
    erou1.getJucator().deplasare(1, 0); // Dreapta
    erou2.getJucator().deplasare(0, 1); // Jos
    monstru1.getJucator().deplasare(-1, 0); // Stanga
    
    harta.afiseazaHarta();
    harta.interactioneazaJucatori();
    
    // 8. Testare operator= si constructor copiere
    cout << "\n--- TESTARE COPIERE ---" << endl;
    Supravietuitor erouCopia = erou1; // Operator=
    Monstru monstruCopia(monstru2);   // Constructor copiere
    
    cout << "Erou copiat: " << erouCopia.getJucator().getNume() << endl;
    cout << "Monstru copiat: " << monstruCopia.getJucator().getNume() << endl;
    
    // 9. Afisare finala
    cout << "\n--- STARE FINALA ---" << endl;
    cout << erou1 << endl;
    cout << erou2 << endl;
    cout << monstru1 << endl;
    cout << monstru2 << endl;
    
    cout << "\n=== JOC TERMINAT ===" << endl;
    return 0;
}
