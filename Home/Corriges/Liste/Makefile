# Debut de Makefile - Liste
#
# Denis Gillain - Version 1.2
#
# make -n visualise les regles, sans les executer
# make -r n'applique pas les regles implicites (par defaut)

# Cherche d'abord les include des participants; a defaut prend ceux des corrections
CC   = g++ -Wall -I.. -I../Corriges
CORE = Makefile Liste.h
PRG  = Test-Liste
OBJS = ../Rand/Rand.o


$(PRG): $(PRG).o $(OBJS) $(CORE)
	$(CC) $(PRG).o $(OBJS) -o $(PRG)

# 1- Regle occultee par une regle par defaut si pas de 'Liste.h'
# 2- Il faut mettre '-o' sinon par defaut l'objet arrive dans le repertoire courant
%.o: %.cpp $(CORE)
	$(CC) -c $< -o $*.o

test: $(PRG)
	@./$(PRG)
	@echo "   ... autre essai"
	@./$(PRG)
	@echo

cleanrep:
	@rm -f $(PRG) $(OBJS) $(PRG).o

version:
	@$(CC) --version | head -1

# Fin de Makefile
