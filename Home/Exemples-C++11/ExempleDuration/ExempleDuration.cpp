// Debut de ./Exemples-C++11/ExempleDuration/ExempleDuration.cpp
#include <chrono>
#include <iostream>
int main() { // --------------------------------------------------- 70

    const std::chrono::seconds      VingtSecondes( 20); // 20 periodes
    const std::chrono::milliseconds UneMilliSeconde( 1);//  1 periode
    const std::chrono::hours        UnJour( 24);        // 24 periodes

    std::chrono::duration< int>     QqSecondes ;
    std::cout << QqSecondes.count() << " s (non initialise)\n" ;

    QqSecondes = std::chrono::seconds( 17) ;
    std::cout << QqSecondes.count() << " s (doit etre 17)\n" ;
    QqSecondes++; // Ajoute 1 periode definie a la creation de l'objet
    std::cout << QqSecondes.count() << " s (doit etre 18)\n" ;

    std::chrono::duration< int, std::milli> QqMilliSecondes(
               std::chrono::duration< int, std::ratio< 1, 1000> >( 77)
            );
    std::cout << QqMilliSecondes.count() << " ms (doit etre 77)\n" ;
    QqMilliSecondes++ ;
    std::cout << QqMilliSecondes.count() << " ms (doit etre 78)\n" ;

    const std::chrono::seconds      JourEnSecondes( UnJour) ;
    std::cout << JourEnSecondes.count() << " s (doit etre " ;
    std::cout << 24*60*60 << ": les conversions sont assurees)\n" ;
}   // fin de fichier
