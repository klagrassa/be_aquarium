#ifndef _OREILLES_H
#define _OREILLES_H


#include "Capteur.h"

class Oreilles : public Capteur {
  private:
    double distance_ecoute;

    double champs_perception;

    double capacite_detection;


  public:
    Oreilles(const Oreilles & c);

    Oreilles(double distance_ecoute, double capacite_detection);

    ~Oreilles();

};
#endif
