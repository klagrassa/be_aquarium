#ifndef _CAMOUFLAGE_H
#define _CAMOUFLAGE_H


#include "Accessoire.h"

class Camouflage : public Accessoire {
  private:
    double coefficient;


  public:
    Camouflage(const Camouflage & c);
    Camouflage(double camouflage);
    ~Camouflage();

};
#endif
