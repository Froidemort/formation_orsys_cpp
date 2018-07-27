// Debut de ./Exemples-C++11/Clocks/Clocks.cpp
#include <chrono>
#include <iostream>
#include <iomanip>

template< typename H>   // H pour Horloge; 'typename' ou 'class'
void Caracteristiques( void)
{
    using namespace std;
    cout << "- precision: " ;

//  typedef typename H::period P;     // P est la periode de l'horloge
    typedef typename H::duration::period P; // equivallent a ci dessus

    if ( ratio_less_equal< P, nano>::value ) {
        // Si la periode 'P' de l'horloge est <= nanoseconde: on
        // multiplie cette periode par 1000000000 dans GP
        typedef typename ratio_multiply< P, giga>::type GP;
        cout << double( GP::num)/GP::den << " nano-seconde(s)\n" ;

     } else if ( ratio_less_equal< P, micro>::value ) {
        // Si la periode 'P' de l'horloge est <= microseconde: on
        // multiplie cette periode par 1000000 dans MP
        typedef typename ratio_multiply< P, mega>::type MP;
        cout << double( MP::num)/MP::den << " micro-seconde(s)\n" ;

     } else if ( ratio_less_equal< P, milli>::value ) {

        // Si la periode 'P' de l'horloge est <= milliseconde: on
        // multiplie cette periode par 1000 dans kP
        typedef typename ratio_multiply< P, kilo>::type kP;
        cout << double( kP::num)/kP::den << " milli-seconde(s)\n";

     } else {
        cout << double( P::num)/P::den << " seconde(s)\n";
     }

//    Disponible que pour la system_clock   
//    cout << "- epoch    : " << std::ctime( H::to_time_t( H)) << '\n';

    cout << "- is_steady: " << H::is_steady << '\n';
    cout << "- sizeof   : " << sizeof (H) << '\n';
}



int main()   // ------------------------------------------------------ 73
{
    std::cout << std::boolalpha ;
    // #define ESSAI_LOCALE
    #if defined( ESSAI_LOCALE)
        // Tout n'est peut-etre pas encore traduit...
        std::locale::global( std::locale( "")); perror( 0) ;
        std::cout << (bool)1 << '\n' ;
    #endif

    std::cout << std::setprecision( 3) ; // nb de chiffres apres ','
    // #define ESSAI_PRECISION
    #if defined( ESSAI_PRECISION)
        std::cout << std::fixed ; // Affiche les '0' non significatifs
        std::cout << 3.1415926524 << '\n' ;
        std::cout << 3.0 << '\n' ;
    #endif

    std::cout << "\nsystem_clock: \n" ;
    Caracteristiques< std::chrono::system_clock>() ;

    std::cout << "\nsteady_clock: \n" ;
    Caracteristiques<std::chrono::steady_clock>();

    std::cout << "\nhigh_resolution_clock: \n" ;
    Caracteristiques< std::chrono::high_resolution_clock>();

    std::cout << "\n" ; return 0 ;
}   // fin de fichier
