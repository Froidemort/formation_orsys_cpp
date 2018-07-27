// Debut de Home/Exemples-C++11/shared_ptr/shared_ptr.cpp
#include <iostream>    // std::cout
#include <memory>      // std::shared_ptr

using std::cout ; using std::shared_ptr ; using std::unique_ptr ;

#define UNIQUE_PTR  // Mettre en commentaire pour compiler en SHARED_PTR


// Pour inclure la classe Foo depuis l'exemple precedent ------------- 73
#define SHARED_PTR_CPP_FILE
#include "../unique_ptr/unique_ptr.cpp"



// ------------------------------------------------------------------- 73
#ifdef UNIQUE_PTR
void func( unique_ptr< Foo> pX) { pX->Affiche( "dans func()") ; return; }
#else
void func( shared_ptr< Foo> pX) { pX->Affiche( "dans func()") ; return; }
#endif



int main( void) { // ------------------------------------------------- 73

#ifdef UNIQUE_PTR
    unique_ptr< Foo> p0( new Foo( "p0")) ;
    func( p0) ;
#else
    shared_ptr< Foo> p0( new Foo( "p0")) ;
    func( p0) ;
#endif

}   // fin de main()
