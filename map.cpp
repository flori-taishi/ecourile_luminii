#include "Map.h"
#include <iostream>
#include <algorithm>


Harta::Harta(int dim) : dimensiune(dim) {
    zones.resize(dimensiune, std::vector<char>(dimensiune, '.'));
    initializeazaHarta();
    std::cout << "Harta creata cu dimensiunea: " << dimensiune << "x" << dimensiune << std::endl;
}


Harta::Harta(const Harta& other) 
    : dimensiune(other.dimensiune), zones(other.zones),
      supravietuitori(other.supravietuitori), monstri(other.monstri) {
    std::cout << "Constructor copiere Harta" << std::endl;
}


Harta& Harta::operator=(const Harta& other) {
    if (this != &other) {
        dimensiune = other.dimensiune;
        zones = other.zones;
        supravietuitori = other.supravietuitori;
        monstri = other.monstri;
    }
    std::cout << "Operator= Harta" << std::endl;
    return *this;
}


Harta::~Harta() {
    std::cout << "Destructor Harta" << std::endl;
}


void Harta::initializeazaHarta() {
 
    zones[2][2] = 'S';
    zones[7][3] = 'S';
    zones[4][8] = 'S';
    
   
    zones[5][5] = 'X';
    zones[1][7] = 'X';
    zones[8][1] = 'X';
}


bool Harta::estePozitieValida(int x, int y) const {
    return x >= 0 && x < dimensiune && y >= 0 && y < dimensiune;
}


char Harta::getSimbolPozitie(int x, int y) const {
    if (!estePozitieValida(x, y)) return ' ';
    return zones[y][x];
}


void Harta::adaugaSupravietuitor(const Supravietuitor& supravietuitor) {
    supravietuitori.push_back(supravietuitor);
    std::cout << "Supravietuitor adaugat pe harta: " 
              << supravietuitor.getJucator().getNume() << std::endl;
}

void Harta::adaugaMonstru(const Monstru& monstru) {
    monstri.push_back(monstru);
    std::cout << "Monstru adaugat pe harta: " 
              << monstru.getJucator().getNume() << std::endl;
}


void Harta::afiseazaHarta() const {
    std::cout << "\n=== HARTA JOC ===" << std::endl;
    
    for (int y = 0; y < dimensiune; ++y) {
        
        for (int x = 0; x < dimensiune; ++x) {
            std::cout << "+---";
        }
        std::cout << "+" << std::endl;
        
    
        for (int x = 0; x < dimensiune; ++x) {
            std::cout << "| ";
            
           
            char simbol = zones[y][x];
            bool gasitJucator = false;
            
         
            for (const auto& sup : supravietuitori) {
                if (sup.getJucator().getPozitieX() == x && 
                    sup.getJucator().getPozitieY() == y) {
                    std::cout << "H"; 
                    gasitJucator = true;
                    break;
                }
            }
            
          
            if (!gasitJucator) {
                for (const auto& mon : monstri) {
                    if (mon.getJucator().getPozitieX() == x && 
                        mon.getJucator().getPozitieY() == y) {
                        std::cout << "M"; // Monstru
                        gasitJucator = true;
                        break;
                    }
                }
            }
            
           
            if (!gasitJucator) {
                std::cout << simbol;
            }
            
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }
    
    
    for (int x = 0; x < dimensiune; ++x) {
        std::cout << "+---";
    }
    std::cout << "+" << std::endl;
    
    std::cout << "Legend: H=Supravietuitor, M=Monstru, S=Cristal, X=Obstacol" << std::endl;
}


bool Harta::verificaColiziune(int x, int y) const {
    if (!estePozitieValida(x, y)) return true;
    return zones[y][x] == 'X'; 
}


void Harta::interactioneazaJucatori() {
    std::cout << "\n=== INTERACTIUNI PE HARTA ===" << std::endl;
    

    for (auto& supravietuitor : supravietuitori) {
        for (auto& monstru : monstri) {
            int distX = std::abs(supravietuitor.getJucator().getPozitieX() - 
                               monstru.getJucator().getPozitieX());
            int distY = std::abs(supravietuitor.getJucator().getPozitieY() - 
                               monstru.getJucator().getPozitieY());
            
           
            if (distX <= 1 && distY <= 1 && (distX + distY) > 0) {
                std::cout << "INTERACTIUNE: " << supravietuitor.getJucator().getNume()
                          << " si " << monstru.getJucator().getNume() << " sunt aproape!" << std::endl;
                
              
                monstru.absorbeEnergie(supravietuitor);
            }
        }
        
       
        int x = supravietuitor.getJucator().getPozitieX();
        int y = supravietuitor.getJucator().getPozitieY();
        
        if (estePozitieValida(x, y) && zones[y][x] == 'S') {
            std::cout << supravietuitor.getJucator().getNume() 
                      << " este pe un cristal solar!" << std::endl;
            supravietuitor.activeazaCristal();
        }
    }
}


std::ostream& operator<<(std::ostream& os, const Harta& harta) {
    os << "Harta " << harta.dimensiune << "x" << harta.dimensiune;
    os << " | Supravietuitori: " << harta.supravietuitori.size();
    os << " | Monstri: " << harta.monstri.size();
    return os;
}
