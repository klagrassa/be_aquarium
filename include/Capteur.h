#ifndef _CAPTEUR_H
#define _CAPTEUR_H


class Bestiole;

class Capteur {
  public:
    virtual Bestiole* detect(Bestiole * & bestioles, int x, int y) = 0;

};
#endif
