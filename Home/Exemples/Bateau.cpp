// Fichier ./Exemples/Bateau.cpp

#include <iostream>
using namespace std ;   // Obsolete: tjs preferer std::cout ...

class Bateau {
  public:
    char* Nom ;         // Volontairement 'public' pour simplifier -70
    ~Bateau()
      { cout << "<-- Fin de " << Nom << endl ; }

    Bateau( char* s)            // Constructeur parametre ------------
      { Nom=s; cout << "--> Debut de " << Nom << endl ; }

    Bateau( Bateau const& r)    // Constructeur de copie -------------
      { Nom=r.Nom; cout << "--> Copie de " << Nom << endl ; }
} ;


void foo1( Bateau const r) {    // -----------------------------------
   cout << "    foo1    " << r.Nom << endl ; return ;
} // que se passe-t-il si 'Bateau foo( Bateau r) { ..... return r ; }


void foo2( Bateau const& r) {   // -----------------------------------
   cout << "    foo2    " << r.Nom << endl ; return ;
}


int main( void) {     // ---------------------------------------------

   Bateau f( (char*)"f est dans main()") ;
   Bateau g( (char*)"g est dans main()") ;
   cout << endl ;                          // pour sauter une ligne
   foo1( f) ;
   cout << endl ;                          // puis une autre ligne
   foo2( g) ;
   cout << endl ;                          // et une troisieme
}  // fin de main()
// Fin de fichier
