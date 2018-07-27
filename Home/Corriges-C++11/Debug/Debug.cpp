// Debut de ./Home/Corriges-C++11/Debug/Debug.cpp'
#include "Debug.h"    // Debug() 
#include <stdarg.h>   // va_args()
#include <stdio.h>    // fprintf() vfprintf() setbuf() stderr stdout
#include <mutex>      // std::mutex   // Ajout SYNCHRO ------------ 70

static bool _DebugEstActif = false ;  // Avant d'en faire une classe !



// ---------------------------------------------------------------- 70
///        \brief    Fonction activant le mode Debug
///        \date    22 aprile 2016
///
/// La fonction assure la logistique activant le mode Debug.
/// Il est preferable d'utiliser Debug( true, Identifiant) ; qui logue
/// un message dans le Debug.
///
void SetDebug( void) noexcept {
    _DebugEstActif = true ;
    setbuf( stderr, nullptr) ; setbuf( stdout, nullptr) ;
}    // fin de SetDebug()



// ---------------------------------------------------------------- 70
///        \brief    Debug( ...) permet de loguer un message de Debug
///        \date    22 aprile 2016
///        \return    true si le mode Debug est active, false sinon
///
/// S'utilise comme printf() pour loguer un message en stderr. Par
/// exemple: l'appel 'Debug( "main()", "3x3=%d", 3*3) ;' fournit
/// '(debug) main(): 3x3=9'
/// 
///    \warning: passer les arguments a vfprintf() ne permet pas
///              l'activation de la verificationde la pile par g++
///
bool Debug(
    char const* Id,   ///< Identifiant de l'appelant de la fonction
    char const* fmt,  ///< Format avec la suite, transmis a fprintf()
    ...                    
) noexcept {

    if ( ! _DebugEstActif ) return false ;
    if ( ! fmt ) return true; // (fmt==nullptr) return etat du Debug()

    static std::mutex m ;       // Ajout SYNCHRO ------------------ 70
    m.lock() ;                  // Ajout SYNCHRO ------------------ 70
    va_list ap;

    va_start( ap, fmt);

    if ( fmt ) {
        while ( *fmt == '\n' ) { fprintf( stderr, "\n") ; fmt ++ ; }

        if ( *fmt ) {    // L'id est sur 3 caracteres en general
             fprintf( stderr, "(debug) %s : ", Id ? Id : " ? " ) ;
            vfprintf( stderr, fmt, ap);
        }
    }
    fprintf( stderr, "\n") ;
    va_end( ap);
    m.unlock() ;                // Ajout SYNCHRO ------------------ 70

    return true ;
}    // fin de Debug()
// fin de ./Home/Debug/Debug.cpp
