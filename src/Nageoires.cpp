
#include "Nageoires.h"

Nageoires::Nageoires(const Nageoires & n) {
}

Nageoires::Nageoires(float coefficient_vitesse) {
}

Nageoires::~Nageoires() {
}

/**
 * @brief recupere le coeff de vitesse 
 * 
 * @return float est le coeff de vitesse
 */
float Nageoires::getCoefficient(void) {
    return coefficient; 
}

/**
 * @brief met a jour coeff
 * 
 * @param c est le coeff de vitesse
 */
void Nageoires::setCoefficient(float c) {
    if(c>=0)
        this->coefficient = c;
    else
        this->coefficient=0; 
}


