#ifndef _ICOMPORTEMENT_H
#define _ICOMPORTEMENT_H


class IComportement {

    public:
    virtual void bouge(Bestiole* bestiole_actuelle, std::vector<Bestiole*> bestioles) = 0;

    public:
    virtual ~IComportement() = 0;
};
#endif
