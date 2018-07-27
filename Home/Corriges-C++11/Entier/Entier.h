// debut de ./Corriges-C++11/Entier/Entier.h
#include <iostream>         // std::cerr

// Les messages de Debug sont tous en fin des methodes,
// avant le 'return'. C'est important car certaines methodes
// peuvent fabriquer des objets intermediaires.

//#define AVEC_CONSTRUCTEUR_VIDE
#define AVEC_CONVERTION_IMPLICITE
//#define AVEC_OPERATIONS_MOVE_DELETE

class Entier { // ------------------------------------------------- 70

  public :
// Constructeur et Affectation d'un entier
    Entier( int n) : _num( n) {
        std::cerr << "(debug) Constructeur a partir d'un int\n" ;
    }

    Entier& operator=( int e) {        // etape 2
        _num=e ;
        std::cerr << "(debug) Operateur affectation \"=\" d'un int\n";
        return *this ;
    }



// Constructeur et Affectation de copie
    Entier( Entier const& r) : _num( r._num) {
        std::cerr << 
              "(debug) Constructeur de copie a partir d'un Entier\n" ;
    }

    Entier& operator=( Entier const& r) {
        _num=r._num ;
        std::cerr <<
		"(debug) Operateur affectation par copie \"=\" d'un Entier\n";
        return *this ;
    }



// Constructeur et Affectation de deplacement
#ifdef AVEC_OPERATIONS_MOVE_DELETE
    Entier( Entier&& r) = delete ;
    Entier& operator=( Entier&& r) =delete ;
#else
    Entier( Entier&& r) : _num( r._num) {
        std::cerr <<
		"(debug) Constructeur de deplacement a partir d'un Entier\n" ;
    }

    Entier& operator=( Entier&& r) {
        _num=r._num ;
        std::cerr << "(debug) Operateur affectation par deplacement" ;
		std::cerr << " \"=\" d'un Entier\n" ;
        return *this ;
    }
#endif



// Destructeur
    ~Entier() {                        // etape 2 
        std::cerr << "(debug) Destructeur\n" ;
    }



// Constructeur vide sur option: on peut s'en passer dans cet exercice
#if defined( AVEC_CONSTRUCTEUR_VIDE) 
    Entier() : _num( 0) {
        std::cerr << "(debug) Constructeur vide\n" ;
    }
#endif



// Operation 'Entier + int'
    Entier operator+( int e) {        // etape 3
        Entier tmp( this->_num + e) ; // Appel constructeur a un 'int'
        std::cerr << "(debug) Operation Entier \"+\" int\n" ;
        return tmp ;
    }


#if defined( AVEC_CONVERSION_IMPLICITE) 
    operator int() {                // etape 5 si pas de 'explicit'
        std::cerr << "(debug) Conversion Entier --> int\n" ;
        return _num ;
    }
#else
    explicit operator int() {            // etape 5 avec 'explicit'
        std::cerr << "(debug) Conversion Entier --> int\n" ;
        return _num ;
    }

    Entier operator+( Entier const& e) {   //  etape 5 avec 'explicit'
        Entier tmp( this->_num + e._num) ; // Appel constructeur 'int'
        std::cerr << "(debug) Operation Entier \"+\" Entier\n" ;
        return tmp ;
    }
#endif


  private:
    int _num ;  // Pas de valeur par defaut: il n'y a pas de ctor vide

    // Pour memoire fonction 'amie'. Un Geteur aurait ete plus elegant
    friend std::ostream& operator<<( std::ostream &c,Entier const& e);

} ; // fin de 'class Entier'


inline std::ostream &operator << ( std::ostream& c, Entier const& e) {
    return c << '"' << e._num << '"' ;    
}

// fin de fichier
