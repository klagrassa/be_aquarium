
#include "Yeux.h"
#define _USE_MATH_DEFINES
#include <math.h>

Yeux::Yeux(const Yeux & y) {
}

Yeux::Yeux(float capacite_perception, float angle_vision, float distance_vision) {
  this->capacite_perception = capacite_perception;
  this->angle_vision = angle_vision;
  this->distance_vision = distance_vision;
}

Yeux::~Yeux() {
}


float Yeux::getCapaciteDetection( void ) {
  return this->capacite_perception;
}

float Yeux::getDistanceVision( void ) {
  return this->distance_vision;
}

float Yeux::getAngleVision( void ) {
  return this->angle_vision;
}

void Yeux::setDistanceVision( float dv ) {
  assert(dv >= 0)
  this->distance_vision = dv;
}

void Yeux::setAngleVision( float av ) {
  assert(av >= 0 && av <= 2*M_PI)
  this->angle_vision = av;
}

void Yeux::setCapacitePerception( float cp) {
  assert(cp >= 0 && cp <= 1)
  this->capacite_perception = cp;
}
