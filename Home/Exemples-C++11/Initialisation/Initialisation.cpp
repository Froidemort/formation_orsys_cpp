#include <iostream>
#include <vector>
#include <map>
using std::cout ;

int z{ 666} ;  // Initialisation uniforme OK sur les variables statiques

class C {    // ------------------------------------------------------ 73
    private: int _a=0, _b=1 ;  // Initialisation directe de membres c++11
    public: C( void) { cout << "Appel au constructeur vide\n" ; }
  #ifdef C_PLUS_PLUS_MARCHE_TOUJOURS
    public: C( int a, int b) : _a( a), _b( b) { // Liste d'initialisation
        cout << "Appel au ctor a 2 entiers\n" ;
    }
  #else
    public: C( int a, int b) : _a{ a}, _b{ b} {  //   id. mais uniforme
        cout << "Appel au ctor a 2 entiers et initialisation uniforme\n";
    }
  #endif
} ;


int main( void) {  // ------------------------------------------------ 73

    C c() ;      // ctor vide? ou appel de fonction? ?? ??? (pas de warning)
    C d ;        // ctor vide ici, c'est sur
    C e=C() ;    // ctor vide ici, sur egalement
                    cout << std::endl ;
    int i ;         cout << "i==>" <<i<< "< (i n'est pas initialise)\n" ;
    int j=5 ;       cout << "j==>" <<j<< "< (affectation valeur initiale)\n" ;
    int k=int() ;   cout << "k==>" <<k<< "< (appel de ctor par defaut)\n" ;
    int l() ;       cout << "l==>" <<l<< "< (ctor vide? appel de fonction?)\n" ;
    int m=int(6) ;  cout << "m==>" <<m<< "< (ctor fonctionnel)\n" ;
    int n(7) ;      cout << "n==>" <<n<< "< (ctor fonctionnel)\n" ;
    int o{8} ;      cout << "o==>" <<o<< "< (initialisation uniforme)\n\n" ;
                    cout << "z==>" <<z<< "< (var. globale; init. uniforme)\n\n";

    int tab[ 10] { 4, 5} ;      // Initialisation uniforme depuis c++11
//  int tab[ 10] = { 1, 3 } ;   // L'initialisation vieux style marche toujours
    cout << "tab[ 1]==>" << tab[ 1] << "<\n" ;
    cout << "tab[ 2]==>" << tab[ 2] << "< (non initialise)\n\n" ;

    // L'initialisation uniforme permet d'initialiser les retours de new
    int* p = new int[ 5] { 100, 101 } ;
    cout << "*(p+1)==>" << *(p+1) << "<\n" ;
    cout << "*(p+2)==>" << *(p+2) << "< (non initialise)\n\n" ;
    delete[] p ; p=nullptr;                   // Pas de ramasse-miettes en c++11

    int* q { new int[ 5] { 5, 4, 3, 2, 1 } } ;// Identique a ce dessus    
    for ( size_t i=0; i<5; i++ ) {
        cout << "*(q+" << i << ")==>" << *(q+i) << "<\n" ;
    }    cout << std::endl ;
    delete[] q ; q=nullptr;

    C F( 2, 5) ;                // Appel explicite au constructeur fonctionnel
    C f{ 7, 8 } ;               // Initialisation uniforme
    C g = { 4, 7 } ;            // Initialisation traditionnelle

    // L'initialisation (y compris uniforme) est ajoutee pour les conteneurs
    std::vector< std::string> vs { "uno", "dos", "tres"} ;
    std::map< std::string, std::string> sites {
        { "Denis", "http://www.matania.com"},
        { "ELLIPSYS", "http://www.ellipsys.fr"}
    } ;
}   // fin de fichier
