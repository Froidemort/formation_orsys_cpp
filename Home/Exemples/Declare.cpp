// Fichier './Exemples/Declare.cpp'
// compiler 'g++ -Wall -Wno-unused-variable Declare.cpp'
//

char MSG[]  = "rien" ;

class Rien {
} ;

int main() {

    char *a ;
    unsigned char **aa ;
    char * const b = MSG  ; // Initialisation obligatoire b est const
    char const *c = MSG ; c++ ; // (*c)++ interdit car (*c) est const
    const char *d ;             // syntaxe identique a ci dessus
    const char * const e = MSG ; // Initialisation obligatoire

    int *i[ 20] ;
    int (*j)[ 20] ;              // ???
    void (*k)( void) ;
    void (Rien::*f)( void) ;     // ???

}   // Fin de fichier './Exemples/Declare.cpp'
