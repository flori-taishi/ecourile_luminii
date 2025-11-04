#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Abilitate.h"

class Jucator {
private:
    std::string nume;
    int viata;
    int energie;
    int pozitieX, pozitieY;
    std::vector<Abilitate> abilitati;

    // Functie privata
    void initializeazaAbilitatiStandard();

public:
    // Constructor de initializare
    Jucator(const std::string& nume = "", int viata = 100, int energie = 50, 
            int x = 0, int y = 0);
    
    // Constructor de copiere
    Jucator(const Jucator& other);
    
    // Operator= de copiere
    Jucator& operator=(const Jucator& other);
    
    // Destructor
    ~Jucator();

    // Getters const
    std::string getNume() const { return nume; }
    int getViata() const { return viata; }
    int getEnergie() const { return energie; }
    int getPozitieX() const { return pozitieX; }
    int getPozitieY() const { return pozitieY; }
    const std::vector<Abilitate>& getAbilitati() const { return abilitati; }

    // Setters
    void setPozitie(int x, int y);
    void setViata(int viata) { this->viata = viata; }
    void setEnergie(int energie) { this->energie = energie; }

    // Functii membre netriviale
    bool esteInViata() const;
    void deplasare(int deltaX, int deltaY);
    bool poateFolosiAbilitate(int indexAbilitate) const;
    void folosesteAbilitate(int indexAbilitate);
    
    // Operator <<
    friend std::ostream& operator<<(std::ostream& os, const Jucator& jucator);
};

#endif
