// Fichier './Exemples/ZeroZero.cpp'
// compiler 'g++ -x c -Wall ZeroZero.cpp'
//          -x c : compile en C exclusivement

// Mais le C ne reconnait pas try {} catch {}
// Et le C++ n'intercepte pas les exceptions Linux

#include <stdio.h>

int main()
{
  try {
         printf("hello 1\n");
         int r=1;
         int k=0;
         int j=r/k;
         printf( "no exception 1\n");

  } catch (...) {

         printf("exception caught 1\n");
  }

  try  {
         printf("hello 2\n");
         double r=1;
         double k=0;
         double j=r/k;
         printf( "no exception 2\n");

  } catch (...) {

         printf("exception caught 2\n");
  }

  printf("leaving\n"); return 0;
} // Fin de './Exemples/ZeroZero.cpp'
