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
    Pondeuse * pondeuse;
    Milieu* instance = nullptr;
    Parametres_Sim* param;

    static const T          white[];

    int                     width, height;
    std::vector<Bestiole*>   listeBestioles;

  public:
    //Avance la simulation d'un step
    void step(void);   
    
    std::vector<Bestiole*> verifier_clonage(const Bestiole* & bestioles, double taux_clonage);

    int nbVoisins( const Bestiole & b );

    void addMember(Bestiole* b);

    Milieu( int _width, int _height );
    ~Milieu();
  
    int getWidth( void ) const { return width; };
    int getHeight( void ) const { return height; };

};
#endif
