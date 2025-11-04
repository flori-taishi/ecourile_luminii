#ifndef MAP_H
#define MAP_H

#include "Supravietuitor.h"
#include "Monstru.h"
#include <vector>
#include <memory>

class Harta {
private:
    int dimensiune;
    std::vector<std::vector<char>> zones;
    std::vector<Supravietuitor> supravietuitori;
    std::vector<Monstru> monstri;
    
    // Functii private
    void initializeazaHarta();
    bool estePozitieValida(int x, int y) const;
    char getSimbolPozitie(int x, int y) const;

public:
    // Constructor de initializare
    Harta(int dim = 10);
    
    // Constructor de copiere
    Harta(const Harta& other);
    
    // Operator= de copiere
    Harta& operator=(const Harta& other);
    
    // Destructor
    ~Harta();

    // Getters const
    int getDimensiune() const { return dimensiune; }
    const std::vector<Supravietuitor>& getSupravietuitori() const { return supravietuitori; }
    const std::vector<Monstru>& getMonstri() const { return monstri; }

    // Functii membre netriviale
    void adaugaSupravietuitor(const Supravietuitor& supravietuitor);
    void adaugaMonstru(const Monstru& monstru);
    void afiseazaHarta() const;
    bool verificaColiziune(int x, int y) const;
    void interactioneazaJucatori();
    
    // Operator <<
    friend std::ostream& operator<<(std::ostream& os, const Harta& harta);
};

#endif
