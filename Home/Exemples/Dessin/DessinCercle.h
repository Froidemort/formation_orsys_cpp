// Fichier './Exemples/Dessin/DessinCercle.h'

#ifndef DESSINCERCLE_H_FILE
#define DESSINCERCLE_H_FILE

#include "../Cercle/Cercle.h"
#include "Dessin.h"

class Image ;   // Declaration 'forward' qui evite 
                // #include "Image.h"

class DessinCercle: public Cercle, public Dessin {

  public:
    DessinCercle( int x, int y, int r, Couleur fond=jaune) :
      Cercle( x, y, r), Dessin( bleu, fond) {}

    friend void Image::Dessine( const DessinCercle &) ;
} ;

#endif  // Fin de './Exemples/Dessin/DessinCercle.h'
