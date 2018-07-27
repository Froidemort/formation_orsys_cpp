# Fichier './Exemples/Cercle/Makefile'

CORE	=	Makefile Cercle.h Point.h
CC		=	g++ -Wall
OBJETS	=	Cercle.o Test.o Point.o

Cercle : $(OBJETS) $(CORE)
	$(CC) -o Cercle $(OBJETS)

%.o : %.cpp $(CORE)
	$(CC) -c $*.cpp -o $*.o

clean : 
	@rm -f *.o *.tar Cercle

# Fin de './Exemples/Cercle/Makefile'
