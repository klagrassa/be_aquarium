
#include "Pondeuse.h"
#include "Bestiole.h"
#include "Accessoire.h"
#include "Capteur.h"
#include "Parametres_Sim.h"

#include "Constants.h" /* liste de comportements */

// Accessoires
#include "Nageoires.h"
#include "Camouflage.h"
#include "Carapace.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>        /* floor */

/**
 * @brief Création initiale des bestioles en accord avec les 
 * proportions indiquées dans les paramètres de simulation
 * 
 * @param nb_bestioles nombre de bestioles totales à générer
 * @return Bestiole* 
 */
std::vector<Bestiole> Pondeuse::creerBestioles(int nb_bestioles) {
    std::vector<Bestiole> bestioles_initiales;
    std::vector<double> proportions = param_sim->getProportions();


    // Génération des bestioles par comportement
    for (int i = 0; i < int(proportions[0]*(nb_bestioles-1)); i++)
    {
        Gregaire *comp = new Gregaire();
        bestioles_initiales.push_back(
            *(creerBestiole(comp))
        );
    }
    for (int i = 0; i < int(proportions[1]*(nb_bestioles-1)); i++)
    {
        Kamikaze* comp = new Kamikaze();
        bestioles_initiales.push_back(
            *(creerBestiole(comp))
        );

    }
    for (int i = 0; i < int(proportions[2]*(nb_bestioles-1)); i++)
    {
        Peureux* comp = new Peureux();
        bestioles_initiales.push_back(
            *(creerBestiole(comp))
        );

    }
    for (int i = 0; i < int(proportions[3]*(nb_bestioles-1)); i++)
    {
        Prevoyant* comp = new Prevoyant();
        bestioles_initiales.push_back(
            *(creerBestiole(comp))
        );
    }
    for (int i = 0; i < int(proportions[4]*(nb_bestioles-1)); i++)
    {
        Multiple* comp = new Multiple(liste_comportement);
        bestioles_initiales.push_back(
            *(creerBestiole(comp))
        );
    }
    return bestioles_initiales;
}

/**
 * @brief Crée une bestiole avec les paramètres donnés
 * 
 * @param comportement comportement de la bestiole
 * @param accessoires accessoires de la bestiole
 * @param capteurs capteurs de la bestiole
 * @return Bestiole* référence de la bestiole créée
 */
Bestiole* Pondeuse::creerBestiole(IComportement* comportement, std::vector<Accessoire*> accessoires, std::vector<Capteur*> capteurs) {
    return new Bestiole(comportement, accessoires, capteurs);
}

/**
 * @brief Creer une bestiole avec un comportement déjà prédéfini.
 * Le reste des accessoires et capteurs est généré aléatoirement
 * 
 * @param comp comportement actuel de la bestiole
 * @return Bestiole* avec capteurs / accessoires aléatoires
 */
Bestiole* Pondeuse::creerBestiole(IComportement* comp)
{
    Bestiole* best;
    // Génération des accessoires
    std::vector<Accessoire*> acc;

    /* initialize random seed: */
    srand(time(NULL));
    int res;

    // nageoire
    res = rand() % 2;
    if (res == 1)
    {
        // cast to int for modulo
        double coeff_vitesse = fmod(rand(), param_sim->getLimitesNageoiresVitesse());
        acc.push_back(new Nageoires(1+coeff_vitesse));
    }
    
    // carapace
    res = rand() % 2;
    if (res == 1)
    {
        // valeurs générées aléatoirement qui respectent les limites
        double ralentissement = fmod(rand(), param_sim->getLimitesCarapaces()[0]);
        double mort = fmod(rand(), param_sim->getLimitesCarapaces()[1]);
        acc.push_back(new Carapace(mort, ralentissement));
    }


    // camouflage
    res = rand() % 2;
    if (res == 1)
    {
        double camouflage = fmod(rand(), param_sim->getLimitesCamouflage()[1]) 
        + param_sim->getLimitesCamouflage()[0] ;
        acc.push_back(new Camouflage(camouflage));
    }

    // capteurs

    return best;
}

/**
 * @brief Construct a new Pondeuse:: Pondeuse object
 * 
 * @param param les paramètres de simulation que doit prendre en compte
 * la pondeuse
 */
Pondeuse::Pondeuse(Parametres_Sim* param) {
    if (param != nullptr)
        this->param_sim = param;
}

/**
 * @brief Destroy the Pondeuse:: Pondeuse object
 * 
 */
Pondeuse::~Pondeuse() {
    delete instance;
}

