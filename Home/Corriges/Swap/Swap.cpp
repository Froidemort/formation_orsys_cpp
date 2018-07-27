// Debut de './Corriges/Swap/Swap.cpp'
#include <iostream>
using namespace std;

int change(
    double &a, double &b
) {
    double c = a ; a = b ; b = c ;
}

int main( void) {   // ------------------------------------------------
//  int i=3, j=9 ;           // Conversion vers 'int &' impossible
    double i=3.14159, j=9.99999 ;
    cout << "avant i=" << i << " j=" << j << endl ;
    change( i, j) ;
    cout << "apres i=" << i << " j=" << j << endl ;
}   // Fin de fichier './Corriges/Swap/Swap.cpp'
