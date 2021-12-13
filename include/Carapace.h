#ifndef _CARAPACE_H
#define _CARAPACE_H


#include "Accessoire.h"

class Carapace : public Accessoire {
  private:

    double protection;
    double ralentissement;


  public:
    Carapace(const Carapace & c);
    Carapace(double protection, double ralentissement);
    ~Carapace();

};
#endif
