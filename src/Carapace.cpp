
#include "Carapace.h"

/**
 * @brief Construct a new Carapace:: Carapace object
 * Copy ctor
 * 
 * @param c carapace à copier
 */
Carapace::Carapace(const Carapace & c) {
}

/**
 * @brief Construct a new Carapace:: Carapace object
 * 
 * @param protection coefficient de reduction de mort
 * @param ralentissement coefficient de ralentissement
 */
Carapace::Carapace(double protection, double ralentissement) {
    this->protection = protection;
    this->ralentissement = ralentissement;
}

Carapace::~Carapace() {
}

