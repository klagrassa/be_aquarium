#include "../include/Aquarium.h"
#include "../include/Parametres_Sim.h"
#include "../include/Milieu.h"

/**
 * @brief Construct a new Aquarium:: Aquarium object
 * 
 * @param param Paramètres de la simulation
 */
Aquarium::Aquarium(const Parametres_Sim & param) : CImgDisplay(), delay( param.getDelay() )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   std::cout << "const Aquarium" << std::endl;

   flotte = new Milieu(param.getWidth(), param.getHeight());
   assign( *flotte, "Simulation d'ecosysteme");

   move( static_cast<int>((screenWidth-param.getWidth())/2), static_cast<int>((screenHeight-param.getHeight())/2) );
}

/**
 * @brief Destroy the Aquarium:: Aquarium object
 * 
 */
Aquarium::~Aquarium( void )
{

   delete flotte;

   std::cout << "dest Aquarium" << std::endl;

}

/**
 * @brief Fais tourner l'écosystème défini par le milieu
 * Utilise la variable "delay" (en ms) pour un tick de simulation
 * 
 */
void Aquarium::run( void )
{

   std::cout << "running Aquarium" << std::endl;

   while ( ! is_closed() )
   {

      // cout << "iteration de la simulation" << endl;

      if ( is_key() ) {
         std::cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         std::cout << " (" << key() << ")" << std::endl;
         if ( is_keyESC() ) close();
      }

      flotte->step();
      display( *flotte );

      wait( delay );

   } // while

}


