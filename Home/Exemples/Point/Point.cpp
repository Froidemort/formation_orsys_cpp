// Fichier './Exemples/Point/Point.cpp'
#include <iostream>
#include "Point.h"
using namespace std ;

void Point::Place(
    int x, int y
) {
    Point::x = x ; Point::y = y ;
}

void Point::Bouge(
    int dep_x, int dep_y
) {
    x += dep_x; y += dep_y;
}

void Point::Affiche (
    void
) const {
    cout << "Point x=" << x << ", y=" << y << endl;
}

// Fin de './Exemples/Point/Point.cpp'
