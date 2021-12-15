
#include "Camouflage.h"

Camouflage::Camouflage(const Camouflage & c) {
}

/**
 * @brief Construct a new Camouflage:: Camouflage object
 * 
 * @param coefficiant_camouflage coefficient du camouflage
 */
Camouflage::Camouflage(double coefficiant_camouflage) {
    this->coefficient = coefficiant_camouflage;
}

Camouflage::~Camouflage() {
}

