// Fichier './Exemples/Paire.cpp'

#include <iostream>
#include <string>
#include <set>

using namespace std ;

typedef pair< string, int> MembreFamille ;

int main( void)
{
    pair< string, int> d = make_pair( "Denis", 52);
    cout << d.first << ' ' << d.second << endl;

    pair< string, int> m( "Mathieu", 19);
    MembreFamille t( "Tania", 16) ;
    MembreFamille c = MembreFamille( "Charlie", 3) ;

    // 'set' : ensemble trie de valeurs uniques
    set< MembreFamille> Gillain ;
    Gillain.insert( d); Gillain.insert( t) ;
    Gillain.insert( c); Gillain.insert( m) ;

    set< MembreFamille>::iterator it;
    cout << "Ma famille:" ;
    for ( it=Gillain.begin() ; it != Gillain.end(); it++ )
          cout << ' ' << it->first ;
    cout << endl;

    return 0;
}

// Fin de './Exemples/Paire.cpp'
