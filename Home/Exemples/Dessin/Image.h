// Fichier './Exemples/Dessin/Image.h'

#ifndef IMAGE_H_FILE
#define IMAGE_H_FILE

#include <stdio.h>   // pour fopen() ...
class DessinCercle ; // Declaration 'forward' necessaire
                     // pour mentionner 'DessinCercle'

class Image {
      FILE *fp ;

   public :
      Image( const char *fic) ; // Ouvre un fichier
      ~Image() ;                // Ferme le fichier

      void Dessine( const DessinCercle &) ;
} ;

#endif             // Fin de './Exemples/Dessin/Image.h'
