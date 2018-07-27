// Debut de './Corriges/String/String.h'

#include <string.h>   // celui du Langage C
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
    String operator =( const String &s) throw( bad_alloc) {
        if ( this != &s ) {
           char *tmp = new char[ strlen( s._val) +1] ;
           if ( !tmp ) throw bad_alloc() ;
           strcpy( tmp, s._val) ;
           delete [] _val ;
           _val = tmp ;
        }
        return *this ;
    }
    String operator +=( const String &s) throw( bad_alloc) {
        if ( this != &s && strlen( s._val) ) {
           char *tmp = new char[ strlen( s._val) + strlen( _val) +1] ;
           if ( !tmp ) throw bad_alloc() ;
           strcpy( tmp, _val) ;
           strcat( tmp, s._val) ;
           delete [] _val ;
           _val = tmp ;
        }
        return *this ;
    }
    String operator -=( int i) throw( bad_alloc) {
        if ( i < 0 ) throw bad_alloc() ;
        if ( i == 0 ) return *this ;
        int j = strlen( _val) - i ;
        if ( j < 0 ) throw bad_alloc() ;
        char *tmp = NULL ;
        tmp = new char[ j+1] ;
        if ( !tmp ) throw bad_alloc() ;
        strncpy( tmp, _val, j) ; tmp[ j] = '\0';
        delete [] _val ;
        _val = tmp ;
        return *this ;
    }
    ~String() { delete [] _val ; }
    friend ostream &operator <<( ostream &c, String &s) ;
} ;

inline ostream &operator <<( ostream &c, String &s) {
    return c << "chaine=>" << s._val << "<" ;
}

// Fin de './Corriges/String/String.h'
