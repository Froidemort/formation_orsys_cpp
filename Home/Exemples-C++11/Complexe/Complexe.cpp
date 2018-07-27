// debut de ./Exemples-C++11/Complexe/Complexe.cpp
#include <iostream>     // std::cout
#include <complex>      // std::complex
int main( void) {       // ---------------------------------------- 70

    std::complex< double> UnComplexe;
    UnComplexe = std::complex< double>( 2.0, 1.0);  //  2+i
    UnComplexe = UnComplexe + 10.0 ;                // 12+i

    if ( UnComplexe == std::complex< double>( 12.0, 1.0) ) {
        std::cout << "UnComplexe : " << UnComplexe << '\n';
    }
    return 0;
}   // fin de fichier
