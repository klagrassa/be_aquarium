#ifndef _MILIEU_H
#define _MILIEU_H

#include "UImg.h"

#include <iostream>
#include <vector>

class Bestiole;
class Pondeuse;
class Parametres_Sim;

using namespace cimg_library;

class Milieu : public UImg
{
private:
  // Attributs liés à la simulation
  Pondeuse *pondeuse = nullptr;
  Milieu *instance = nullptr;
  Parametres_Sim *param;

  // Attributs liés aux bestioles
  std::vector<Bestiole *> listeBestioles;


  // Couleur du milieu
  static const T white[];
  int width, height;

public:
  // Avance la simulation d'un step
  void step(void);

  std::vector<Bestiole *> verifier_clonage(const Bestiole *&bestioles, double taux_clonage);
  int nbVoisins(const Bestiole &b);
  void addMember(Bestiole *b);

// ctor and dtor
public:
  Milieu(int _width, int _height);
  ~Milieu();

  int getWidth(void) const { return width; };
  int getHeight(void) const { return height; };

  void ponteInitiale(int nb_bestioles);
  void setParametres(Parametres_Sim *param);
};
#endif
