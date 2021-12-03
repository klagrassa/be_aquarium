#ifndef _BESTIOLE_H
#define _BESTIOLE_H


#include "IComportement.h"

class Capteur;
class Accessoire;
class Milieu;

class Bestiole {
  private:
    <Capteur *> capteurs;

    <Accessoire *> accessoires;

    IComportement comportement;

    double taux_clonage;

    int age;

    <Bestiole*> bestioles_environnantes;


  public:
    void action(const const Milieu& & milieu);

    Bestiole(const Comportement* & comp, const Accessoire* & acc, const Capteur* & capteurs, const  & ,  );

    ~Bestiole();

    Bestiole clonage(Bestiole & bestiole);

    int getAge();

};
#endif
