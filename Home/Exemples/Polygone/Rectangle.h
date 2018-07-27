// Fichier './Exemples/Polygone/Rectangle.h'

#include <iostream>
#include "Polygone.h"

class Rectangle : public Polygone {

    public :
        Rectangle( int l, int h) : Polygone( 4) {
            SetCote( 0, l) ; SetCote( 2, l) ;
            SetCote( 1, h) ; SetCote( 3, h) ;
        }
        Rectangle( std::istream &) ;
        Rectangle( void) : Polygone( 4) {}

        void Affiche( void) const {
            std::cout << "Rectangle ---- " ;
            std::cout << Hauteur() << "x" << Largeur() << std::endl;
        }

        int Hauteur( void) const { return TabLongueurs[ 1] ; }
        int Largeur( void) const { return TabLongueurs[ 0] ; }
        int Aire( void) const { return Hauteur() * Largeur() ; }

} ;     // Fin de './Exemples/Polygone/Rectangle.h'
