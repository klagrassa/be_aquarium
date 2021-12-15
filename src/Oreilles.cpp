
#include "Oreilles.h"
#include "Bestiole.h"
#include <cmath>


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

double Oreilles::getCapaciteDetection( void ) {
  return this->capacite_detection;
}

double Oreilles::getDistanceEcoute( void ) {
  return this->distance_ecoute;
}

void Oreilles::setDistanceEcoute( double de ) {
  if (de >= 0)
    this->distance_ecoute = de;
}

void Oreilles::setChampsPerception( double cp ) {
  if (cp >= 0 && cp <= 2*M_PI)
    this->champs_perception = cp;
}

void Oreilles::setCapaciteDetection( double cd) {
  if (cd >= 0 && cd <= 1);
  this->capacite_detection = cd;
}

/**
 * @brief Implémentation de la détection pour les oreilles
 * 
 * @param cette_bestiole la bestiole possédant les oreilles
 * @param b la bestiole qu'on veut détecter
 * @return true la bestiole b est détectée
 * @return false la bestiole b n'est pas détectée
 */
bool Oreilles::detect(Bestiole * cette_bestiole, Bestiole* b)
{
   double         dist;
   dist = std::sqrt( (cette_bestiole->getX() - b->getX())*(cette_bestiole->getX() - b->getX()) 
   + (cette_bestiole->getY() - b->getY())*(cette_bestiole->getY() - b->getY()) );
   return ((dist <= this->distance_ecoute) &&  (rand()/RAND_MAX <= this->capacite_detection));
}
