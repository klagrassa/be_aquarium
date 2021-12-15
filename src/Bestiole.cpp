
#include "Bestiole.h"
#include "Capteur.h"
#include "Accessoire.h"
#include "Milieu.h"

#include "Constants.h"

#include <cstdlib>
#include <cmath>

int Bestiole::next = 0;

/**
 * @brief Construct a new Bestiole:: Bestiole object
 *
 * @param comp comportement de la bestiole
 * @param acc liste des accessoires de la bestiole
 * @param capteurs liste des capteurs de la bestiole
 */
Bestiole::Bestiole(IComportement *comp,
                   std::vector<Accessoire *> acc,
                   std::vector<Capteur *> capteurs)
{
   identite = ++next;

   std::cout << "const Bestiole (" << identite << ") par defaut" << this << std::endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>(rand()) / RAND_MAX * 2. * M_PI;
   vitesse = static_cast<double>(rand()) / RAND_MAX * MAX_VITESSE;

   age_lim = rand()%100;

   age = 0;

   this->accessoires = acc;
   this->capteurs = capteurs;
   this->comportement = comp;

   // TODO : ajouter des couleurs par comportement ?
   couleur = new T[3];
   couleur[0] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 230.);
   couleur[1] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 230.);
   couleur[2] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 230.);
}

Bestiole::Bestiole(const Bestiole &b)
{

   identite = ++next;

   std::cout << "const Bestiole (" << identite << ") par copie" << std::endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   couleur = new T[3];
   memcpy(couleur, b.couleur, 3 * sizeof(T));
}

/**
 * @brief Destroy the Bestiole:: Bestiole object
 *
 */
Bestiole::~Bestiole(void)
{
   std::cout << "dest Bestiole" << identite << this << std::endl;
   delete[] couleur;
   // destruction des objets possédé par la bestiole
   delete comportement;

   for (auto it = accessoires.begin(); it != accessoires.end(); it++)
      delete *it;

   for (auto it = capteurs.begin(); it != capteurs.end(); it++)
      delete *it;
}

Bestiole Bestiole::clonage(const Bestiole &bestiole)
{
}

int Bestiole::getAge() const
{
   return this->age;
}

void Bestiole::initCoords(int xLim, int yLim)
{

   x = rand() % xLim;
   y = rand() % yLim;
}

void Bestiole::bouge(int xLim, int yLim)
{

   double nx, ny;
   double dx = cos(orientation) * vitesse;
   double dy = -sin(orientation) * vitesse;
   int cx, cy;

   cx = static_cast<int>(cumulX);
   cumulX -= cx;
   cy = static_cast<int>(cumulY);
   cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ((nx < 0) || (nx > xLim - 1))
   {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else
   {
      x = static_cast<int>(nx);
      cumulX += nx - x;
   }

   if ((ny < 0) || (ny > yLim - 1))
   {
      orientation = -orientation;
      cumulY = 0.;
   }
   else
   {
      y = static_cast<int>(ny);
      cumulY += ny - y;
   }
}

bool Bestiole::action(const Milieu &monMilieu)
{
   bool mort = false;
   age ++;
   bouge(monMilieu.getWidth(), monMilieu.getHeight());

   if(age>=age_lim){
      mort = true;
   }
   return mort;
}

void Bestiole::draw(UImg &support)
{

   double xt = x + cos(orientation) * AFF_SIZE / 2.1;
   double yt = y - sin(orientation) * AFF_SIZE / 2.1;

   support.draw_ellipse(x, y, AFF_SIZE, AFF_SIZE / 5., -orientation / M_PI * 180., couleur);
   support.draw_circle(xt, yt, AFF_SIZE / 2., couleur);
}

bool operator==(const Bestiole &b1, const Bestiole &b2)
{

   return (b1.identite == b2.identite);
}

bool Bestiole::jeTeVois(const Bestiole &b) const
{

   double dist;

   dist = std::sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
   return (dist <= LIMITE_VUE);
}
