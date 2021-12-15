
#include "Yeux.h"
#include "Bestiole.h"
#include <cmath>

Yeux::Yeux(const Yeux & y) {
}

/**
 * @brief Construct a new Yeux:: Yeux object
 * 
 * @param capacite_perception capacité de perception des yeux
 * @param angle_vision angle de vision (en radian)
 * @param distance_vision distance de vision des yeux
 */
Yeux::Yeux(double capacite_perception, double angle_vision, double distance_vision) {
    this->capacite_perception = capacite_perception;
    this->angle_vision = angle_vision;
    this->distance_vision = distance_vision;
}

Yeux::~Yeux() {
}


double Yeux::getCapaciteDetection( void ) {
  return this->capacite_perception;
}

double Yeux::getDistanceVision( void ) {
  return this->distance_vision;
}

double Yeux::getAngleVision( void ) {
  return this->angle_vision;
}


void Yeux::setDistanceVision( double dv ) {
  if (dv >= 0) {
    this->distance_vision = dv;
  }
  else {
    this->distance_vision = 0;
  }
}

void Yeux::setAngleVision( double av ) {
  if (av >= 0 && av <= 2*M_PI) {
    this->angle_vision = av;
  }
  else {
    this->angle_vision = 0;
  }
}

void Yeux::setCapacitePerception( double cp) {
  if (cp >= 0 && cp <= 1) {
    this->capacite_perception = cp;
  }
  else {
    this->capacite_perception = 0;
  }
}

/**
 * @brief Implémentation de la detection pour les yeux 
 * 
 * @param cette_bestiole la bestiole qui doit detecter
 * @param b la bestiole qui doit être detectée
 * @return true si b est detectée
 * @return false si b n'est pas detectée
 */
bool Yeux::detect(Bestiole * cette_bestiole, Bestiole* b) {
   double         dist;
   dist = std::sqrt( (cette_bestiole->getX()-b->getX())*(cette_bestiole->getX()-b->getX()) 
   + (cette_bestiole->getY()- b->getY())*(cette_bestiole->getY()- b->getY()) );
   bool           distance;
   bool           angle;
   distance = (dist <= this->distance_vision);
   angle = (cette_bestiole->getOrientation() - atan(b->getX()/b->getY()) <= this->angle_vision);
   return (distance &&  angle && (rand()/RAND_MAX <= this->capacite_perception));
}
