#ifndef MONSTRU_H
#define MONSTRU_H

#include "Player.h"
#include <vector>

class Monstru {
private:
    Jucator jucator;  // COMPUNERE cu Jucator!
    int putereUmbra;
    int energieAbsorbita;
    bool esteInvizibil;

    // Functii private
    void initializeazaAbilitatiIntuneric();

public:
    // Constructor de initializare
    Monstru(const std::string& nume = "", int viata = 80, int energie = 70, 
            int x = 0, int y = 0, int putereUmbra = 10);
    
    // Getters const
    int getPutereUmbra() const { return putereUmbra; }
    int getEnergieAbsorbita() const { return energieAbsorbita; }
    bool getEsteInvizibil() const { return esteInvizibil; }
    const Jucator& getJucator() const { return jucator; }

    // Setters
    void setPutereUmbra(int putere) { putereUmbra = putere; }
    void setEsteInvizibil(bool invizibil) { esteInvizibil = invizibil; }

    // Functii membre netriviale
    void absorbeEnergie(Supravietuitor& target);
    void devineInvizibil();
    int calculeazaPutereAtac() const;
    
    // Operator <<
    friend std::ostream& operator<<(std::ostream& os, const Monstru& monstru);
};

#endif
