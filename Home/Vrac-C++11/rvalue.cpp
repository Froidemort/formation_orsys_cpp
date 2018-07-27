#include <iostream>
#include <string>


int main( void) {

	// les 'r-values' : on les place a droite des affectations...
	std::string&& rval = "Bidule" ;			// nouvelle forme declarative &&
	              rval = "Truc" ;
	std::string   obj( rval) ;
	std::cout << "Ma rvalue : " << rval << std::endl ;
	std::cout << "Mon objet : " << obj  << std::endl << std::endl ;


//	std::string&& x ;	// ne compile pas. Les rvalues sont des references !
//	std::string&& y = rval ;		// meme punition


	std::string&  lval = obj ;
				  lval = "Essai" ;
	std::cout << "Ma rvalue   : " << rval << std::endl ;
	std::cout << "Mon objet   : " << obj  << std::endl ;
	std::cout << "Ma reference: " << lval << std::endl << std::endl ;


	std::string&  lval2 = rval ;
				  lval2 = "Test" ;
	std::cout << "Ma rvalue   : " << rval << std::endl ;
	std::cout << "Mon objet   : " << obj  << std::endl ;
	std::cout << "Ma reference: " << lval << std::endl ;
	std::cout << "Un ocni     : " << lval2<< std::endl ;
}	// Fin de './Home/....rvalue.cpp'
