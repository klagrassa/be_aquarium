#ifndef _GREGAIRE_H
#define _GREGAIRE_H


#include "IComportement.h"

class Gregaire : public IComportement {
    public:
        void bouge(Bestiole* bestiole_actuelle, std::vector<Bestiole*> bestioles);

    // ctor and dtor
    public:
        Gregaire();
        ~Gregaire();
};
#endif
