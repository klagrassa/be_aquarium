#ifndef _CAPTEUR_H
#define _CAPTEUR_H


class Bestiole;

class Capteur {
  public:
    /**
    * @brief Detecter une autre bestiole a l'aide du capteur
    *
    * @param cette_bestiole bestiole actuelle
    * @param b bestiole a detecter
    */
    virtual Bestiole* detect(Bestiole * cette_bestiole, Bestiole* b) = 0;

};
#endif
