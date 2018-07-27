// Fichier './Corriges/Liste/Liste.h'

#ifndef LISTE_H_FILE
#define LISTE_H_FILE

// Dans ce fichier il n'y a aucune mention de l'objet a mettre en liste
// et dans le fichier decrivant l'objet il n'est pas fait mention
// de la liste. Mais par heritage multiple, on obtient une liste d'objets

class Element {

    public:
        Element( void) { _suivant = (Element *)0 ; }
        Element *suivant( void) const { return _suivant ; }

//      Ajoute 'e' immediatement derriere le courant
        void ajoute( Element *e) {
            if ( e != (Element *)0 ) {
                e->_suivant = _suivant ;
                _suivant = e ;
            }
        }

    private:
        Element *_suivant ;
} ;

#endif                         // Fin de './Corriges/Liste/Liste.h'
