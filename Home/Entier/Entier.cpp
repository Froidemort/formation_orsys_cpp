// debut de ./Entier/Entier.cpp
// lien physique avec ./Corriges-C++11/Entier/Entier.cpp
#include "Entier.h"
#include <iostream>        // std::cout

//#define ETAPE_2
//#define ETAPE_3
//#define ETAPE_4
//#define ETAPE_5

char const* Inchange = " (inchange depuis une etape precedente)" ;


int main( void) {          // ------------------------------------- 70

	std::cout << "\netape 1: creation de la variable A\n" ;
	Entier A( 1) ;
	std::cout << "A vaut " << A << '\n' ;

#ifdef ETAPE_2
	std::cout << "\netape 2: affectation d'un entier : A=2\n" ;
	A = 2 ;
	std::cout << "A vaut " << A << '\n' ;
#endif

#if defined( ETAPE_3) || defined( ETAPE_5)
	std::cout << "\netape 3: creation de B=A+1\n" ;
	Entier B=A+1 ;
	std::cout << "A vaut " << A << Inchange << '\n' ;
	std::cout << "B vaut " << B << '\n' ;
#endif

#if defined( ETAPE_4) || defined( ETAPE_5)
	std::cout << "\netape 4: creation de C=A\n" ;
	Entier C=A ;
	std::cout << "A vaut " << A << Inchange << '\n' ;
	std::cout << "C vaut " << C << '\n' ;
#endif

#if defined( ETAPE_5)
	std::cout << "\netape 5: affectation C=B+B\n" ;
	C=B+B ;
	std::cout << "B vaut " << B << Inchange << '\n' ;
	std::cout << "C vaut " << C << '\n' ;
#endif

// FAIRE: A=3
//        f( A) avec "Entier f( Entier)"

	std::cout << "\nfin du programme\n" ;
    return 0;
}   // fin de fichier
