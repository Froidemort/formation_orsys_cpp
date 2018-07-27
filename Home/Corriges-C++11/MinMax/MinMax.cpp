// Debut de Home/Corriges-C++11/MinMax/MinMax.cpp
#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

inline auto Liste( std::vector< int> const& v) {

	std::for_each( v.cbegin(), v.cend(),
		// i est la valeur 'int' du vector< int> en position courante
		[] ( int i) { std::cout << i << ' ' ; }
	) ;
	std::cout << '\n' ;
}   // fin de Liste()



auto main( void) -> int { // -------------------------------------- 70

	const int MIN=0, MAX=9 ;

    std::random_device alea ;
    std::mt19937 eng( alea());
    std::uniform_int_distribution< int> distrib( MIN, MAX) ;
	// std::cout << distrib( eng) << '\n'; // Pour afficher un alea

	int const NbElems = 5 ;
	std::vector< int> v( NbElems) ;// les elements sont a 0 par defaut
	v[ 3]=3 ;                      // Pour verification
	Liste( v) ;

    // #define JE_N_ARRIVE_PAS_A_UTILISER_FILL
    # if defined( JE_N_ARRIVE_PAS_A_UTILISER_FILL)
		std::fill( v.begin(), v.end(), 
				[ & ] ( int& i) {
				    i=distrib( eng) ;
//				    std::cout << "alea=" << i << '\n';
				}
			) ;
	#else
		std::for_each( v.begin(), v.end(),
				[ & ] ( int& i) {
				    i=distrib( eng) ;
//				    std::cout << "alea=" << i << '\n';
				}
			) ;
	#endif
	std::cout << '\n' ;
	Liste( v) ;

	int vMax = MIN ; int vMin = MAX ;
	std::for_each( v.cbegin(), v.cend(),
				[ &vMin, &vMax ] ( int i) {
				    if ( i < vMin ) vMin = i ;
				    if ( i > vMax ) vMax = i ;
				}
			) ;
	std::cout << "vMin=" << vMin << " et vMax=" << vMax << '\n' ;
}   // end of file
