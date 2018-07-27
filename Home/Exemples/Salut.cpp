// Fichier './Exemples/Salut.cpp'

#include <cstdio>   // pour printf()
#include <cstdlib>  // pour exit()

// using namespace std ; // trop general car tous les objets de 'std'
                         // sont susceptibles d'etre designes
// using std::printf ;   // meilleur choix, mais il y a peut etre
// using std::exit ;     // beaucoup d'objets a renommer

int main( void)
{
   std::printf( "Salut la compagnie\n"
           "euh... Hello world!\n"
         ) ;

   std::exit( 0) ;

}              // Fin de './Exemples/Salut.cpp'
