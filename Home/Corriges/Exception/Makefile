# Fichier './Exception/Makefile'
# Fichier './Corriges/Exception/Makefile'  (lien physique)

PRG=Exception

all: $(PRG)

$(PRG): $(PRG).cpp Makefile
	g++ -Wall -fexceptions $(PRG).cpp -o $(PRG)
#	g++ -Wall -fno-exceptions $(PRG).cpp -o $(PRG)

test:
	@./$(PRG)

cleanrep:
	@rm -f *.o $(PRG)

# Fin de './Exception/Makefile'
