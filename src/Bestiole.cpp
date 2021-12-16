
#include "Bestiole.h"
#include "Capteur.h"
#include "Accessoire.h"
#include "Milieu.h"
#include "IComportement.h"

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

   age_lim = rand() % 300;
   std::cout<<"age lim : "<<age_lim<<std::endl;

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

/**
 * @brief Construct a copy Bestiole:: Bestiole object
 *
 * @param b bestiole a copier
 */
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

   // copier les capteurs / accessoires
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

/**
 * @brief Effectue une copie de la bestiole actuelle
 * @deprecated use copy ctor instead
 *
 * @param bestiole
 * @return Bestiole
 */
/* Bestiole Bestiole::clonage(const Bestiole &bestiole)
{
   return ;
} */

/**
 * @brief Renvoie l'âge actuel de la bestiole
 *
 * @return int age de la bestiole
 */
int Bestiole::getAge() const
{
   return this->age;
}

/**
 * @brief Renvoie la position en x de la bestiole
 *
 * @return int x position
 */
int Bestiole::getX() const
{
   return this->x;
}

/**
 * @brief Renvoie la position en y de la bestiole
 *
 * @return int y position
 */
int Bestiole::getY() const
{
   return this->y;
}

/**
 * @brief Renvoie l'orientation de la bestiole
 *
 * @return double angle d'orientation de la bestiole
 */
double Bestiole::getOrientation() const
{
   return this->orientation;
}

/**
 * @brief Initialisation des coordonnée à des points aléatoires
 *
 * @param xLim
 * @param yLim
 */
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
   std::cout<<"position de "<<this<<" : "<<x<<" "<<y<<std::endl;
}

bool Bestiole::action(const Milieu &monMilieu)
{
   bool mort = false;
   age++;
   bouge(monMilieu.getWidth(), monMilieu.getHeight());

   if (age >= age_lim)
   {
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

/**
 * @brief Ajoute un accessoire à la bestiole
 * 
 * @param acc accessoire à ajouter
 */
void Bestiole::ajouterAccessoire(Accessoire *acc)
{
   accessoires.push_back(acc);
}

/**
 * @brief Ajoute un capteur à la bestiole
 * 
 * @param cap capteur à ajouter
 */
void Bestiole::ajouterCapteur(Capteur* cap)
{
   capteurs.push_back(cap);
}

bool operator==(const Bestiole &b1, const Bestiole &b2)
{

   return (b1.identite == b2.identite);
}