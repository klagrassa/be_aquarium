
#include "Parametres_Sim.h"

Parametres_Sim::~Parametres_Sim() {
}

int Parametres_Sim::getHeight() const {
    return height;
}

int Parametres_Sim::getWidth() const {
    return width;
}

int Parametres_Sim::getDelay() const {
    return delay;
}


void Parametres_Sim::setWidth(int w){
    width = w;
}

void Parametres_Sim::setHeight(int h){
    height = h;
}

void Parametres_Sim::setDelay(int d){
    delay = d;
}

