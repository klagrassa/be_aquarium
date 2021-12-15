
#include "Multiple.h"

void Multiple::choisir_comportement() {
}

Multiple::Multiple(std::vector<IComportement*> liste_comportements) {
    this->liste_comportements = liste_comportements;
}

Multiple::Multiple(const Multiple & m) {
}

