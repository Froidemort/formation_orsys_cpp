// Fichier './Exemples/Cast.c'
// Compiler 'g++ -Wall Cast.c -o Cast' (pour C++)
//       ou par 'make Cast'            (pour C)


int main( void) {

    int i=9 ; int *pi = &i ;

    char *s ;
    void *u ;

    s = pi ;          // warning en C, erreur en C++
    s = (char *)pi ;  // OK

    s = u ;           // OK en C, erreur en C++
    s = (char *)u ;   // OK

    return 0 ;
}   // Fin du fichier './Exemples/Cast.c'
