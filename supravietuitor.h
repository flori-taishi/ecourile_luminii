#ifndef SUPRAVIETUITOR_H
#define SUPRAVIETUITOR_H

#include "Player.h"
#include <vector>

class Supravietuitor {
private:
    Jucator jucator;  // COMPUNERE cu Jucator!
    bool areCristal;
    int puncteLumina;
    int cristaleActivate;

    // Functii private
    void initializeazaAbilitatiSpeciale();

public:
    // Constructor de initializare
    Supravietuitor(const std::string& nume = "", int viata = 100, int energie = 60, 
                   int x = 0, int y = 0, bool cristal = false);
    
    // Getters const
    bool getAreCristal() const { return areCristal; }
    int getPuncteLumina() const { return puncteLumina; }
    int getCristaleActivate() const { return cristaleActivate; }
    const Jucator& getJucator() const { return jucator; }

    // Setters
    void setAreCristal(bool cristal) { areCristal = cristal; }
    void setPuncteLumina(int puncte) { puncteLumina = puncte; }

    // Functii membre netriviale
    bool activeazaCristal();
    void reparaCristal();
    int calculeazaBonusLumina() const;
    
    // Operator <<
    friend std::ostream& operator<<(std::ostream& os, const Supravietuitor& supravietuitor);
};

#endif
