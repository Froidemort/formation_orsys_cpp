// Fichier './Exemples/Erreur.h'

//    Nomenclature des erreurs  ------------------------------
const unsigned int ErrInconnue = 0 ;
//    ................
const unsigned int ErrSalaireNegatif = 101 ;
//    ................


class Erreur: public std::exception  // ----------------------
{
  public:

    Erreur(
       int num = ErrInconnue,
       const char *mesg = "inconnu",
       int magic = 78172931
    ) throw() : _numero( num), _mesg( mesg), _magic( magic) {}


    virtual const char *what( void) const throw() { return _mesg ; }


    int getNum( void) const throw() { return _numero ; }
   

    int getMagic( void) const throw() { return _magic ; }
   

    virtual ~Erreur() throw() {}


  private: // ---------------------------------

    int _numero ;        // Numero de l'erreur.
    const char *_mesg ;  // Complement de l'erreur.
    int _magic  ;        // Provenance de l'erreur.
} ;

// Fin de './Exemples/Erreur.h'
