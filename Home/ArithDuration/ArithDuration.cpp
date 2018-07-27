// Debut de ./Exemples-C++11/ArithDuration/ArithDuration.cpp
#include <chrono>           // std::chrono
#include <iostream>         // std::cout std::endl

typedef std::chrono::duration< int, std::ratio< 60, 3> > TiersDeMinute ;
typedef std::chrono::duration< int, std::ratio< 60, 4> > QuartDeMinute ;

// Ma fonction 'operator<<' d'affichage d'une duree< Valeur, Ratio>
template< class V, class R>
std::ostream& operator<< (
    std::ostream& s,
    const std::chrono::duration< V, R>& d
) {
    s << "(" << d.count() << " X " << R::num << "/" << R::den << ") s" ;
    return s;
}


int main() { // ------------------------------------------------------ 73

    const TiersDeMinute DeuxTiers( 2) ;
    const QuartDeMinute UnQuart( 1) ;

    // On ne sait pas afficher de duree... sans notre template
    std::cout << "Duree de 2/3 de minute : " << DeuxTiers << '\n' ;
    std::cout << "Duree de 1/4 de minute : " << UnQuart << '\n' ;

    // Un peu d'arithmetique
    std::cout << "L'un moins l'autre : " << DeuxTiers-UnQuart << '\n' ;
    std::cout << "L'un plus  l'autre : " << DeuxTiers+UnQuart << '\n' ;
    std::cout << "Quatre quarts      : " << 4*UnQuart << '\n' ;

    // La conversion marche si ...
    // elle n'aboutit pas a une perte "possible" de precision
    std::cout<<"soit aussi " << std::chrono::seconds( 4*UnQuart) << '\n';

    // Ci dessous ne compile pas car aucune conversion n'est disponible
    // entre le std::ratio< 60l> et le std::ratio< 60l, 4l>
//  std::cout<<"Ou encore  " << std::chrono::minutes( 4*UnQuart) << '\n';

    // Mais le developpeur est tetu comme Indiana Jones!
    const std::chrono::seconds QuatreQuarts( 4*UnQuart) ;
//  const std::chrono::minutes UneMinute( QuatreQuarts) ;
    // Ce qui ne rapporte rien: la conversion se fait a la compilation
    std::cout<<"Ou encore  " <<               // ou avec duration_cast<>
        std::chrono::duration_cast< std::chrono::minutes>( 4*UnQuart) ;
    std::cout << std::endl ;

    // Exercice: afficher toutes les donnees ci dessus en 'double'

    return 0 ;
}   // fin de fichier
