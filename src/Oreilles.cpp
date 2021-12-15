
#include "Oreilles.h"

Oreilles::Oreilles(const Oreilles & c) {
}

/**
 * @brief Construct a new Oreilles:: Oreilles object
 * 
 * @param distance_ecoute distance d'écoute des oreilles
 * @param capacite_detection capacité de detection
 */
Oreilles::Oreilles(double distance_ecoute, double capacite_detection) {
    this->distance_ecoute = distance_ecoute;
    this->capacite_detection = capacite_detection;
}

Oreilles::~Oreilles() {
}

