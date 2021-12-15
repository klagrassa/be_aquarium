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
   static const double     LIMITE_VUE_DIST;
   static const double     LIMITE_VUE_ANGLE;
   static const double     VUE_CAPACITY;
   static const double     EARS_CAPACITY;


    static const double     AFF_SIZE;
    static const double     MAX_VITESSE;
    static const double     LIMITE_VUE;


    static int next;


  private:
    int identite;
    int x, y;
    double cumulX, cumulY;
    double orientation;
    double vitesse;

    T *couleur;

  public:
    Bestiole(IComportement *comp, std::vector<Accessoire *> acc, std::vector<Capteur *> capteurs);
    Bestiole(const Bestiole &b);
    ~Bestiole();
    Bestiole clonage(const Bestiole &bestiole);

    bool action(const Milieu &milieu);
    void draw(UImg &support);
    bool jeTeVois(const Bestiole &b) const;
    void initCoords(int xLim, int yLim);

    int getAge() const;

    friend bool operator==(const Bestiole &b1, const Bestiole &b2);

  private:
    void bouge(int xLim, int yLim);

  public:
    void ajouterAccessoire(Accessoire* acc);
    void ajouterCapteur(Capteur* cap);
};
#endif
