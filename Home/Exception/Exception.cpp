#include <iostream>

using std::cout ;
using std::cin ;
using std::endl ;

class erreur {

  public:

	// Seul constructeur necessaire: renseigne la cause
	erreur( int c) : cause( c) {}

	int cause;
} ;

class other {};   // Pour toutes les autres exceptions



int main(void)
{
	cout << endl ;
	cout << "  0 pour generer une exception Erreur" << endl ;
	cout << "  1              une exception int" << endl ;
	cout << "  5 pour un traitement normal" << endl ;
	cout << "  7 pour une violation de memoire" << endl ;
	cout << "  8 pour un defaut d'allocation dans new" << endl ;
	cout << "  9 pour une division par 0" << endl ;
	cout << "    mais pas un autre chiffre, pas de 'quit' (surtout pas!)" << endl; 

	char *p; int i;

	while ( true ) {

		cout << "    Votre choix: " ;
		cin >> i;

		try {
			switch ( i) {
				// les break ne sont pas utiles, le code etant interrompu
				case 0: throw erreur( 66) ;
				case 1: throw 1 ;
				case 5: break ;
				case 7: p = ( char *)0 ; *p= 'a' ; 
				case 8: p = new char[ (unsigned long)(-1) / 2 -1] ;
						if ( ! p ) throw erreur( 55) ;
						cout << "L'allocation a marche tapez un autre '8'" << endl ;
				        continue ; // l'allocation a marche, peut etre 1 fois
				case 9: { int j=4; i /= (j-4) ; }
				default: { other c ; throw( c); }
			}
			cout << "Vous avez choisi 5, sinon ce message ne s'affiche pas\n" ;
		}
	
		catch( erreur &tmp) {
			cout << "Erreur erreur ! (cause " << tmp.cause << ")" << endl;
		}
		catch( int tmp) {
			cout << "Erreur int ! (cause " << tmp << ")" << endl;
		}
		catch( other &tmp) {
			cout << "Autre erreur" << endl;
		}
		catch (...) {
			cout << "Exception inattendue !" << endl;
		}

		cout << "vous pouvez rejouer" << endl ;
	}

	return 0;
}
