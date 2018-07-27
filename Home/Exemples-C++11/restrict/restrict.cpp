// Fichier Home/Exemples-C++11/restrict/restrict.cpp
// Compile en C99, C11 (sans warning) mais pas en C89, ni en C++11

void f( int* restrict p, int* restrict q) { (*p)++; (*q)++ ; }

int main( void) { int i=12; f( &i, &i) ; }
// fin de fichier
