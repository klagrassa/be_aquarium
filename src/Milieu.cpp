
#include "Milieu.h"
#include "Bestiole.h"
#include "Pondeuse.h"

//Avance la simulation d'un step
void Milieu::step() {
}

//Renvoie les bestioles qui doivent mourir de vieillesse

Bestiole* Milieu::verifier_vieillesse(const Bestiole* & bestioles) {
}

//Renvoie les bestioles clon�es. Le clonage ne se fait uniquement que si le taux de clonage de la bestiole est inf�rieur au taux de clonage donn�
//en param�tre.
Bestiole* Milieu::verifier_clonage(const Bestiole* & bestioles, double taux_clonage) {
}

Milieu::Milieu() {
}

Milieu::~Milieu() {
}

