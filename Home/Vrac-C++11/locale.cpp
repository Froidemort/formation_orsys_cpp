#include <iostream>
#include <locale>
 
int main()  // --------------------------------------------------------------- 81
{
	std::locale loc( "") ;
	std::cout << "Votre symbole monetaire: "
			  << std::use_facet< std::moneypunct< char, true>>(loc).curr_symbol()
			  << std::endl ;

}	// Fin de locale.cpp
