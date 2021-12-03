#ifndef _AQUARIUM_H
#define _AQUARIUM_H


class Parametres_Sim;
class Milieu;

class Aquarium {
  public:
    Aquarium(const Parametres_Sim & param);

    ~Aquarium();


  private:
    Parametres_Sim * param_sim;

    Milieu * milieu;

};
#endif
