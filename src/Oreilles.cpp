
#include "Oreilles.h"
#include <cmath>


Oreilles::Oreilles(const Oreilles & c) {
}

Oreilles::Oreilles(float distance_ecoute, float capacite_detection) {
  this->distance_ecoute = distance_ecoute;
  this->capacite_detection = capacite_detection;
  this->champs_perception = 2*M_PI;
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
