/* Fichier './Exemples/Octave.cpp'
 * compiler 'g++ -Wall Octave.cpp /usr/lib/octave-3.2.4/liboctave.so'
 * avec le package (debian) octave3.2-headers installe
 * et executer par LD_LIBRARY_PATH=/usr/lib/octave-3.2..... ./a.out
 */


#include <iostream>
#include <octave/oct.h>

int main( void)
{
    int n = 3 ;
    Matrix a_matrix = Matrix (n, n) ;

    for ( octave_idx_type i=0; i<n; i++) {
            for ( octave_idx_type j=0; j<n; j++) {
                a_matrix( i, j) = (i+1)*10 + (j+1) ;
            }
    }

    std::cout << "Soit une matrice M:\n" << a_matrix ;
    std::cout << "\n Multipliee par 2:\n" << a_matrix * 2 ;

    return 0;
}                   // Fin de './Exemples/Octave.cpp'
