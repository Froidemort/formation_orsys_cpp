// #define TEMPLATE_MAIN
#include <iostream>

#ifdef TEMPLATE_MAIN
template< typename T>		// Ne compile pas, d'ailleurs
int main( void)				// comment specifier quelle
{ 							// instance de main() on veut
	T x( 6.666) ;			// faire ? Mais le developpeur
							// a plus d'un tour dans son sac...
	std::cout << "template de fonction main() : " ;
	std::cout << x << std::endl ;
	return 0 ;
}

#else
template< typename T>
int f( void)
{ 
	T x( 6.666) ;

	std::cout << "template de fonction main() : " ;
	std::cout << x << std::endl ;
	return 0 ;
}
int main( void) { return f< int>() ; }
#endif
