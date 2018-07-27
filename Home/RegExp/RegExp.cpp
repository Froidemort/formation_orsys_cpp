// Debut de ./RegExp/RegExp.cpp
#include <iostream>
#include <regex>
#include <string>

int main()
{
	std::string Ligne ;
	std::regex Entier /* Placez-ici votre RE */
	std::cout << "Sauriez-vous saisir un entier par ligne...\n" ;

	for ( ;; ) {

		std::cout << "> " ;
		std::cin >> Ligne;		// Ou mieux: getline( std::cin, Ligne);
		if ( Ligne == "q" ) return 0 ;  // Ou une autre RE
		if ( regex_match( Ligne, Entier) ) {
			std::cout << "entier detecte >" << Ligne << "<\n" ;
			std::cout << "gagne...\n" ;
		} else {
			std::cout << ">" << Ligne << "< n'est pas un entier\n" ;
			std::cout << "perdu...\n" ;
			return 1 ;
		}
	}
	return 2 ;
}   // fin de fichier
