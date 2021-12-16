
#include "../include/Milieu.h"
#include "../include/Bestiole.h"
#include "../include/Pondeuse.h"

const T Milieu::white[] = {255,255,255};

//Renvoie les bestioles clon�es. Le clonage ne se fait uniquement que si le taux de clonage de la bestiole est inf�rieur au taux de clonage donn�
//en param�tre.
std::vector<Bestiole*> Milieu::verifier_clonage(const Bestiole* & bestioles, double taux_clonage) {

}

Milieu::Milieu( int _width, int _height ): UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   std::cout << "const Milieu" << std::endl;

   std::srand( time(NULL) );

   // création de la pondeuse
   this->pondeuse = new Pondeuse(this->param);

}

Milieu::~Milieu()
{
   delete param;
   delete pondeuse;
   delete instance;
   std::cout << "dest Milieu" << std::endl;
}

void Milieu::step( void )
{
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      if((*it)->action( *this )){
         delete *it;
         listeBestioles.erase(it);
         it--;
      }
      else{
         (*it)->draw( *this );
      }
   } // for

}


// TODO revoir l'intérêt de cette implémentation
/**
 * @brief Renvoie le nombre de voisins de la bestioles
 * 
 * @param b 
 * @return int 
 */
// int Milieu::nbVoisins( const Bestiole & b )
// {
//    int nb = 0;

//    for (std::vector<Bestiole>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it )
//       if (!(b == *it) && b.jeTeVois(*it))
//          ++nb;

//    for (auto it = this->listeBestioles.begin(); it != listeBestioles.end(); ++it)
//    {

//    }

//    return nb;
// }

/**
 * @brief Ajoute une bestiole dans le milieu. Initialise
 * ses coordonnées.
 * 
 * @param b bestiole à ajouter
 */
void Milieu::addMember(Bestiole* b) { 
   listeBestioles.push_back(b); 
   listeBestioles.back()->initCoords(width, height);
}

void Milieu::ponteInitiale(int nb_bestioles)
{
   if (nb_bestioles > 0)
      this->listeBestioles = this->pondeuse->creerBestioles(nb_bestioles);
}

/**
 * @brief Etablit les paramètres pour le milieu
 * 
 * @param param 
 */
void Milieu::setParametres(Parametres_Sim *parametre)
{
   this->param = parametre;
}

