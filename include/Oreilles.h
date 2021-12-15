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

    double getCapaciteDetection( void );

    double getDistanceEcoute( void );

    double getChampsPerception( void );

    void setDistanceEcoute( double de );

    void setChampsPerception( double cp );

    void setCapaciteDetection( double cd );

    bool detect(Bestiole * cette_bestiole, Bestiole* b);
};
#endif
