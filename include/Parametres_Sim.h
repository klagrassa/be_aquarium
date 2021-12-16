#ifndef _PARAMETRES_SIM_H
#define _PARAMETRES_SIM_H

#include <map>
#include <vector>
#include "Constants.h"

/**
 * @brief This class contains simulation parameters
 *
 */
class Parametres_Sim {

  private:

    static Parametres_Sim *instance;

    // window size parameter
    int height;
    int width;

    // delay of the simulation
    int delay;

    /** Proportions de création de bestioles (la somme doit être 
     * égale a 1)
     * Premier élément : Grégaire
     * Deuxieme élément : Kamikaze
     * Troisième élément : Peureux
     * Quatrième élément : Prévoyant
     * Cinquième élément : Multiple
     */
    std::vector<double> proportions;

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

    //std::map<std::string, double> proportions;

    
    Parametres_Sim();

  public:

    /**
     * Ne dois pas être cloné
     */
    Parametres_Sim(Parametres_Sim &other) = delete;
    /**
     * Ne doit pas être assignable
     */
    void operator=(const Parametres_Sim &) = delete;

    ~Parametres_Sim();

    /**
     * @brief Renvoie un objet unique Parametres_Sim
     * 
     * @return Parametres_Sim* Parametres_Sim
     */
    
    static Parametres_Sim* getInstance();


    // get
    int getWidth() const;
    int getHeight() const;
    int getDelay() const;

    double* getLimitesRayonOreilles();
    double* getLimitesDetectionOreilles();
    double* getLimitesDetectionYeux();
    double* getLimitesDistanceAngulaireChampsVision();
    double* getLimitesDistanceChampsVision();
    double getLimitesNageoiresVitesse();
    double* getLimitesCarapaces();
    double* getLimitesCamouflage();
    std::vector<double> getProportions();

    // set
    void setWidth(int width);
    void setHeight(int height);
    void setDelay(int delay);

    void setLimitesCarapace(double ralentissement_max,
                            double mort);
    void setLimitesNageoires(double vitesse_max);
    void setLimitesCamouflage(double coeff_min, double coeff_max);
    void setLimitesRayonOreilles(double rayon_min, double rayon_max);
    void setLimitesDetectionOreilles(double detec_min, double detec_max);
    void setLimitesDetectionYeux(double detec_min, double detec_max);
    void setLimitesDistanceChampsVision(double distance_min, double distance_max);
    void setLimitesDistanceAngulaireChampsVision(double angle_min, double angle_max);
    void setProportions(std::vector<double> prop);

};

#endif
