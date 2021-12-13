#ifndef __CONST_H
#define __CONST_H

// Comportements
#include "Gregaire.h"
#include "Multiple.h"
#include "Kamikaze.h"
#include "Prevoyant.h"
#include "Peureux.h"

/**
 * CONSTANTS.H
 *
 * All the constants that need to be global should be set here.
 *
 */

const double AFF_SIZE = 8.;
const double MAX_VITESSE = 10.;
const double LIMITE_VUE = 30.;

const IComportement* liste_comportement[4] = {
    new Gregaire(),
    new Peureux(),
    new Prevoyant(),
    new Kamikaze()
};

#endif;