// Debut de ./Home/Exemples-C++11/detach/detach.cpp
#include <thread>
#include <iostream>       // std::cout  std::boolalpha

class Obj {
  public :
    Obj( void) { std::cout << "cree un Obj: ctor vide\n" ; }
  public :
    ~Obj()     { std::cout << "detruit un Obj: dtor\n" ; }
} ;

void foo( void) { // ------------------------------------------------- 73
    Obj Oo ;
    std::cout << "Dans foo() apres creation de 'Oo'\n" ;
    for (;;) ; // boucle infinie... mais le dtor de Oo est-il appele ?
}


int main() {  // ----------------------------------------------------- 73
    std::thread MonThread( foo) ;
//  MonThread.detach() ;           // Quelle difference cela fait-il ?

    std::this_thread::sleep_for( std::chrono::seconds( 1));

    std::cout << std::boolalpha;  // affiche "true" ou "false" ci dessous
    std::cout << "MonThread est joignable: " << MonThread.joinable() ;
    std::cout << "\n" ; return 0 ;
} // fin de fichier
