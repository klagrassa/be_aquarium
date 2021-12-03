#ifndef _PONDEUSE_H
#define _PONDEUSE_H


class Parametres_Sim;
class Bestiole;
class Accessoire;
class Capteur;

class Pondeuse {
  private:
    Parametres_Sim * param_sim;

    Pondeuse* instance = nullptr;


  public:
    Bestiole* creerBestioles(int nb_bestioles);

    Bestiole* creerBestiole(const Comportement* & comportement, const Accessoire* & accessoires, const Capteur* & capteurs);

    Pondeuse();

    ~Pondeuse();

};
#endif
