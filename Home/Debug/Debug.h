// fichier ./Home/Debug/Debug.h
// lien    ./Home/Corriges-C++11/Debug/Debug.h
#ifndef DEBUG_H_FILE
#define DEBUG_H_FILE

// Declaration des 2 fonctions definies dans Debug.cpp
void SetDebug( void) noexcept ;
bool Debug( char const* Id=nullptr, char const* Format=nullptr, ...) noexcept ;



///        \brief    Debug( bool) permet d'activer le mode Debug
///        \date    22 aprile 2016
///        \return    true si le mode Debug est active, false sinon
///
/// La fonction 'inline' est un wrapper appelant SetDebug(). Il permet de positionner le mode Debug
/// Actuellement rien n'est ecrit pour desactiver le mode Debug, et ce n'est pas necessaire
///
inline bool Debug(            ///< renvoie l'etat du mode Debug : true ou false
    bool etat,                ///< true pour activer le mode Debug. false ne fait rien mais retourne l'etat actuel du Debug
    char const* Id=nullptr    ///< Identifiant permettant d'indentifier l'appelant de Debug()
) noexcept {
    if ( etat ) {
        if ( Debug() ) {
            Debug( Id, "Fonction de Debug() etait deja active: on ne change rien") ;
        } else {
            SetDebug() ; Debug( Id, "Fonction de Debug() activee") ;
        }
    } else if ( Debug() ) {                 // Sans rien retoune l'etat du Debug
        Debug( Id, "Une fois active le Debug ne peut pas etre desactive") ;
    } else ;
    return Debug() ;
}   // Fin de Debug( bool)

#endif // fin de fichier
