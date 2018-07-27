// Fichier './Exemples/Errno.cpp'

#include <iostream>    // pour cout cerr setlocale()
#include <fstream>     // pour ifstream
#include <errno.h>     // pour errno
#include <string.h>    // pour strerror()
using namespace std ;

int main( void)
{
#if defined( __linux__)
    setlocale( LC_ALL, "") ;           // erreurs en francais
#endif

    ifstream Essai( "@-((toto-ahah") ; // fichier inexistant

    if ( ! Essai ) {
        cerr << "Erreur : " << strerror( errno) ;
        cerr << " (code " <<  errno << ")\n" ;
    }
    return 0 ;
}                             // Fin de './Exemples/Errno.cpp'
