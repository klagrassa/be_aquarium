
#include "Camouflage.h"

Camouflage::Camouflage(const Camouflage & c) {
}

Camouflage::Camouflage(float coefficiant_camouflage) {
}

Camouflage::~Camouflage() {
}

/**
 * @brief met a jour 
 * 
 * @return float est le coeff de camouflage
 */
float Camouflage::getCoefficient(void) {
    return coefficient; 
}

/**
 * @brief change le coeff
 * 
 * @param c est le coeff de camouflage
 */
void Camouflage::setCoefficient(float c) {
    if(coefficient>=0)
        this->coefficient = c; 
    else
        this->coefficient=0; 
}
