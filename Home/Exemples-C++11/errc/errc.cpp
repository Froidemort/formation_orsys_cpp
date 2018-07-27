// fichier ./Home/Exemples-C++11/errc/errc.cpp

#include <iostream>      // std::out
#include <system_error>  // std::system_error
#include <thread>        // std::thread

#define SANS_LE_TRY

int main() {  // -------------------------------------------------- 70
#ifdef SANS_LE_TRY
        std::thread T; T.detach(); return 1; // en fait: 128 + SIGABRT
#else
    try {
        std::thread T; T.detach();
    } catch ( const std::system_error& e ) {
        std::cout << "T.detach(): " << e.what() << '\n';
        return 2;                        // Le code retour sera bien 2
    }
    return 0;
#endif
} // fin de fichier
