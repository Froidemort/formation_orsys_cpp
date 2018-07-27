// Fichier ./Home/Debug/Main.cpp
// Lien    ./Home/Corriges-C++11/Debug/Main.cpp

#include "Debug.h"    // Debug() 
#include <thread>   // std::thread
#include <iostream> // std::cerr


// ---------------------------------------------------------------- 70
void f( char c) {
    int const i = 500 ;
    std::string Id( "f(") ; Id.append( 1, c) ; Id.append( ")") ;
    char const* szId = Id.c_str() ;
    Debug( szId, "debut avec i >%d<   c >%c<", i, c) ;

    std::string Inutile( i, c) ;    // Faites ce que vous voulez
                                    // Mais ne rien faire, c'est OK
    Debug( szId, "quitte avec Inutile.size() >%zd<", Inutile.size()) ;
}


// ---------------------------------------------------------------- 70
int main( void) {

    Debug( true, "main()") ;
    std::array< std::thread, 6> Tab {
        std::thread( f, '-') ,
        std::thread( f, '.') ,
        std::thread( f, '~') ,
        std::thread( f, '?') ,
        std::thread( f, '+') ,
        std::thread( f, 'o')
    } ;

    Debug( "main()", "tous les threads sont crees") ;
    for ( auto it = Tab.begin(); it != Tab.end(); it++) {
        it->join() ;
    }

    Debug( "main()", "fin normale du programme") ;
    return 0;
}   // Fin de ./Home/Debug/Main.cpp
