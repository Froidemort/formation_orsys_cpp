// Debut du fichier './Exemples/Errno.cpp'

#include <iostream>    // pour cout, cerr
#include <fstream>     // pour ifstream
#include <locale>      // pour locale
using namespace std ;

int main( void)
{
    const char Fic[] = "toto" ;
#ifdef __linux__
    locale::global( locale::locale( "")) ;
#endif

    perror( "Avant") ;
    ifstream Essai( Fic) ;        // fichier inexistant

    if ( ! Essai ) {
        perror( Fic) ;	// Dans la langue de la var '$LANG'
    }
	cout << "... et le decimal   (cout): " << 3.14 << endl ;
	printf( "... et le decimal (printf): %.2f\n", 3.14) ;
    return 0 ;
}                         // Fin de './Exemples/Errno2.cpp'
