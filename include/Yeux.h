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


};
#endif
