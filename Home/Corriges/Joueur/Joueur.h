// Fichier './Corriges/Joueur/Joueur.h'

const int SCORE_GAGNANT = 5000 ;

class Joueur {

    public :
        Joueur( const char *s) {
            score = 0 ;
            nb_coups = 0;
            _Nom = s ;
        }

        bool Gagne( void) const { return score >= SCORE_GAGNANT ; }
        void Affiche( void) const ;
        void Joue( void) ;
        const char *Nom( void) const { return _Nom ; }
        virtual ~Joueur() {}

    private :
        int score ;    
        int nb_coups ;
        const char *_Nom;

        virtual bool Continue( void) = 0 ;
} ;

class JoueurManuel : virtual public Joueur {
    protected :
        bool Continue( void) ;
    public :
        JoueurManuel( const char *s) : Joueur( s) {}
        ~JoueurManuel() {}
} ;

class JoueurAuto : virtual public Joueur {
    protected :
        bool Continue( void) ;
    public :
        JoueurAuto( const char *s) : Joueur( s) {}
        ~JoueurAuto() {}
} ;

class JoueurAvise : public JoueurAuto, public JoueurManuel {
        bool Continue( void) ;
    public :
        JoueurAvise( const char *s) :  // appel les ctors
            // dans l'ordre pour eviter un 'warning'
            Joueur( s), JoueurAuto( s), JoueurManuel( s) {}
        ~JoueurAvise() {}
} ;

// Fin de './Corriges/Joueur/Joueur.h'
