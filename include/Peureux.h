#ifndef _PEUREUX_H
#define _PEUREUX_H


#include "IComportement.h"

class Peureux : public IComportement {

    public:
        void bouge(Bestiole* bestiole_actuelle, std::vector<Bestiole*> bestioles);
    
    // ctor and dtor
    public:
        Peureux();
        ~Peureux();
};
#endif
