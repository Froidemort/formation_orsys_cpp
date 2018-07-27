// Debut de ./Home/Exemples-C++11/random/random.cpp
#include <iostream>
#include <random>

int main() // ----------------------------------------------------- 70
{
    std::random_device alea ;   // Fournit un alea meilleur que time()
    std::mt19937 eng( alea());  // Arme un generateur avec l'alea

  // 1ere serie : des des retournes
    std::uniform_int_distribution< int8_t> jet( 1, 6) ;    // 6 inclus
    for ( int i=0; i<40; ++i) {
        // int8_t d = jet( alea());              // --> ne compile pas
        int8_t d = jet( eng);
        std::cout << (int32_t)d << ' ' ;
    }   std::cout << '\n' ;

  // 2ieme serie : une distribution de floats entre 0 et 1
    std::uniform_real_distribution< float> a( 0.0, 1.0); // 1.0 exclus
    for ( int i = 0; i < 10; ++i) {
        std::cout << a( eng) << '\n' ;
    }
    return 0;
}   // fin de fichier
