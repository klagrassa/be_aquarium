#ifndef _PONDEUSE_H
#define _PONDEUSE_H

#include <vector>

class Parametres_Sim;
class Bestiole;
class Accessoire;
class Capteur;
class IComportement;

class Pondeuse {

  // attributes
  private:
    Parametres_Sim * param_sim;
    Pondeuse* instance = nullptr;

  // methods
  public:
    std::vector<Bestiole> creerBestioles(int nb_bestioles);
    Bestiole* creerBestiole(IComportement* comportement, std::vector<Accessoire*> accessoires, std::vector<Capteur*> capteurs);
    Bestiole* creerBestiole(IComportement* comp);

  // ctors and dtor
  public:
    Pondeuse(Parametres_Sim* param);
    ~Pondeuse();

};
#endif
