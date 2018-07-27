// Fichier './Exemples/Vector-Int.cpp'

#include <iostream>
#include <vector>

using std::cout;
using std::left;
const size_t TabSize = 31 ;

int g[ TabSize] ;                     // g en zone statique
std::vector<int> G( TabSize);         // G en zone statique 

int main()
{
    int d[ TabSize];                  // d en zone dynamique
    std::vector<int> D( TabSize);     // D en zone dynamique

    cout << "\nTableaux dans l'esprit du C\nEt du " ;
    cout << "C++ (compatible -std=c++98 et -std=c++11)\n\n";

    for ( size_t i=0; i< TabSize; i++ ) { 
        cout << "Tab C global: g[ " ;
        cout.width(  3) ; cout << left << i << "] : " ;
        cout.width( 11) ; cout << g[ i] ;
        cout << "    Vector C++ global: G[ " ;
        cout.width(  3) ; cout << left << i << "] : " ;
        cout << G.at( i) << '\n';
    } 
    cout << "\n" ;
    for ( size_t i=0; i< TabSize; i++ ) { 
        cout << "Tab C pile  : d[ " ;
        cout.width(  3) ; cout << left << i << "] : " ;
        cout.width( 11) ; cout << d[ i] ;
        cout << "    Vector C++ pile  : D[ " ;
        cout.width(  3) ; cout << left << i << "] : " ;
        cout << D.at( i) << '\n';
    } 
    cout << "\nConclusion: les classes containers du C++ " ;
    cout << "appellent le constructeur vide\nde la classe" ;
    cout << " de l'objet contenu, et implementent un equi" ;
    cout << "vallent pour les\nobjets de base (ceux du C)" ;
    cout << "\n\n" ;
    return 0 ;
}                      // Fin de './Exemples/Vector-Int.cpp'
