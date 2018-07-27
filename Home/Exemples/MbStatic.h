// Fichier './Exemples/MbStatic.h'

class Rationnel {   // Une classe ----------------------
    int numerator, denominator ;
    static unsigned int _nb ;  // private par defaut
  public :
    Rationnel( void) {         // Un constructeur 
        numerator = 0 ; denominator = 1 ; _nb++ ;
    } 
    
    Rationnel( int a, int b) { // Et un autre incomplet: que faire 
                               // si b==0 ? Correction plus loin...
        numerator = a ; denominator = b ; _nb++ ;
    } 
    
    ~Rationnel( ) {           // Le destructeur 
        _nb-- ;
    }

    static unsigned int NbRationnels( void) {
        return _nb ;
    }
} ;

// L'initialisation du membre statique est obligatoire! Sinon l'objet
// ne peut pas etre instancie, par exemple dans la fonction main(), il
// faut mettre la ligne suivante dans un fichier toto.cpp pour qu'elle
// soit prise en compte par le compilateur. Peu importe le fichier,
// mais il faut une ligne (une seule) pour initialiser le champ statique
//    unsigned int Rationnel::_nb = 0 ;

// Fin du fichier './Exemples/MbStatic.h'
