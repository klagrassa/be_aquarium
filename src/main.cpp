#include "Aquarium.h"
#include "Milieu.h"
#include "Parametres_Sim.h"
#include "Bestiole.h"

#include <iostream>
#include <typeinfo>


int main()
{
   Parametres_Sim param = Parametres_Sim::getInstance();
   Parametres_Sim param2 = Parametres_Sim::getInstance();
   const char* s = typeid(param).name(); // works
   std::cout <<"this is : " << s << std::endl;

   std::cout << "test singleton" << &param << " and " << &param2;
   param.setWidth(640);
   param.setHeight(480);
   param.setDelay(30);

   Aquarium ecosysteme(param);

   for ( int i = 1; i <= 20; ++i )
      //ecosysteme.getMilieu().addMember( new Bestiole(nullptr, nullptr, nullptr) );
   ecosysteme.run();


   return 0;

}
