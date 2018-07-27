// Le programme ci apres ne compile pas... pourquoi ?
// Pour corriger il faut initialiser C directement ainsi:

#include <atomic>			// std::atomic

int main( void) {

//	std::atomic< char> C( ' ') ;	// compile bien: cela montre la clarte de la notation fonctionnelle
	std::atomic< char> C = ' ' ;	// erreur de compilation avec gcc 4.9 le 10 marzo 2015

	return 0 ;
}	// Fin de main()
