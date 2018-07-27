// Fichier './Exemples/Polygone/Carre.h'

#include "Rectangle.h"

class Carre : public Rectangle {

    public :
        Carre( int c) : Rectangle( c, c) {}
        Carre( std::istream &) ;
        Carre( void) {}

        void Affiche( void) const {
            std::cout << "Carre ---- " ;
            std::cout << "\tcote :" << TabLongueurs[ 0] ;
            std::cout << std::endl ;
        }

} ;     // Fin de './Exemples/Polygone/Carre.h'
