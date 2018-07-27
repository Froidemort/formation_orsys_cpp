// Fichier './Exemples-C++11/SysExcept.cpp'
#include <iostream>      // cerr
#include <fstream>       // classe ifstream
#include <string>        // classe string et c_str()

int main( void) {  // ------------------------------------------------ 70

    // Lever une exception est optionnel; il faut activer le dispositif
    std::string MonFich( "Gillain.dbf") ; std::ifstream Fichier ;
    Fichier.exceptions( std::ifstream::failbit | std::ifstream::badbit) ;

    try {
        Fichier.open( MonFich.c_str(), std::ios::in) ;
        Fichier.close() ;
    } catch ( std::system_error const& e ) {
        std::cout << "Caught system_error with code " << e.code() 
                  << " meaning " << e.what() << '\n';
        return 2 ;
    } catch ( ... ) {
        std::cerr << "Unknown exception caught\n" ;
        return 2 ;
    }
    return 0 ;
}   // fin de fichier
