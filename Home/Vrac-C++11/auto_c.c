// Fichier 'FAIRE'
#include <stdio.h>

int i = 666 ;			// Variable globale du C creee en zone statique
// auto int j = 667 ;	// Une variable statique ne peut pas etre dans la pile

int main( void) {

	auto int j = 777 ;	// auto cree une variable de pile en C
	auto i = 0.999999 ;	// Warning: type defaults to 'int'

	printf( "i=>%d< j=>%d< i=>%f<\n", i, j, (double)i) ;
	return 0 ;
}	// fin de fichier
