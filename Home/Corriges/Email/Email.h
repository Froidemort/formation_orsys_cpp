// Fichier './Corriges/Email/Email.h'

#include <exception>

// ---------------------------------------------------------------------
class ErreurSaisie : public std::exception {  // Classe la plus generale
  protected :
           const char *_message ;
  public :
           ErreurSaisie( void) { _message = "Erreur lors de la saisie" ; }
           ErreurSaisie( char const *s) { _message = s ; }
           virtual char const *what( void) { return _message ; }
} ;


// -----------------------------------------------------------------------------------------
class ErreurEmail : public ErreurSaisie {     // Erreur intermediaire: saisie incorrecte
  public :
           ErreurEmail( void) : ErreurSaisie( "Erreur dans la saisie d'une adresse email") {}
           ErreurEmail( char const *s) { _message = s ; }
} ;


// ---------------------------------------------------------------------------------------
class ChaineVide : public ErreurEmail {
  public : ChaineVide( void) : ErreurEmail( "L'adresse email n'est pas renseignee") {}
} ;

class NomAbsent : public ErreurEmail {
  public : NomAbsent( void) : ErreurEmail( "L'adresse doit commencer par un destinataire") {}
} ;


void VerifierEmail( char const *) throw( ErreurEmail &) ;

// Fin de fichier './Corriges/Email/Email.h'
