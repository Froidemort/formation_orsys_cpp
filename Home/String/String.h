// Fichier './String/String.h'

#include <string.h>
#include <iostream>
using namespace std ;

class String {
    char *_val ;
  public :
    String( const char *s = "") throw( bad_alloc) {
        _val = new char[ strlen( s) +1] ;
        if ( !_val ) throw bad_alloc() ;
        strcpy( _val, s) ;
    }
    String( const String &s) throw( bad_alloc) {
        _val = new char[ strlen( s._val) +1] ;
        if ( !_val ) throw bad_alloc() ;
        strcpy( _val, s._val) ;
    }        
    String &operator =( const String &s) throw( bad_alloc) {
        if ( this != &s ) {
           char *tmp = new char[ strlen( s._val) +1] ;
           if ( !tmp ) throw bad_alloc() ;
           strcpy( tmp, s._val) ;
           delete [] _val ;
           _val = tmp ;
        }
        return *this ;
    }
    ~String() { delete [] _val ; }
    friend ostream &operator <<( ostream &c, String &s) ;
} ;

inline ostream &operator <<( ostream &c, String &s) {
    return c << "(string=" << s._val << ")" ;
}

// Fin de './String/String.h'
