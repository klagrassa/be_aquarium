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

};
#endif
