// Fichier './Exemples/Const.cpp'
// compiler 'g++ -Wall -Wno-unused-variable Const.cpp'
int main( void) {

    int i ;
    const int N = 100 ;
    const int *p = &N ;        // p peut varier, mais on ne modifiera pas
                               // (*p) en passant par p
    int const *q ; q = &N ;    // definition identique
    const int * const t = &i ; // Ni t ni *t ne peuvent varier: en fait
                               // on peut changer (*t) mais pas avec t:
    i = 12 ;

//  int * const r ;
//  Const.cpp:15: error: uninitialized const 'r'

//  int * const s = &N ;
//  Const.cpp:18: error: invalid conversion from 'const int*' to 'int*'

    return 0 ;
}   // Fin de './Exemples/Const.cpp'
