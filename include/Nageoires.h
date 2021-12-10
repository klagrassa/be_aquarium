#ifndef _NAGEOIRES_H
#define _NAGEOIRES_H


#include "Accessoire.h"

class Nageoires : public Accessoire {
  private:
    float coefficient;
    

  public:
    Nageoires(const Nageoires & n);

    Nageoires(float coefficient_vitesse);

    ~Nageoires();

    float getCoefficient();

    void setCoefficient(float c);

};
#endif
