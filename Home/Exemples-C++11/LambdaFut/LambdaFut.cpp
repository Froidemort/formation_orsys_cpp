// Debut de Home/Exemples-C++11/LambdaFut/LambdaFut.cpp
// ------------------------------------------------------------------- 73
// A compiler avec -std=c++14

#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // 300ms

int main() {  // ----------------------------------------------------- 73

    // Simple curiosite que l'instruction ci-dessous...
    [] { std::cerr << __PRETTY_FUNCTION__ << '\n' ; }() ;


    #if defined( QQS_NOMBRES_PREMIERS)          // Ma bibliotheque
        long long ll = 3132223137661ll;         // de nombres premiers
        long long ll =  132223137691ll;         // pour faire des
        long long ll =   13222137737ll;         // copier/coller
        long long ll =    1222137781ll;
    #endif

    long long ll = 1222137781ll;
    std::cout << "Checking whether " << ll << " is prime.\n";
    std::future< bool> fut = std::async( std::launch::async,
        [ ll ]( void) ->
        bool {
            // Ci dessous, simple curiosite, quel est le nom de la lambda
            std::cerr << __func__ << ": " ; // et demarre l'algorithme
            for (auto i=2ll; i<ll; ++i) if (ll%i==0) return false;
            return true;
        }
    ) ;


    // get() est bloquante et attend que l'etat du future soit connu
    // Du coup on teste l'etat du future avant le get()
    std::cout << "Calculating. Please, wait\n";
    using namespace std::chrono_literals;        // pour 300ms ci dessous
    while ( fut.wait_for( 300ms) == std::future_status::timeout ) {
        std::cerr << '.' ;
    }
    std::cerr << '\n' ;
    bool ret = fut.get();


    if ( ret ) std::cout << "It is prime!\n";
    else std::cout << "It is not prime.\n";

    return 0;
}   // fin de fichier
