// Debut de ./Exemples-C++11/typename/typename.cpp

struct A { struct X {} x; };

/*
   ne compile pas sans 'typename', avec l'erreur (clang) ci apres:
   error: missing 'typename' prior to dependent type name 'T::X'
   ----
   En effet dans un template la mention du type 'T' ne permet pas de
   mentionner des types. Dans l'exemple T::X ne peut mentionner que
   le nom d'un champ, pas celui d'un type.
   ----
   Sauf a utiliser le mot clef 'typename' :o)
 */
template< class T> void f( T t) { // ------------------------------ 70

               T::X {} ;
//    typename T::X {} ;

}  // fin du template< T>



int main() { // --------------------------------------------------- 70
    A a; f( a);
}    // fin de fichier
