#ifndef _YEUX_H
#define _YEUX_H


#include "Capteur.h"

class Yeux : public Capteur {
  private:
    double capacite_perception;
    double angle_vision;
    double distance_vision;

  public:
    Yeux(const Yeux & y);
    Yeux(double capacite_perception, double angle_vision, double distance_vision);
    ~Yeux();

<<<<<<< HEAD
    float getCapaciteDetection( void );

    float getDistanceVision( void );

    float getAngleVision( void );

    void setDistanceVision( float dv );

    void setAngleVision( float av );

    void setCapacitePerception( float cp);

    bool detect(Bestiole * cette_bestiole, Bestiole* b);
=======
>>>>>>> 68bd5a667bf4794937c06523cdcef382121a62cd

};
#endif
