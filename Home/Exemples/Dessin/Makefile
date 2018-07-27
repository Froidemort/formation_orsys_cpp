# Fichier './Exemples/Dessin/Makefile'
# Makefile de 'Dessin'

PROJET	=	Dessin
CC		=	g++ -Wall
CORE	=	Makefile Dessin.h Image.h ../Cercle/Cercle.h ../Cercle/Point.h
OBJETS	=	../Cercle/Cercle.o ../Cercle/Point.o Test.o Image.o

$(PROJET) : $(OBJETS) $(CORE)
	$(CC) -o $(PROJET) $(OBJETS)

%.o : %.cpp $(CORE)
	$(CC) -c $*.cpp -o $*.o

clean : 
	@rm -f $(OBJETS) $(PROJET)

# Fin de './Exemples/Dessin/Makefile'
