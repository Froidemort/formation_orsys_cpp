// Fichier 'FAIRE'
#include <stdio.h>

auto i = 666 ;			// Variable globale du C creee en zone statique

int main( void) {

	auto j = 777 ;		// 'auto int j' ne compile plus en C++11
	auto i = 0.999999 ;	// i est de type double automatiquement

	printf( "i=>%d< j=>%d< i=>%f<\n", (int)i, j, i) ;
	return 0 ;
}	// fin de fichier
