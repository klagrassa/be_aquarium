#ifndef _OREILLES_H
#define _OREILLES_H


#include "Capteur.h"

class Oreilles : public Capteur {
  private:
    float distance_ecoute;

    float champs_perception;

    float capacite_detection;


  public:
    Oreilles(const Oreilles & c);

    Oreilles(float distance_ecoute, float capacite_detection);

    ~Oreilles();

};
#endif
