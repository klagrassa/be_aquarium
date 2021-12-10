
#include "Yeux.h"
#include <cmath>

Yeux::Yeux(const Yeux & y) {
}

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

bool Yeux::detect(Bestiole * cette_bestiole, Bestiole* b) {
   double         dist;
   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   bool           distance;
   bool           angle;
   distance = (dist <= this->distance_vision);
   angle = (orientation - atan(b.x/b.y) <= this->angle_vision);
   return (distance &&  angle && (rand()/RAND_MAX <= this->capacite_perception));
}
