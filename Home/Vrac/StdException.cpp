#include <stdexcept>	// std::invalid_argument
#include <limits>		// std::numeric_limits< char>::max(), std::numeric_limits< char>::min()
#include <iostream>		// std::endl, std::cerr, std::cout

class MyClass {
  public:
	void MyFunc( int X) {
		std::cout << "X==" << X << '\n' ;
		if ( X > std::numeric_limits< char>::max() || X < std::numeric_limits< char>::min() ) {
			throw std::invalid_argument( "L'argument ne peut pas etre transforme en 'char'");
		}
	}
} ;

int main() {
	try {
		char c = -256 ;			// debordement detecte a la compilation par un 'warning'
		char d = (char)-256 ;	// debordement non detecte: il faut bannir les casts !
		MyClass a; a.MyFunc( c); a.MyFunc( d); a.MyFunc( -256) ;
	} catch( std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		return -1 ;
	}
	return 0;
}	// fin de fichier
