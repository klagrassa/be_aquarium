
#include "Parametres_Sim.h"


/**
 * @brief Construct a new Parametres_Sim::Parametres_Sim object
 * 
 */
Parametres_Sim::Parametres_Sim() {}

/**
 * @brief Destroy the Parametres_Sim::Parametres_Sim object
 * 
 */
Parametres_Sim::~Parametres_Sim() {}

// get / set operators

/**
 * @brief Renvoie les proportions de génération par comportement
 * 
 * @return std::vector<double> somme des éléments doit être égale à 1
 */
std::vector<double> Parametres_Sim::getProportions()
{
    return this->proportions;
}

/**
 * @brief Retourne la hauteur de la fenêtre
 * 
 * @return int hauteur de la fenêtre
 */
int Parametres_Sim::getHeight() const {
    return this->height;
}

/**
 * @brief Retourne la largeur de la fenêtre
 * 
 * @return int largeur de la fenêtre
 */
int Parametres_Sim::getWidth() const {
    return this->width;
}

/**
 * @brief Retourne le délai de la simulation
 * 
 * @return int délai de la simulation
 */
int Parametres_Sim::getDelay() const {
    return this->delay;
}

/**
 * @brief Retourne les limites des carapaces
 * 
 * @return double* le premier élément est le ralentissement max
 *                  le second élément est la réduction de mort
 */
double* Parametres_Sim::getLimitesCarapaces()
{
    double res[2] = {this->limites_carapace_ralentissement,
                    this->limites_carapace_mort};
    return res; 
}

/**
 * @brief Renvoie les coefficients min et max de valeurs de camouflage
 * 
 * @return double* premier élément : min
 *                 deuxième élément : max
 */
double* Parametres_Sim::getLimitesCamouflage()
{
    return this->limites_camouflage;
}

/**
 * @brief Renvoie les limites du rayon d'écoute pour les
 * oreilles
 * 
 * @return double* tableau contenant les limites,
 * taille de 2
 * 0 = rayon min
 * 1 = rayon max
 */
double* Parametres_Sim::getLimitesRayonOreilles() {
    return this->limites_rayon_oreilles;
}

/**
 * @brief Renvoie les limites de détection des oreilles
 * 
 * @return double* tableau contenant les limites
 * taille de 2
 * 0 = detec min
 * 1 = detec max
 */
double* Parametres_Sim::getLimitesDetectionOreilles() {
    return this->limites_detection_oreilles;
}

/**
 * @brief Renvoie les limites de detection des yeux
 * 
 * @return double* tableau contenant les limites de detection
 * taille de 2
 */
double* Parametres_Sim::getLimitesDetectionYeux() {
    return this->limites_detection_yeux;
}

/**
 * @brief Renvoie les limites de distance angulaire pour
 * le champs de vision
 * 
 * @return double* tableau contenant les limites
 * taille de 2
 * 0 = angle min
 * 1 = angle max
 */
double* Parametres_Sim::getLimitesDistanceAngulaireChampsVision() {
    return this->limites_angulaire_champ_vision;
}

/**
 * @brief Renvoie les limites 
 * 
 * @return double* tableau contenant les limites
 * 0 = distance min
 * 1 = distance max
 */
double* Parametres_Sim::getLimitesDistanceChampsVision() {
    return this->limites_distance_champ_vision;
} 

/**
 * @brief Renvoie le coefficient limite de vitesse pour les nageoires
 * 
 * @return double coefficient de vitesse max pour les nageoires
 */
double Parametres_Sim::getLimitesNageoiresVitesse()
{
    return this->limites_nageoires_vitesse;
}

/**
 * @brief Hauteur de la fenêtre
 * 
 * @param height hauteur de la fenêtre
 */
void Parametres_Sim::setHeight(int height) {
    if (height > 0)
        this->height = height;
}

/**
 * @brief Paramètre la largeur de la fenêtre
 * 
 * @param width largeur de la fenêtre
 */
void Parametres_Sim::setWidth(int width) {
    if (width > 0)
        this->width = width;
}

/**
 * @brief Paramètre le délai de simulation
 * 
 * @param delay délai de simulation
 */
void Parametres_Sim::setDelay(int delay) {
    if (delay >= 0)
        this->delay = delay;
}

/**
 * @brief Paramètre les limites des coefficients vitesses pour les nageoires
 * 
 * @param vitesse_min min des nageoires
 * @param vitesse_max max des nageoires
 */
void Parametres_Sim::setLimitesNageoires(double vitesse_max){
    if (vitesse_max >= 0) 
        this->limites_nageoires_vitesse = vitesse_max;
}

/**
 * @brief Paramètre les limites du camouflage
 * 
 * @param coeff_min min du camouflage
 * @param coeff_max max du camouflage
 */
void Parametres_Sim::setLimitesCamouflage(double coeff_min, double coeff_max) {
    // 0 <= min <= max <= 1
    if (coeff_min >= 0 && coeff_max >= coeff_min && coeff_max <= 1 && coeff_min <= coeff_max)
    {
        this->limites_camouflage[0] = coeff_min;
        this->limites_camouflage[1] = coeff_max;
    }
}

/**
 * @brief Paramètre les limites du rayon de perception des oreilles
 * 
 * @param rayon_min distance minimale du rayon
 * @param rayon_max distance maximale du ratyon
 */
void Parametres_Sim::setLimitesRayonOreilles(double rayon_min, double rayon_max){
    if (rayon_min >= 0 && rayon_max >= rayon_min)
    {
        this->limites_rayon_oreilles[0] = rayon_min;
        this->limites_rayon_oreilles[1] = rayon_max;
    }
}

/**
 * @brief Paramètre les limites de la detection des oreilles
 * 
 * @param detec_min min de detection des oreilles
 * @param detec_max max de detection des oreilles
 */
void Parametres_Sim::setLimitesDetectionOreilles(double detec_min, double detec_max){
    if (detec_min >= 0 && detec_max >= detec_min)
    {
        this->limites_detection_oreilles[0] = detec_min;
        this->limites_detection_oreilles[1] = detec_max;
    }
}

/**
 * @brief Paramètre les limites de la detection des yeux
 * 
 * @param detec_min min de detection des yeux
 * @param detec_max max de detection des yeux
 */
void Parametres_Sim::setLimitesDetectionYeux(double detec_min, double detec_max){
    if (detec_min >= 0 && detec_max >= detec_min)
    {
        this->limites_detection_yeux[0] = detec_min;
        this->limites_detection_yeux[1] = detec_max;
    }
}

/**
 * @brief Paramètre les limites de la distance de champs de vision
 * 
 * @param distance_min distance minimale du champs de vision
 * @param distance_max distance maximale du champs de vision
 */
void Parametres_Sim::setLimitesDistanceChampsVision(double distance_min, double distance_max){
    if (distance_min >= 0 && distance_max >= distance_min)
    {
        this->limites_distance_champ_vision[0] = distance_min;
        this->limites_distance_champ_vision[1] = distance_max;
    }
}

/**
 * @brief Paramètre les limites de la distance angulaire du champs de vision
 * 
 * @param angle_min angle minimal du champs de vision
 * @param angle_max angle maximal du champs de vison
 */
void Parametres_Sim::setLimitesDistanceAngulaireChampsVision(double angle_min, double angle_max){
    if (angle_min >= 0 && angle_max >= angle_min)
    {
        this->limites_angulaire_champ_vision[0] = angle_min;
        this->limites_angulaire_champ_vision[1] = angle_max;
    }
}

/**
 * @brief Paramètre les proportions de générations de bestiole.
 * Chaque pourcentage représente un caractère à générer parmi 5.
 * Voir doc
 * 
 * @param proportions vector de double, la somme doit être égale à 1
 */
void Parametres_Sim::setProportions(std::vector<double> prop)
{
    for (auto it = prop.begin(); it != prop.end(); ++it)
    {
        this->proportions.push_back(*it);
    }
}

/**
 * @brief Paramètre les limites pour la carapace
 * 
 * @param ralentissement_max 
 * @param mort coefficient de réduction de dégâts
 */
void Parametres_Sim::setLimitesCarapace(double ralentissement_max, double mort)
{
    if (ralentissement_max >= 1)
        this->limites_carapace_ralentissement;
    if (mort >= 1)
        this->limites_carapace_mort;
}
