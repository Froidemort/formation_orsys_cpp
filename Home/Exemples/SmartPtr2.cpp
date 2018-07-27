// Fichier './Exemples/SmartPtr2.cpp'

#include <iostream>   // std::cout, std::endl
#include <cstring>    // std::strcpy()
#include <memory>     // std::auto_ptr
#include <stdexcept>  // std::runtime_error

class Contact {
    char Nom[ 20] ; int  Age ;

  public:
    Contact( const char*S, int i) {
        std::strcpy( Nom, S) ; // 'std::' n'est pas (encore) obligatoire
        Age=i ;                // tant que <cstring> inclut <string.h>
        std::cout << "   Constructeur de " << S << "\n" ;
    }
    ~Contact() {
        std::cout << "   Destructeur de " << Nom << "\n" ;
    }

    size_t Sizeof( void) const { return sizeof *this ; }
    char const *GetNom( void) const { return Nom ; }
} ;

void foo( ) {
    throw std::runtime_error( "mon message d'erreur") ;
}


int main( void) {

    // L'exception "catchee" entraine le passage dans le destructeur
    try {
        std::auto_ptr< Contact > p( new Contact( "Denis", 0)) ;
        foo() ;
        std::cout << "Un contact: " << p->GetNom() << std::endl ;
        // delete ici ne serait pas execute si foo() leve une exception
    } catch ( const std::exception& e ) {
        std::cout << e.what() << std::endl ;
    }
    std::cout << "Instruction suivant le delete" << std::endl ;
    return 0 ;                                                     // 72
}                                   // Fin de './Exemples/SmartPtr2.cpp'
