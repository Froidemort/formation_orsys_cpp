// Fichier './Exemples/Vector.cpp'

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>

using std::cout;

int main()
{
    std::vector<int> v;
    v.push_back( 10 );
    cout << "premier element de v: " << v.front() << '\n';
    cout << "dernier element de v: " << v.back()  << '\n';
    v.pop_back();
    if ( v.empty() ) {
        cout << "Le tableau v est vide\n" ;
    }

    v.resize( 22 );
    cout << "Nouvelle taille: " << v.size() << '\n';
    
    std::fill( v.begin(), v.end(), 113 );
    v[ 12] = 35;
    cout << "v[ 11] == " << v.at( 11) << '\n';
    cout << "v[ 12] == " << v.at( 12) << '\n';
    
    v.clear();
    v.reserve( 50 ); // Pre-Allocation pour gagner en performances
    cout << "Taille apres vidage: " << v.size() << '\n';

    // capacite du tableau = nombre d'elements qu'il peut stocker
    // sans devoir reallouer (modifie grace a reserve())
    cout << "Capacite: " << v.capacity() << '\n';

    for ( int i = 0; i < 50; ++i ) {
        v.push_back( i );
    }

    cout << "Nouvelle taille: " << v.size() << '\n';
    cout << "v[ 44] == " << v.at( 44) << '\n';
    cout << "v[ max] == " << *std::max_element( v.begin(), v.end() ) << '\n';

    v.resize( 5);
    cout << "Nouvelle taille: " << v.size() << '\n';
    std::sort( v.begin(), v.end() );

    for ( size_t i = 0, size = v.size(); i < size; ++i ) {
        cout << v[ i ] << '\t';  // operateur [] : on peut deborder    
    }   cout << '\n';

    
    try { // utilisation de at() : les acces sont verifies
        v.at( v.size() ) = 10; // acces en dehors des limites !
    } catch ( const std::out_of_range & ) {
        cout << "at() a leve l'exception std::out_of_range\n";
    }

    // parcours avec un iterateur en inverse
    for ( std::vector<int>::reverse_iterator i = v.rbegin();
          i != v.rend();
            ++i ) {
        cout << *i << '\t';
    }   cout << '\n';

    std::vector<int> w( 10, 20 ); // 10 elements initialises a 20
    cout << "Somme w[*]: " << std::accumulate( w.begin(), w.end(), 0 ) << '\n';

    v = w;
    if ( std::equal( v.begin(), v.end(), w.begin() ) ) {
        cout << "v est bien une copie conforme de w\n";
    }
}

// Fin de './Exemples/Vector.cpp'
