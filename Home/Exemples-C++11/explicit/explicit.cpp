// debut de ./Exemples-C++11/explicit/explicit.cpp
#pragma GCC diagnostic ignored "-Wunused-variable"     // GCC et clang
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" // GCC seul

#define explicit  // Mettre en commentaire pour compiler avec explicit

struct T {
    explicit T( int) {}      // Constructeur de conversion     - C++
    explicit T( int, int) {} // Constructeur de conversion     - C++11
    explicit operator bool() const { return true; } // (bool)T - C++11
} ;

// ---------------------------------------------------------------- 70
int main() {

    T a( 1);                                 // -1-
    T b = 2;                                 // -2-
    T c{ 3, 4};                              // -3-
    T d = { 5, 6};                           // -4-
    T e = (T)7;                              // -5-
    T f = static_cast< T>( 8) ;              // -6-
    if (a) return 0 ;                        // -7-
    bool x = a;                              // -8-
    bool y = static_cast< bool>( a);         // -9-

}   // fin de fichier
