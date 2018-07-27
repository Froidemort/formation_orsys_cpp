// Fichier './Home/Constructeurs/Constructeurs.cpp'
#include <iostream>
using std::cout ;

class T {   // -------------------------------------------------------------- 80
  public:
	T( void) : _size( 0), _page( nullptr)
		{ cout << "Constructeur vide\n"; }
	T( size_t size) : _size( size), _page( new int[ size])
		{ cout << "Constructeur fonctionnel pour size == " << size << '\n' ; }

  private:
  	size_t		_size ;
	int*		_page ;
} ;	// fin de class T


int main( void) {   // ------------------------------------------------------ 80
	T t1 ;

//	T t2( 5) ;
//	t1 = t2 ;
}	// fin de fichier
