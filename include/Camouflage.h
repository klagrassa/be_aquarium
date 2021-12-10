#ifndef _CAMOUFLAGE_H
#define _CAMOUFLAGE_H


#include "Accessoire.h"

class Camouflage : public Accessoire {
  private:
    float coefficient;


  public:
    Camouflage(const Camouflage & c);

    Camouflage(float coefficiant_camouflage);

    ~Camouflage();

};
#endif
