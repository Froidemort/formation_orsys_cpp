// Debut de './Exemples/Rationnel/Pgcd.h'

#ifndef PGCD_H_INCLUDED
#define PGCD_H_INCLUDED

// Eviter une fonction inline, si elle doit etre recursive
// 'inline' n'est qu'un souhait, et le compilateur peut le suivre
// ou non, mais pour une fonction recursive, cela fait drole...

inline int pgcd( const int a, const int b) {
    return (b==0) ? a : pgcd( b, a%b) ;
}

#endif

// Fin de './Exemples/Rationnel/Pgcd.h'
