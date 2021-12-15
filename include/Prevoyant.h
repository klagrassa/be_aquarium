#ifndef _PREVOYANT_H
#define _PREVOYANT_H


#include "IComportement.h"

class Prevoyant : public IComportement {

    public:
        void bouge(Bestiole* bestiole_actuelle, std::vector<Bestiole*> bestioles);

    public:
        Prevoyant();
        ~Prevoyant();
};
#endif
