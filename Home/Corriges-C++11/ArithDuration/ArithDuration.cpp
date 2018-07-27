// Debut de ./Corriges-C++11/ArithDuration/ArithDuration.cpp
#include <chrono>           // std::chrono
#include <iostream>         // std::cout std::endl
#include <iomanip>          // std::precision() std::fixed

typedef std::chrono::duration< int, std::ratio< 60, 3>> TiersDeMinute;
typedef std::chrono::duration< int, std::ratio< 60, 4>> QuartDeMinute;


// Ma fonction 'ToDouble<<' d'affichage d'une duree< Valeur, Ratio>
template< class V, class R>
double ToDouble(
    const std::chrono::duration< V, R>& d
) {
    return ( d.count() * (double)R::num ) / R::den ;
}


int main() { // --------------------------------------------------- 70

	using std::cout ;
    const TiersDeMinute DeuxTiers( 2) ;
    const QuartDeMinute UnQuart( 1) ;

    // Afficher les 'float' avec 2 decimales et forcer les 0 en fin
    cout << std::setprecision (2) << std::fixed ;

    cout << "2/3 de minute : " << ToDouble( DeuxTiers)     << " s\n";
    cout << "1/4 de minute : " << ToDouble(   UnQuart)     << " s\n";
    cout << "2/3 - 1/4 : " << ToDouble( DeuxTiers-UnQuart) << " s\n";
    cout << "2/3 + 1/4 : " << ToDouble( DeuxTiers+UnQuart) << " s\n";
    cout << "4 * 1/4   : " << ToDouble( 4*UnQuart)         << " s\n";

    return 0 ;
}   // fin de fichier
