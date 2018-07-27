// debut de fichier './Exemples/Rationnel/Part6.h'

  public:
    Rationnel &operator ++() { // ++q
      num+=den; return *this ;
    }
    Rationnel operator ++( int dummy) { // q++
      Rationnel r = *this ;
      num+=den ; return r ;
    }

// Fin de './Exemples/Rationnel/Part6.h'
