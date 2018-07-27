// Fichier './Exemples/Rationnel/Part3.h'
#if defined( PART3) || defined( PART4) || defined( PART5)

  public:
    Rationnel &operator += ( const Rationnel &r) {
        return ajoute( r) ;
    }

    #include "Part4.h"
#endif     // Fin de './Exemples/Rationnel/Part3.h'
