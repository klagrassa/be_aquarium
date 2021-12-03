#ifndef _AQUARIUM_H
#define _AQUARIUM_H

#include <iostream>
#include "CImg.h"

class Parametres_Sim;
class Milieu;

class Aquarium : public CImgDisplay {
  public:
    Aquarium(const Parametres_Sim & param);

    ~Aquarium();

    void run(void);


  private:
    Parametres_Sim * param_sim;

    Milieu * flotte;
    int delay;

};
#endif
