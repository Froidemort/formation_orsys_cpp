// Fichier './Exemples/Mutable.cpp'
#include <iostream>

class Example {

   public:
      
     // 'x' peut etre modifie par les methodes 'const'
     mutable int x;

     void Set_x( int y) const ;

     // A l'inverse 'y' est 'const' dans tous les cas
     // const int y ; // Erreur compilation 'y' doit etre initialise
     // const int y=2;// Erreur compilation instruction interdite
     enum { y = 2 } ; // Grosse astuce !

} ;


inline void Example::Set_x(int y) const {
   x = y ;
}


int main( void) {

   Example e;

   std::cout << e.x << std::endl ;    // non initialise
   e.Set_x( 10);
   std::cout << e.x << std::endl ;

   // e.y = 3 ;
   // error: lvalue required as left operand of assignment

   std::cout << e.y << std::endl ;
   return 0 ;
}                    // Fin de './Exemples/Mutable.cpp'
