
#include "Multiple.h"

void Multiple::bouge(Bestiole *bestiole_actuelle, std::vector<Bestiole *> bestioles)
{
}

Multiple::Multiple()
{
    this->liste_comportements = {
        new Gregaire(),
        new Kamikaze(),
        new Peureux(),
        new Prevoyant()
    };
}

Multiple::Multiple(const Multiple &m)
{
}

Multiple::~Multiple() {}