#ifndef _PARAMETRES_SIM_H
#define _PARAMETRES_SIM_H

#include <map>

/**
 * @brief This class contains simulation parameters
 *
 */
class Parametres_Sim {

  private:
    Parametres_Sim* instance = nullptr;

    // window size parameter
    int height;
    int width;

    // delay of the simulation
    int delay;

    // limites des capteurs et accessoires
    double limites_carapace_ralentissement;
    double limites_carapace_mort;
    double limites_camouflage[2]; // les coefficients sont entre 
                                  // 0 =< phi_min =< phi_max =< 1
    double limites_nageoires_vitesse;

    double limites_rayon_oreilles[2]; // phi_min =< phi_max
    double limites_angulaire_champ_vision[2]; // phi_min =< phi_max
    double limites_distance_champ_vision[2]; // phi_min =< phi_max
    double limites_detection_yeux[2]; // 0 =< phi_min =< phi_max =< 1
    double limites_detection_oreilles[2]; // 0 =< phi_min =< phi_max =< 1

    std::map<std::string, double> proportions;

    
    Parametres_Sim();

  public:

    ~Parametres_Sim();

    /**
     * @brief Renvoie un objet unique Parametres_Sim
     * 
     * @return Parametres_Sim* singleton
     */
    static Parametres_Sim& getInstance() {
      static Parametres_Sim instance;  // sera instancié au premier appel à getInstance()
      return instance; 
    }


    // get
    int getWidth() const;
    int getHeight() const;
    int getDelay() const;

    double* getLimitesRayonOreilles();
    double* getLimitesDetectionOreilles();
    double* getLimitesDetectionYeux();
    double* getLimitesDistanceAngulaireChampsVision();
    double* getLimitesDistanceChampsVision();

    // set
    void setWidth(int width);
    void setHeight(int height);
    void setDelay(int delay);

    void setLimitesCarapces(double ralentissement_min,
                            double ralentissement_max,
                            double mort);
    void setLimitesNageoires(double vitesse_max);
    void setLimitesCamouflage(double coeff_min, double coeff_max);
    void setLimitesRayonOreilles(double rayon_min, double rayon_max);
    void setLimitesDetectionOreilles(double detec_min, double detec_max);
    void setLimitesDetectionYeux(double detec_min, double detec_max);
    void setLimitesDistanceChampsVision(double distance_min, double distance_max);
    void setLimitesDistanceAngulaireChampsVision(double angle_min, double angle_max);


};

#endif
