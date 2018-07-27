// debut de ./Corriges-C++11/Entier/Entier.h
#include <iostream>         // std::cerr

// Les messages de Debug sont tous en fin des methodes, avant le 'return'
// C'est important car certaines methodes peuvent fabriquer des objets intermediaires

//#define AVEC_CONSTRUCTEUR_VIDE

class Entier {

  public :
    Entier( int n) : _num( n) {
		std::cerr << "(debug) Constructeur a partir d'un int\n" ;
    }



    Entier( Entier const& r) : _num( r._num) {
		std::cerr << "(debug) Constructeur de copie a partir d'un Entier\n" ;
	}

	Entier& operator=( Entier const& r) {
        _num=r._num ;
        std::cerr << "(debug) Operateur affectation par copie \"=\" d'un Entier\n" ;
        return *this ;
	}



// Constructeur vide sur option, car on peut s'en passer dans cet exercice
#if defined( AVEC_CONSTRUCTEUR_VIDE) 
    Entier() : _num( 0) {
		std::cerr << "(debug) Constructeur vide\n" ;
    }
#endif



  private:
    int _num ;	// Pas de valeur par defaut: il n'y a pas de ctor vide

	// Pour memoire: fonction 'amie'. Un Get'eur aurait ete plus elegant
    friend std::ostream &operator <<( std::ostream &c, Entier const& e) ;

} ;	// fin de 'class Entier'


inline std::ostream &operator << ( std::ostream& c, Entier const& e) {
	return c << '"' << e._num << '"' ;	
}

// fin de fichier
