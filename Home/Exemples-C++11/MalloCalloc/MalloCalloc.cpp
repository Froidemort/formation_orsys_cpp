// Debut de './Exemples-C++11/MalloCalloc.cpp'
// Quelle difference de performance entre malloc() et calloc()? La
// doc specifie que calloc() initialise les octets a '\0', ce que ne 
// fait pas malloc(). Quel impact sur les performances? L'espace
// alloue a calloc() est-il reellement alloue? (pour y mettre '\0')

#include <iostream>      // std::cout ...
#include <iomanip>       // std::setw() std::left std::right std::fill()
#include <ctime>
#include <ratio>
#include <chrono>

int main () {  // --------------------------------------------------- 72

    using namespace std::chrono;
    const size_t Bytes = 1000000 ;   // un million
    const size_t NbTab =   10000 ;   // dix mille
    const int    Nb    =    1000 ;   // mille
    unsigned int err_malloc = 0 ; unsigned int err_calloc = 0 ;

  while ( 1 ) {

    steady_clock::time_point A = steady_clock::now();
    for ( int i=0; i<Nb; i++) if ( ! malloc( NbTab*Bytes) ) {
        if ( err_malloc == 0 ) perror( "malloc") ;
        err_malloc++;
    }
    steady_clock::time_point B = steady_clock::now();
    duration< double> Duree = duration_cast< duration< double>>( B-A);
    std::cout << std::setw( 4)  << std::right << Nb-err_malloc ;
    std::cout << " fois malloc( " << NbTab*Bytes << ")     duree: " ;
    std::cout << std::setw( 10) << std::left << Duree.count() << " s\n";

    steady_clock::time_point R = steady_clock::now();
    for ( int i=0; i<Nb; i++) if ( ! calloc( NbTab, Bytes) ) {
        if ( err_calloc == 0 ) perror( "malloc") ;
        err_calloc++;
    }
    steady_clock::time_point S = steady_clock::now();
    Duree = duration_cast< duration< double>>( S-R);
    std::cout << std::setw( 4) << std::right << Nb-err_calloc ;
    std::cout << " fois calloc( " <<NbTab<<", "<<Bytes<< ")  duree: ";
    std::cout << std::setw( 10) << std::left << Duree.count() << " s\n";

    if ( err_malloc+err_calloc ) { return 0 ; }   // Fin normale du test
    else { std::cout << "---- aucune erreur: on rejoue.\n"; }
  }
}    // fin du fichier
