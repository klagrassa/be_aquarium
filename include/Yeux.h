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

    double getCapaciteDetection( void );

    double getDistanceVision( void );

    double getAngleVision( void );

    void setDistanceVision( double dv );

    void setAngleVision( double av );

    void setCapacitePerception( double cp);

    bool detect(Bestiole * cette_bestiole, Bestiole* b);

};
#endif
