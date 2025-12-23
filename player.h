#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include "Entitate.h"
#include "Abilitate.h"

// Jucator moștenește acum din Entitate
class Jucator : public Entitate {
protected: // protected pentru ca Om si Creatura sa le poata accesa
    int viata;
    int energie;
    std::vector<Abilitate> abilitati;

    void initializeazaAbilitatiStandard();

public:
    // Constructorul pasează numele și coordonatele către clasa de bază Entitate
    Jucator(const std::string& nume = "", int viata = 100, int energie = 50, 
            int x = 0, int y = 0);
    
    Jucator(const Jucator& other);
    Jucator& operator=(const Jucator& other);
    
    // Destructor virtual pentru polimorfism
    virtual ~Jucator();

    // Getters
    int getViata() const { return viata; }
    int getEnergie() const { return energie; }
    const std::vector<Abilitate>& getAbilitati() const { return abilitati; }

    // Setters
    void setViata(int viata) { this->viata = viata; }
    void setEnergie(int energie) { this->energie = energie; }

    // Metode de logică
    bool esteInViata() const;
    void deplasare(int deltaX, int deltaY);
    
    // Metodele virtuale din Entitate (le lăsăm virtuale pure sau le implementăm parțial)
    virtual void interactioneaza() override = 0; 
};

#endif
