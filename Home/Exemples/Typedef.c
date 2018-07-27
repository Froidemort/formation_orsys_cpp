// Fichier './Exemples/Typedef.c'
struct Point {
    int x, y;
} ;                   // Tout compile en C++

struct Point p1 ; 
Point p2 ;            // Erreur en C

typedef int Entier ; 
typedef char Ligne[ 255];   // Compile en C

typedef struct Person {
    char nom[ 20]; int age ;
} Person ;

struct Persona {
    char nom[ 20]; int age ;
} ;

int main ( void) {
    Ligne s = "essai" ;
    Persona Toto ;   // Erreur en C
    return 0 ;
}   // Fin de './Exemples/Typedef.c'
