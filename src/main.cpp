#include "Aquarium.h"
#include "Milieu.h"
#include "Parametres_Sim.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main()
{
   Parametres_Sim param = Parametres_Sim::getInstance();
   param.setWidth(640);
   param.setHeight(480);
   param.setDelay(30);

   Aquarium       ecosysteme(param);

   for ( int i = 1; i <= 20; ++i )
      ecosysteme.getMilieu().addMember( Bestiole(nullptr, nullptr, nullptr) );
   ecosysteme.run();


   return 0;

}
