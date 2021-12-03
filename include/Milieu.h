#ifndef _MILIEU_H
#define _MILIEU_H

#include "UImg.h"

#include <iostream>
#include <vector>

class Bestiole;
class Pondeuse;

class Milieu {
  private:
    Pondeuse * pondeuse;

    Milieu* instance = nullptr;

    static const T          white[];

    int                     width, height;
    std::vector<Bestiole>   listeBestioles;

  public:
    //Avance la simulation d'un step
    void step();   
    

    std::vector<Bestiole*> verifier_vieillesse(const Bestiole* & bestioles);
    std::vector<Bestiole*> verifier_clonage(const Bestiole* & bestioles, double taux_clonage);

    void addMember( const Bestiole & b ) { listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height); }
    int nbVoisins( const Bestiole & b );
    
  // ctors and dtors
  public:
    Milieu();
    ~Milieu();
  
  // get/set 
  public: 
    int getWidth( void ) const { return width; };
    int getHeight( void ) const { return height; };

};
#endif
