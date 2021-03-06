#ifndef _MULTIPLE_H
#define _MULTIPLE_H


#include "IComportement.h"
#include <vector>
using namespace std;

class Multiple : public IComportement {
  private:
    //Liste des comportements
    vector<IComportement *> listeComposants;

    IComportement* comportement_actuel;


  public:
    void choisir_comportement();

    Multiple(const IComportement & liste_comportements);

    Multiple(const Multiple & m);

};
#endif
