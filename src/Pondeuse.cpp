
#include "Pondeuse.h"
#include "Bestiole.h"
#include "Accessoire.h"
#include "Capteur.h"

/**
 * @brief Construct a new Pondeuse:: Pondeuse object
 * 
 * @param param les paramètres de simulation que doit prendre en compte
 * la pondeuse
 */
Pondeuse::Pondeuse(const Parametres_Sim* p) {
   param_sim = p;
   std::cout << "Pondeuse" << std::endl;
}

/**
 * @brief Destroy the Pondeuse:: Pondeuse object
 * 
 */
Pondeuse::~Pondeuse() {
}

/**
 * @brief Création initiale des bestioles en accord avec les 
 * proportions indiquées dans les paramètres de simulation
 * 
 * @param nb_bestioles nombre de bestioles
 * @return Bestiole* 
 */
Bestiole* Pondeuse::creerBestioles(int nb_bestioles) {
}

/**
 * @brief Crée une bestiole avec les paramètres donnés
 * 
 * @param comportement comportement de la bestiole
 * @param accessoires accessoires de la bestiole
 * @param capteurs capteurs de la bestiole
 * @return Bestiole* référence de la bestiole créée
 */
Bestiole* Pondeuse::creerBestiole(const IComportement* comportement, const Accessoire* accessoires, const Capteur* capteurs) {
    return new Bestiole(comportement, accessoires, capteurs);
}

