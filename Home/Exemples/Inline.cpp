// Fichier './Exemples/Inline.cpp'

class Rien   // Aucune donnee membre : encapsule du code
{ public:
     int Identite(int t) { return t; } // code 'inline' par defaut
     inline int Double(int t) ;
     inline int Triple(int t) ;
     int Quad(int t) ;
     int Cinq(int t) ;
} ; 

int Rien::Double( int t) { return t*2; }
inline int Rien::Cinq( int t)   { return t*5; }

int main( void) {   Rien a ;
   a.Identite( 6) ; a.Double( 6) ; a.Triple( 6) ;
   a.Quad( 6) ; a.Cinq( 6) ; return 0 ;
}

// Sont 'inline' malgre une definition tardive
int Rien::Triple( int t) { return t*3; }
inline int Rien::Quad( int t)   { return t*4; }

// Fin de './Exemples/Inline.cpp'
