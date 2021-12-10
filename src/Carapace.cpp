
#include "Carapace.h"

Carapace::Carapace(const Carapace & c) {
}

Carapace::Carapace(float protection, float ralentissement) {
    
}

Carapace::~Carapace() {
}

/**
 * @brief recupere la valeur du coefficient de protection de la carapace
 * 
 * @return float 
 */
float Carapace::getProtection(void){
    return protection; 
};

/**
 * @brief met a jour le coeff
 * 
 * @param p est le coeff de protection 
 */
void Carapace::setProtection(float p){
    if(protection>=0)
        this->protection = p;
    else
        this->protection=0; 
}

/**
 * @brief recupere le coeff de ralentissement
 * 
 * @return float est le coeff de ralentissement
 */
float Carapace::getRalentissement(void ){
    return ralentissement; 
};

/**
 * @brief change le coeff de ralentissement
 * 
 * @param r est le coeff de ralentissement
 */
void Carapace::setRalentissement(float r){
    if (ralentissement>=0)
        this->ralentissement = r;
    else
        this->ralentissement=0; 
};