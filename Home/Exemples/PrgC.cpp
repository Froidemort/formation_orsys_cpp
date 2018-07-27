/* Fichier './Exemples/PrgC.cpp'
 * Petit programme en C, compile aussi en C++
 */

#include <stdio.h>
#define DEBUT -10
#define FIN 10
char MSG[] = "Hello world!"; /* declaration ou definition ? */

int carre(int x);   /* declaration ou definition ? */
int cube(int x);    /* ... mais obligatoire en C++ */

int main( void)
{
  int i;            /* declaration ou definition ? */
  extern int errno ;/* declaration ou definition ? */

  printf( "%s\n\n", MSG);
  printf( "        carre    cube\n") ;
  for ( i=DEBUT; i <=FIN; i++) {

     printf("%5d - %5d - %5d\n", i, carre( i), cube( i) );
  }
  return 0;
}


int cube( /* declaration ou definition de la fonction ? */
    int x /* declaration ou definition de la variable ? */
) {
    return x * carre( x);
}

int carre(
    int x
) {
   return x * x;
}  // Fin de './Exemples/PrgC.cpp'
