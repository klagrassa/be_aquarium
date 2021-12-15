#ifndef _KAMIKAZE_H
#define _KAMIKAZE_H


#include "IComportement.h"

class Kamikaze : public IComportement {
    
    public:
        void bouge(Bestiole* bestiole_actuelle, std::vector<Bestiole*> bestioles);

    // ctor and dtor
    public:
        Kamikaze();
        ~Kamikaze();
};
#endif
