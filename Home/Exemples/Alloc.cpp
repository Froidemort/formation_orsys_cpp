// Fichier './Exemples/Alloc.cpp'

#include "Point/Point.h"

int main( void) {

    // Instanciation d'un tableau de 10 'Point' au sens du C
    Point *a = new Point[ 10]; // a est un tableau de 10 'Point'

    // Instanciation d'un 'Point' par reference C++ seulement
    Point &b = *new Point ;    // b est un 'Point'

    
    // Je ne sais pas faire des tableaux de references
//  Point (&c)[ 10] = *a ;     // Pas d'idee pour creer une 
                               // reference de Tableau...
// erreur: invalid initialization of reference of type
//         'Point (&)[10]' from expression of type 'Point'

    // Il faut autant de delete qu'il y a de new !
    delete [] a;
    delete &b ;
}                               // Fin de './Exemples/Alloc.cpp'
