#ifndef _MULTIPLE_H
#define _MULTIPLE_H


#include "IComportement.h"
#include <vector>

// Comportements
#include "Gregaire.h"
#include "Multiple.h"
#include "Kamikaze.h"
#include "Prevoyant.h"
#include "Peureux.h"

class Multiple : public IComportement {
  private:
    //Liste des comportements
    std::vector<IComportement *> liste_comportements;

    IComportement* comportement_actuel;


  public:
    void choisir_comportement();
    void bouge(Bestiole* bestiole_actuelle, std::vector<Bestiole*> bestioles);

  public:
    Multiple();
    Multiple(const Multiple & m);
    ~Multiple();

};
#endif
