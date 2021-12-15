#ifndef _NAGEOIRES_H
#define _NAGEOIRES_H


#include "Accessoire.h"

class Nageoires : public Accessoire {
  private:
    double coefficient;


  public:
    Nageoires(const Nageoires & n);

    Nageoires(double coefficient_vitesse);

    ~Nageoires();

};
#endif
