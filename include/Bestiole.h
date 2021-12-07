#ifndef _BESTIOLE_H
#define _BESTIOLE_H

#include "UImg.h"
#include <vector>

class Capteur;
class Accessoire;
class Milieu;
class IComportement;

class Bestiole {
  private:
    
    double taux_clonage;
    int age;

    std::vector<Capteur *> capteurs;
    std::vector<Accessoire *> accessoires;
    std::vector<IComportement *> comportements;

    std::vector<Bestiole*> bestioles_environnantes;

    static const double     AFF_SIZE;
    static const double     MAX_VITESSE;
    static const double     LIMITE_VUE;

    static int              next;

  private :
    int               identite;
    int               x, y;
    double            cumulX, cumulY;
    double            orientation;
    double            vitesse;

    T               * couleur;


  public:
    Bestiole(const IComportement* comp, const Accessoire* acc, const Capteur* capteurs); 
    ~Bestiole();
    Bestiole clonage(const Bestiole & bestiole);

    void action(const Milieu& milieu);
    void draw( UImg & support );
    bool jeTeVois( const Bestiole & b ) const;
    void initCoords( int xLim, int yLim );

    int getAge() const;
  
    friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
  
  private :
    void bouge( int xLim, int yLim );

};
#endif
