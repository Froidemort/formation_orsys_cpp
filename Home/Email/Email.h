// Fichier './Email/Email.h'

// Modele de hierarchie de classes: il faut
// - mettre en place la hierarchie
//          ErreurSaisie-->ErreurEmail-->SaisieAbsente
//          ErreurSaisie-->ErreurEmail-->ChaineTropLongue
//          ErreurSaisie-->ErreurEmail-->ManqueArobase
//          ErreurSaisie-->ErreurEmail-->....

#include <exception>

class ErreurEmail : public std::exception {
  private :
           const char *_message ;
  public :
           ErreurEmail( char const *s) { _message = s ; }
           virtual char const *what( void) { return _message ; }
} ;

void VerifierEmail( char const *) ;

// Fin de './Email/Email.h'
