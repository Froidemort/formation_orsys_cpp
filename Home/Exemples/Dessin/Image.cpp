// Fichier './Exemples/Dessin/Image.cpp'

#include "Image.h"
#include "DessinCercle.h"
#include <stdlib.h>  // pour exit()

// -- Etudier en passant l'erreur generee dans un constructeur
Image::Image(  // --------- Un seul constructeur
    const char *fic
) {
   fp = fopen( fic, "w") ;
   if ( ! fp ) {
      char s[ 80] ;
      sprintf( s, "erreur fopen(\" %s\") en ecriture", fic) ;
      perror( s) ;
      // L'objet ne sera pas cree, et donc ne sera jamais detruit
      exit( 1) ;   // pas de return d'un objet incorrect
   }
   fprintf( fp,
       "<?xml version='1.0' standalone='no'?>\n\n"
       "<!DOCTYPE svg PUBLIC '-//W3C//DTD SVG 1.1//EN' "
       "'http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd'>\n\n"
       "<svg width='8cm' height='6cm' version='1.1' "
       "xmlns='http://www.w3.org/2000/svg' viewport='0 0 800 600'>\n\n"
   ) ;
}



Image::~Image(
) {
   fprintf( fp, "</svg>\n") ;
   fclose( fp) ;
}



void Image::Dessine(
   const DessinCercle &d
) {
   fprintf( fp,
     "<circle cx='%d' cy='%d' r='%d' stroke='%s' "
     "stroke-width='%d' fill='%s'/>\n" ,
     d.X(), d.Y(), d.R(), d.Trait(), d.EpaisseurTrait(), d.Fond()
   ) ;
}

// Fin de './Exemples/Dessin/Image.cpp'
