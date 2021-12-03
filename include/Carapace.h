#ifndef _CARAPACE_H
#define _CARAPACE_H


#include "Accessoire.h"

class Carapace : public Accessoire {
  private:
    float protection;

    float ralentissement;


  public:
    Carapace(const Carapace & c);

    Carapace(float protection, float ralentissement);

    ~Carapace();

};
#endif
