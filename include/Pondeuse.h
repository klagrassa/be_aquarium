#ifndef _PONDEUSE_H
#define _PONDEUSE_H

#include <vector>

/* forward declarations */
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
    /* Génération de bestioles aléatoires pour le nombre donné */
    std::vector<Bestiole*> creerBestioles(int nb_bestioles);
    /* Génération de bestiole avec liste de capteur et équipements 
    prédéfinis */
    Bestiole* creerBestiole(IComportement* comportement, std::vector<Accessoire*> accessoires, std::vector<Capteur*> capteurs);
    /* Création d'une bestiole a partir d'un comportement, le reste est 
    aléatoire */
    Bestiole* creerBestiole(IComportement* comp);

  // ctors and dtor
  public:
    Pondeuse(Parametres_Sim* param);
    ~Pondeuse();

};
#endif
