
#include "Oreilles.h"
#include <cmath>


Oreilles::Oreilles(const Oreilles & c) {
}

<<<<<<< HEAD
Oreilles::Oreilles(float distance_ecoute, float capacite_detection) {
  this->distance_ecoute = distance_ecoute;
  this->capacite_detection = capacite_detection;
  this->champs_perception = 2*M_PI;
=======
/**
 * @brief Construct a new Oreilles:: Oreilles object
 * 
 * @param distance_ecoute distance d'écoute des oreilles
 * @param capacite_detection capacité de detection
 */
Oreilles::Oreilles(double distance_ecoute, double capacite_detection) {
    this->distance_ecoute = distance_ecoute;
    this->capacite_detection = capacite_detection;
>>>>>>> 68bd5a667bf4794937c06523cdcef382121a62cd
}

Oreilles::~Oreilles() {
}

float Oreilles::getCapaciteDetection( void ) {
  return this->capacite_detection;
}

float Oreilles::getDistanceEcoute( void ) {
  return this->distance_ecoute;
}

void Oreilles::setDistanceEcoute( float de ) {
  assert(de >= 0);
  this->distance_ecoute = de;
}

void Oreilles::setChampsPerception( float cp ) {
  assert(cp >= 0 && cp <= 2*M_PI);
  this->champs_perception = cp;
}

void Oreilles::setCapaciteDetection( float cd) {
  assert(cd >= 0 && cd <= 1);
  this->capacite_detection = cd;
}

bool Oreilles::detect(Bestiole * cette_bestiole, Bestiole* b)
{
   double         dist;
   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ((dist <= this->distance_ecoute) &&  (rand()/RAND_MAX <= this->capacite_detection));
}
