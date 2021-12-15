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

    float getCapaciteDetection( void );

    float getDistanceEcoute( void );

    float getChampsPerception( void );

    void setDistanceEcoute( float de );

    void setChampsPerception( float cp );

    void setCapaciteDetection( float cd );

    bool detect(Bestiole * cette_bestiole, Bestiole* b);
};
#endif
