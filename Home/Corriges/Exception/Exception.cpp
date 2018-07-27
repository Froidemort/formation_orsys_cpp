// Fichier './Corriges/Exception/Exception.cpp'

// Cette solution n'est pas satisfaisante: pourquoi ne donne-t-elle
// pas le meme comportement si on fait 2 fois le choix 7 ? et que
// se passe-t-il exactement avec le ^C ?

#include <iostream>
#include <exception>
#include <signal.h>


using std::cout ;
using std::cin ;
using std::endl ;

class erreur : public std::exception {

  public:

    // Seul constructeur necessaire: renseigne la cause
    erreur( int c) : cause( c) {}

    // Necessite est faite d'instancier la methode what()
    const char *what( void) const throw() { return "Malaise"; }

    int cause;
} ;



void MonTraitement(  // ----------------------------------------------
    int n_sig
) {
   cout << "Reception du signal " << n_sig << endl ;
   cout << "          on leve l'exception..." << endl ;
   throw erreur( -n_sig) ;
}



int main(void)  // ---------------------------------------------------
{
    cout << endl ;
    cout << "  0 pour generer une exception Erreur" << endl ;
    cout << "  1              une exception int" << endl ;
    cout << "  5 pour un traitement normal" << endl ;
    cout << "  7 pour une violation de memoire" << endl ;
    cout << "  8 pour un defaut d'allocation dans new" << endl ;
    cout << "  9 pour une division par 0" << endl ;
    cout << "    mais pas un autre chiffre, pas de 'quit' (surtout pas!)\n"; 

    char *p; int i;

    cout << "on arme toutes les interruptions" << endl ;
    for ( i=1; i<64; i++ ) signal( i, MonTraitement) ;

//  while ( true ) ;   // Pour tester les interruptions :o(
    while ( true ) {

            // je demande a l'utilisateur (il m'ennerve !) son choix
            cout << "\n    Votre choix: " ;
            cin >> i;

        try {
            switch ( i) {
                // les break ne sont pas utiles, le code etant interrompu
                case 1: throw( 1);
                case 5: break ;
                case 7: p = ( char *)0 ; *p= 'a' ; 
                case 8: p = new char[ (unsigned long)(-1) / 2 -1] ;
                  cout << "L'allocation a marche tapez un autre '8'" <<endl;
                  continue ; // l'allocation a marche, peut etre 1 fois
                case 9: { int j=4; i /= (j-4) ; }
                default: throw erreur( i) ;
            }
            cout << "Vous avez choisi 5 sinon ce message ne s'affiche pas\n";
        }
    
        catch( erreur &tmp) {
            cout << "Erreur 'erreur' ! (cause " << tmp.cause << ")" << endl;
        }
        catch( const std::bad_alloc &e) {
            cout << "Allocation memoire en echec !" << endl ;
        }
        catch( int tmp) {
            cout << "Erreur 'int' ! (cause " << tmp << ")" << endl;
        }
        catch (...) {
            cout << "Exception inattendue !" << endl;
        }

        cout << "vous pouvez rejouer" << endl ;
    }

    return 0;
}   // Fin de './Corriges/Exception/Exception.cpp'
