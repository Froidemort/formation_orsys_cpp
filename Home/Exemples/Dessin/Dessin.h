// Fichier './Exemples/Dessin/Dessin.h'

#ifndef DESSIN_H_FILE
#define DESSIN_H_FILE

enum Couleur { bleu, vert, jaune, noir, blanc, rouge } ;

inline const char *Couleur2Texte( Couleur x) {
    switch ( x ) {
        case bleu : return "blue" ;    // en anglais pour le SVG
        case vert : return "green" ;
        case jaune: return "yellow" ;
        case noir : return "black" ;
        case blanc: return "white" ;
        case rouge: return "red" ;
        default : return "red" ;
    }
}

class Dessin {

    Couleur t, f ;  // CouleurTrait ,  CouleurFond
    int e ;         // EpaisseurTrait

  protected:
    void EpaisseurTrait( int ep) { e = ep ; }

  public:
    int EpaisseurTrait( void) const { return e ; }
    const char *Trait( void) const { return Couleur2Texte( t) ; }
    const char *Fond( void) const { return Couleur2Texte( f) ; }

    Dessin( Couleur trait=bleu, Couleur fond=jaune) {
        t=trait; f=fond; e=5 ;
    }
    Dessin( const Dessin &dessin) {
        t=dessin.t; f=dessin.f; e=dessin.e;
    }
} ;

#endif      // Fin de './Exemples/Dessin/Dessin.h'
