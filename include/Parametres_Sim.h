#ifndef _PARAMETRES_SIM_H
#define _PARAMETRES_SIM_H

#include <map>

class Parametres_Sim {
  private:
    Parametres_Sim(){}

    //Parametres_Sim* instance = nullptr;

    int height;

    int width;

    int delay;

    double limites_carapace_ralentissement[2];

    double limites_carapace_mort[2];

    double limites_camouflage[2];

    double limites_nageoires_vitesse[2];

    double limites_rayon_oreilles[2];

    double limites_angulaire_champ_vision[2];

    double limite_distance_champ_vision[2];

    double limites_detection_yeux[2];

    double limites_detection_oreilles[2];

    std::map<std::string, double> proportions;


  public:
    ~Parametres_Sim();

    static Parametres_Sim& getInstance() {
      static Parametres_Sim instance;  // sera instancié au premier appel à getInstance()
      return instance; 
    }

    int getWidth() const;
    int getHeight() const;
    int getDelay() const;

    void setWidth(int w);
    void setHeight(int h);
    void setDelay(int d);
};

#endif
