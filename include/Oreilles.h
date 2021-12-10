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

    float getCapaciteDetection( void );

    float getDistanceEcoute( void );

    float getChampsPerception( void );

    void setDistanceEcoute( float de );

    void setChampsPerception( float cp );

    void setCapaciteDetection( float cd );

    bool detect(Bestiole * cette_bestiole, Bestiole* b);
};
#endif
