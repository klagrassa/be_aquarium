
#include "../include/Milieu.h"
#include "../include/Bestiole.h"
#include "../include/Pondeuse.h"

//Avance la simulation d'un step
void Milieu::step() {
}

//Renvoie les bestioles qui doivent mourir de vieillesse

std::vector<Bestiole*> Milieu::verifier_vieillesse(const Bestiole* & bestioles) {
    
}

//Renvoie les bestioles clon�es. Le clonage ne se fait uniquement que si le taux de clonage de la bestiole est inf�rieur au taux de clonage donn�
//en param�tre.
std::vector<Bestiole*> Milieu::verifier_clonage(const Bestiole* & bestioles, double taux_clonage) {

}

Milieu::Milieu( int _width, int _height ): UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   std::cout << "const Milieu" << std::endl;

   std::srand( time(NULL) );

}

Milieu::~Milieu( void )
{

   std::cout << "dest Milieu" << std::endl;

}

void Milieu::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {

      it->action( *this );
      it->draw( *this );

   } // for

}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}
