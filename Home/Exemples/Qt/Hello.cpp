// Fichier './Exemples/Qt/Hello.cpp'

// - Attention aux versions: taper 'which qmake' avant toute chose

// Installer au prealable le sdk Qt4
// - debian : apt-get install qt-sdk
// - centos : yum install qt4-devel (verifier avant: il y est peut etre)

// Pour compiler un programme Qt4 comme cet exemple (qui ne marche pas en Qt3)
// -      '/usr/lib/qt4/bin/qmake -project' analyse le repertoire et fabrique 'Qt.pro'
// - puis '/usr/lib/qt4/bin/qmake' fabrique le 'Makefile'
// - et enfin 'make'


#include <QtGui/QApplication>
#include <QtGui/QPushButton>
 
int main( int argc, char *argv[])
{
    QApplication app( argc, argv) ;
    QPushButton hello( "Hello world!") ;
    hello.show() ;
    return app.exec() ;
}

// Fin de './Exemples/Qt/Hello.cpp'
