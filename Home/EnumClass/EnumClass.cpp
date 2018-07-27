// Fichier ./Home/EnumClass/EnumClass.cpp'

#include <iostream>				// std::cout std::cerr

enum Face { Un=1, Deux, Trois, Quatre, Cinq, Six } ;

class De {
  public:
	De( void) noexcept {
		std::cerr << "constructeur vide\n" ;
		roule();
	}
	Face valeur( void) const noexcept { return _face; } ;
    Face roule( void) noexcept {
		static bool InitOk = false ;
		if ( ! InitOk ) {
			InitOk = true ;
			srand( time( NULL)) ;
		}
//		_face = rand() ;	   // Le developpeur commet un bogue ici
		_face = (Face)rand();  // Il "corrige" avec un cast pour compiler
		return _face ;
	}	// fin de la methode roule()

  private:
    Face _face ;
};  // fin de class De

inline std::ostream& operator<<( std::ostream& c, De const& d)  // --- 73
throw( std::runtime_error) {
	return c << d.valeur() ;
}


int main( void) {

	De d, Tab[ 5] ;
	std::cout	<<	"Un de    : " << d << '\n' ;
	std::cout	<<	"Un autre : " << De() << '\n' ;

	std::cout	<<	"Tableau de 5 des:" ;
	for ( size_t i=0; i<5; i++) {
		std::cout << " " << Tab[ i] ;
	}
	std::cout	<< '\n' ;

	std::cout	<<	"Objet errone : " << Tab[ 10] << '\n' ;
	return 0 ;
}	// fin de main()

// fin de fichier
