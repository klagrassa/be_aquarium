
#include "Milieu.h"
#include "Bestiole.h"
#include "Pondeuse.h"

//Avance la simulation d'un step
void Milieu::step() {
}

//Renvoie les bestioles qui doivent mourir de vieillesse

Bestiole* Milieu::verifier_vieillesse(const Bestiole* & bestioles) {
}

//Renvoie les bestioles clonées. Le clonage ne se fait uniquement que si le taux de clonage de la bestiole est inférieur au taux de clonage donné
//en paramètre.
Bestiole* Milieu::verifier_clonage(const Bestiole* & bestioles, double taux_clonage) {
}

Milieu::Milieu() {
}

Milieu::~Milieu() {
}

