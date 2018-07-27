#include <iostream>  // Fichier './Exemples/Float.cpp'
using namespace std ;

double MonMax( double a, double b) {
      return (a > b) ? a : b;
}

double MonMax( double a, double b, double c) {
      return MonMax(a, MonMax(b, c));
}

double MonMax( int n, double t[]) {
      if (n==0) return 0.0;
      if (n==1) return t[ 0];
      double m = t[ 0];
      for (int i=1 ; i<n; i++)
          m = MonMax(m, t[ i]) ;
      return m;
}

int main( void) {
  double x, y, z;
  double T[] = { 11.1, 22.2, 33.3, 44.4, 7.7 } ;

  x = MonMax( 1.86, 3.14);
  y = MonMax( 1.86, 3.14, 37.2);
  z = MonMax (sizeof T / sizeof (double), T);

  cout << x << " " << y << " " << z << endl ;
  return 0 ;
} // Fin de './Exemples/Float.cpp'
