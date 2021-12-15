#ifndef _BESTIOLE_H
#define _BESTIOLE_H

#include "UImg.h"
#include <vector>

class Capteur;
class Accessoire;
class Milieu;
class IComportement;

class Bestiole
{
  private:
<<<<<<< HEAD

=======
>>>>>>> 68bd5a667bf4794937c06523cdcef382121a62cd
    double taux_clonage;
    int age;
    int age_lim;

    std::vector<Capteur *> capteurs;
    std::vector<Accessoire *> accessoires;
    IComportement *comportement;



    std::vector<Bestiole*> bestioles_environnantes;

private :
    static const double     AFF_SIZE;
    static const double     MAX_VITESSE;



    static int next;


  private:
    int identite;
    int x, y;
    double cumulX, cumulY;
    double orientation;
    double vitesse;

    T *couleur;

  public:
<<<<<<< HEAD
    Bestiole(const IComportement* comp, const Accessoire* acc, const Capteur* capteurs);
=======
    Bestiole(IComportement *comp, std::vector<Accessoire *> acc, std::vector<Capteur *> capteurs);
    Bestiole(const Bestiole &b);
>>>>>>> 68bd5a667bf4794937c06523cdcef382121a62cd
    ~Bestiole();
    Bestiole clonage(const Bestiole &bestiole);

<<<<<<< HEAD
  public:
    void action(const Milieu& milieu);
    void draw( UImg & support );
    void initCoords( int xLim, int yLim );
=======
    bool action(const Milieu &milieu);
    void draw(UImg &support);
    bool jeTeVois(const Bestiole &b) const;
    void initCoords(int xLim, int yLim);
>>>>>>> 68bd5a667bf4794937c06523cdcef382121a62cd

    int getAge() const;
<<<<<<< HEAD

  public:
    friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

  private :
    void bouge( int xLim, int yLim );
=======
>>>>>>> 68bd5a667bf4794937c06523cdcef382121a62cd

    friend bool operator==(const Bestiole &b1, const Bestiole &b2);

  private:
    void bouge(int xLim, int yLim);

  public:
    void ajouterAccessoire(Accessoire* acc);
    void ajouterCapteur(Capteur* cap);
};
#endif
