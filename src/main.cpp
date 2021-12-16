#include "Aquarium.h"
#include "Milieu.h"
#include "Parametres_Sim.h"
#include "Bestiole.h"

#include <iostream>
#include <typeinfo>


int main()
{
   Parametres_Sim *param = Parametres_Sim::getInstance();

   std::vector<double> proportions = 
   {
      0.4,
      0,
      0,
      0.6,
      0
   };
   //const char* s = typeid(param).name(); // works
   //std::cout <<"this is : " << s << std::endl;

   param->setWidth(640);
   param->setHeight(480);
   param->setDelay(30);

   param->setProportions(proportions);

   Aquarium ecosysteme(param);

   // Génération des bestioles
   ecosysteme.getMilieu().ponteInitiale(5);

   std::cout << "start"; // debug point

   //for ( int i = 1; i <= 20; ++i )
      //ecosysteme.getMilieu().addMember( new Bestiole(nullptr, nullptr, nullptr) );
   ecosysteme.run();


   return 0;

}
