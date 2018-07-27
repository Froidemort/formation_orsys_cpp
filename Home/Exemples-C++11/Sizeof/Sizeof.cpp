// Debut de  ./Exemples-C++11/Sizeof/Sizeof.cpp
#include <stdio.h>               // printf()
#include <stddef.h>              // cf 'man types.h' et 'man stddef.h'

#ifdef __linux__                 // remplace 'linux'
    // NB. La constante 'linux' a disparu en g++ -std=c++11
    #pragma message "Compilation specifique a Linux."
    const char FORMAT[] = "   %-2zd   %s\n" ;
#else
    #pragma message( "Compilation pour autre systeme que Linux.")
    const char FORMAT[] = "   %-2d   %s\n" ;
#endif

int main( void) {  // ------------------------------------------------ 73

    struct T {
        int i ;
        double d ;  
    } A ;

    printf( "\n     Taille de ...\n     ------------\n") ;
    printf( "octet(s)  objet\n") ;
    printf( FORMAT, sizeof (short),       "short") ;
    printf( FORMAT, sizeof (int),         "int") ;
    printf( FORMAT, sizeof (long),        "long") ;
    printf( FORMAT, sizeof (long long),   "long long") ;
    printf( FORMAT, sizeof (float),       "float") ;
    printf( FORMAT, sizeof (double),      "double") ;
    printf( FORMAT, sizeof (long double), "long double");
    printf( FORMAT, sizeof (T), "class T");
    printf( FORMAT, sizeof (T::i), "class T::i");
    printf( FORMAT, sizeof (T::d), "class T::d");
//    printf( FORMAT, sizeof (main()::T::i), "main()::T::i");
    printf( FORMAT, sizeof A, "A");
    printf( FORMAT, sizeof A.d, "A.d");
    return 0 ;
} // Fin de fichier
