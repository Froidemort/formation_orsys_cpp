// Fichier './Exemples/SmartPtr.cpp'
// Compiler: 'g++ -Wall -Wno-unused-variable SmartPtr.cpp -o SmartPtr'

#include <iostream>   // cout, endl
#include <cstring>    // strcpy()
#include <memory>     // auto_ptr

class Contact {
    char Nom[ 20] ; int  Age ;

  public:
    Contact( const char*S, int i) {
        std::strcpy( Nom, S) ;  // 'std::' pas (encore) obligatoire
        Age=i ;                // tant que <cstring> inclut <string.h>
        std::cout << "   Constructeur de " << S << "\n" ;
    }
    ~Contact() {
        std::cout << "   Destructeur de " << Nom << "\n" ;
    }

    size_t Sizeof( void) const { return sizeof *this ; }
    char const *GetNom( void) const { return Nom ; }
} ;



int main( void) {

//  Contact *p( new Contact( "Denis", 0)) ;  // Pensez au delete !

    // on n'a pas a faire delete pour un auto-pointeur
    std::auto_ptr< Contact > p( new Contact( "Denis", 0)) ;

    std::cout << "Un contact: " << p->GetNom() << std::endl ;

    return 0 ;                                                   // 70
}                                  // Fin de './Exemples/SmartPtr.cpp'
