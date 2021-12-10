#ifndef _PONDEUSE_H
#define _PONDEUSE_H

#include <iostream>


class Parametres_Sim;
class Bestiole;
class Accessoire;
class Capteur;
class IComportement;

class Pondeuse {

  // attributes
  private:
    const Parametres_Sim * param_sim;
    Pondeuse(const Parametres_Sim* p);

  // methods
  public:
    Bestiole* creerBestioles(int nb_bestioles);
    Bestiole* creerBestiole(const IComportement* comportement, const Accessoire* accessoires, const Capteur* capteurs);

  // ctors and dtor
    
    ~Pondeuse();

    static Pondeuse& getInstance(const Parametres_Sim* param) {
      static Pondeuse instance(param);  // sera instancié au premier appel à getInstance()
      return instance; 
    }

};
#endif
