#ifndef _YEUX_H
#define _YEUX_H


#include "Capteur.h"

class Yeux : public Capteur {
  private:
    float capacite_perception;

    float angle_vision;

    float distance_vision;


  public:
    Yeux(const Yeux & y);

    Yeux(float capacite_perception, float angle_vision, float distance_vision);

    ~Yeux();

    float getCapaciteDetection( void );

    float getDistanceVision( void );

    float getAngleVision( void );

    void setDistanceVision( float dv );

    void setAngleVision( float av );

    void setCapacitePerception( float cp);

    bool detect(Bestiole * cette_bestiole, Bestiole* b);

};
#endif
