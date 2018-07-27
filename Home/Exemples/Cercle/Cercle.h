// Fichier './Exemples/Cercle/Cercle.h'

#ifndef CERCLE_H_FILE
#define CERCLE_H_FILE

#include "Point.h"

// Un cercle est un 'Point' ... dote d'un rayon
class Cercle : public Point { // ou private, protected

  private:
    int rayon ;

  public :
    Cercle( int =0, int =0, int =0) ;      // vide
    Cercle( const Point &, int =0) ;
    Cercle( const Cercle &) ;              // copie

    int R( void) const { return rayon ; }
    double Aire( void) const ;
    double Perimetre( void) const ;
} ;

#endif  // Fin de './Exemples/Cercle/Cercle.h'
