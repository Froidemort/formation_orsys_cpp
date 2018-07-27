// Fichier './Exemples-C/sizeof/sizeof.c' dans cours C
// Fichier './Sizeof/Sizeof.c' dans cours C++ (lien physique)
#include <stdio.h>               // printf()
#include <stddef.h>              // cf 'man types.h' et 'man stddef.h'

#ifdef __linux__                 // autrefois 'linux'
    // NB. La constante 'linux' a disparu en g++ -std=c++11
    #pragma message "Compilation specifique a Linux."
    const char FORMAT[] = "   %-2zd   %s\n" ;
#else
    #pragma message( "Compilation pour autre systeme que Linux.")
    const char FORMAT[] = "   %-2d   %s\n" ;
#endif

int main( void)                  // Taille des objets
{ short tab[ 10], *px ;
  printf( "\n     Taille de ...\n     ------------\n") ;
  printf( "octet(s)  objet\n") ;
  printf( FORMAT, sizeof (char),        "char") ;
  printf( FORMAT, sizeof (wchar_t),     "wchar_t") ;
  printf( FORMAT, sizeof (short),       "short") ;
  printf( FORMAT, sizeof (int),         "int") ;
  printf( FORMAT, sizeof (long),        "long") ;
  printf( FORMAT, sizeof (long long),   "long long") ;
  printf( FORMAT, sizeof (float),       "float") ;
  printf( FORMAT, sizeof (double),      "double") ;
  printf( FORMAT, sizeof (long double), "long double");
  printf( FORMAT, sizeof 'a',           "'a'") ;
  printf( FORMAT, sizeof ((char)'a'),   "(char) 'a'") ;
  printf( FORMAT, sizeof 12.0,          "12.0") ;
  printf( FORMAT, sizeof 12.0F,         "12.0f") ;
  printf( FORMAT, sizeof 12.0L,         "12.0l") ;
  printf( FORMAT, sizeof 12L,           "12L") ;
  printf( FORMAT, sizeof 12LL,          "12LL") ;
  printf( FORMAT, sizeof (char *),      "char *") ;
  printf( FORMAT, sizeof (char **),     "char **") ;
  printf( FORMAT, sizeof (void (*)),    "void (*)") ;
  printf( FORMAT, sizeof (short *),     "short *") ;
  printf( FORMAT, sizeof (px),          "px") ;
  printf( FORMAT, sizeof (*px),         "*px") ;
  printf( FORMAT, sizeof (tab),         "tab") ;
  printf( FORMAT, sizeof (size_t),      "size_t") ;
  return 0 ;
} // Fin de './Exemples-C/sizeof/sizeof.c'
