// Fichier './Exemples/Segment.cpp'

class Point {
    int x, y ;
  public:
    Point( int a, int b) { x=a; y=b; }
    void Bouge( int a, int b) { x+=a; y+=b; }
    int Abscisse( void) const { return x ; }
    int Ordonnee( void) const { return y ; }
} ;

class Segment {
    Point Debut, Fin ;
  public:
    Segment( int x1, int y1, int x2, int y2) :
        Debut( x1, y1), Fin( x2, y2) {}
} ;

int main( void) { Segment s( 2, 2, 3, 3); return 0;}
// Fin de './Exemples/Segment.cpp'
