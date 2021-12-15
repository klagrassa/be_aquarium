
#include "Yeux.h"

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

