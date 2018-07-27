#ifdef SCRIPT

	# Ce fichier doit etre executable et execute par ./essai.c
	# --------------------------------------------------------
	# 3 techniques pour creer un tableau. Le but est de regarder la plus legere apres compilation

	# Ce fichier: ~jack/Langage C/Home/vla/essai.c
	# lien phy. : ~jack/C++/Home/Vrac/essai.c (doit etre .c var compile le .c et pas le .cpp ci dessous)

	gcc -Wall -Wno-unused-variable -DDEFINE -c -o define.o essai.c
	gcc -Wall -Wno-unused-variable -DCONST  -c -o const.o  essai.c
	gcc -Wall -Wno-unused-variable -DENUM   -c -o enum.o   essai.c
	strip *.o
	ls -l const.o define.o enum.o
	rm const.o define.o enum.o
	exit 0

#endif

// Ci dessous debut du source en Langage C

#if defined( DEFINE)
	#define	TAB 512
#elif defined( CONST)
	const int TAB = 512 ;
#elif defined( ENUM)
	enum { TAB = 512 } ;
#else
	#error "Il faut compiler avec une option -DCONST, -DENUM, -DDEFINE et regarder la taille de l'objet fabrique"
#endif

int main( void) {

	char tab[ TAB] ;
	return 0 ;
}
