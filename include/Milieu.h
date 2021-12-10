#ifndef _MILIEU_H
#define _MILIEU_H

#include "UImg.h"

#include <iostream>
#include <vector>

class Bestiole;
class Pondeuse;
class Parametres_Sim;

using namespace cimg_library;

class Milieu : public UImg {
  private:
    Milieu(const Parametres_Sim* p);

    Pondeuse * pondeuse;
    //Milieu* instance = nullptr;
    const Parametres_Sim* param;

    static const T          white[];

    int                     width, height;
    std::vector<Bestiole>   listeBestioles;

  public:
    //Avance la simulation d'un step
    void step(void);   
    

    std::vector<Bestiole*> verifier_vieillesse(const Bestiole* & bestioles);
    std::vector<Bestiole*> verifier_clonage(const Bestiole* & bestioles, double taux_clonage);

    int nbVoisins( const Bestiole & b );

    void addMember( const Bestiole & b );

    static Milieu& getInstance(const Parametres_Sim* param) {
      static Milieu instance(param);  // sera instancié au premier appel à getInstance()
      return instance; 
    }

    ~Milieu();
  
    int getWidth( void ) const { return width; };
    int getHeight( void ) const { return height; };

};
#endif
