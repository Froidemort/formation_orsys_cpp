// Fichier './Exemples/Wstring.h'

#include <string>     // classe 'wstring'
#include <iostream>   // wcout ...

class Essai {
  public :
    Essai( const wchar_t *s) : _essai( s) {}
    const std::wstring &Valeur( void) const { return _essai ; }
  private :
    std::wstring _essai ;
} ;

int main( void) {

    Essai e( L"hum ...") ;
    // Essai e( L"hum ... �") ;
    // Essai e( L"Ich wei� nicht") ;
    // Essai e( L"Ich weiß nicht") ;
    std::wcout << e.Valeur() ;
    return 0 ;
}                        // Fin de './Exemples/Wstring.h'
