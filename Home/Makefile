#!/usr/bin/make -rf

# Fichier Makefile de '~jack/C++/Home/Makefile'
# Lien physique vers  '~jack/Pro C/Home/Makefile'

#
# Denis Gillain		-		E   L   L   I   P   S   Y   S
# http://www.ellipsys.fr
#
  VERSION			= "2.0.14	-	01 dicembre 2016"
# INITIAL_VERSION	= "1.0.0	-	11 luglio 2009"
#
# Fichier 'Makefile' d'un repertoire Home des supports de cours
#     - premiere version pour C++
#     - seconde version pour Pro*C
#
# Ce fichier est ecrit en ISO-8859-1, mais tous les messages ecrits
# a l'ecran doivent etre en ASCII




SHELL		:=	/bin/bash
XSLTPROC	:=	xsltproc --nonet --xinclude
DATE_ABR	:=	$(shell LANG=C date +'%d-%b-%Y')
TAR_DIR		:=	/tmp



# ------------------------------------------------------------------------------------ 89
# Page d'aide, qui est aussi l'option par defaut
help:
	@echo 
	@echo "make [ help ]  : cette page d'aide"
	@echo "make version   : numero de version du 'Makefile'"
	@echo "make versions  : versions des differents outils"
	@echo "make clean     : nettoie et verifie le repertoire"
	@echo "make comp.sh   : cree la fonction 'comp' facilitant les compilations"
	@echo 
	@echo "Pour sauvegarder, il faut faire 'm tar' ou utiliser e2l-proj"
	@echo 



# ------------------------------------------------------------------------------------ 89
# Versions des differents outils
version: 
	@echo "------------------------------------------------------------"
	@echo $(MAKEFILE_LIST)": $(VERSION)"

versions: info
info: version
	@echo "	LANG        	= '$(LANG)' - (LC_ALL==>$(LC_ALL)<)"
	@echo "	LD_LIBRARY_PATH = '$(LD_LIBRARY_PATH)' (Cf. man 8 ld.so)"
	@echo "------------------------------------------------------------"
	@echo "make: '$(MAKE)' `$(MAKE) --version | head -1`"
	@echo "      '$(MAKE)' $(MAKE_VERSION)"
	@echo "------------------------------------------------------------"
	@echo "shell: `$$SHELL --version | head -1`"
	@echo "------------------------------------------------------------"
	@echo "xsltproc: `$(XSLTPROC) --version|head -1`"
	@echo "          (depuis le package 'xsltproc')"
	@echo "------------------------------------------------------------"
	@echo "`xmllint 2>&1 --version|head -1`"
	@echo "         (depuis le package 'libxml2.utils')"
	@echo "------------------------------------------------------------"
	@echo "tar: `tar --version|head -1`"
	@echo "------------------------------------------------------------"
	@echo "ldd: `ldd --version|head -1`"
	@echo "------------------------------------------------------------"
	@echo





# ------------------------------------------------------------------------------------ 89
# Nettoyage, et standardisation du repertoire
# FAIRE: tout comme on verifie les tabulations, il faut verifier qu'aucune ligne se termine
#        par des espaces (certaines depassent les 73 caracteres!)
cleanrep: 
	@echo >&2 "Fonctionnalite non disponible: tapez 'make clean'"
verif: clean
clean:
	@#.................................................
	@# Les repertoires sont en 755 ou 2755. Les fichiers en 644 s'ils ont une extension
	@find . -type d -exec chmod 755 {} \;
	@find . -type f ! -name '*.*' -exec chmod 755 {} \;	# BUG FAIRE: rend tous les fichiers sans extension executables AAAZ
	@find . -type f \( -name '*.*' -o -name Makefile \) ! -name 'a.out' -exec chmod 644 {} \;
	@find . -type f    -name Makefile                     -exec chmod 755 {} \;
	@#.................................................
	@# Tous les fichiers de '.' autres que 'Makefile' 'LICENCE.txt' 'README' 'profile' et '*.tar.gz' sont supprimes
	@IFS=$$'\n'; for X in `ls`; do if [[ -f "$$X" ]]; then case "$$X" in \
		'LICENCE.txt') chmod 644 "$$X" ;;	\
		'README') chmod 644 "$$X" ;;		\
		'profile') chmod 644 "$$X" ;;		\
		*.tar.gz) chmod 644 "$$X" ;;		\
		*.tar) chmod 644 "$$X" ;;			\
		'Makefile')	chmod 755 "$$X" ;;		\
		'CreeUsers.sql') chmod 644 "$$X" ;;	\
		'CreeUsers.sh') chmod 644 "$$X" ;;	\
		*) rm -f "$$X" ;;					\
		esac; fi; done
	@#.................................................
	@# Les fichiers caches sont supprimes
	@rm -rf .[!.]* || exit 0 
	@#.................................................
	@# 'README' doit etre en ASCII, LICENCE.txt et Makefile en ISO-8859
	@if ! file README | grep -iq ASCII ; then \
		echo >&2 "Le fichier 'README' n'est pas en ASCII" && exit 0; fi
	@if ! file LICENCE.txt | grep -iq 'iso.*8859'; then \
		echo >&2 "Le fichier 'LICENCE.txt' n'est pas en ISO-8859" && exit 0; fi
	@if ! file Makefile | grep -iq 'iso.*8859'; then \
		echo >&2 "Le fichier 'Makefile' n'est pas en ISO-8859" && exit 0; fi
	@#.................................................
	@# Les repertoires 'Vrac*' 'Exemples*' et 'Corriges' ne doivent contenir ni executable ni objet
	@# Il ne faut pas detruire les 'Makefile' par contre !
	@find ./Exemples ./Exemples-C++11 ./Vrac ./Vrac-C++11 ./Corriges ./Corriges-C++11 \
					-type f \( -perm -100 -o -name '*.o' \) \
					! -name Makefile -ok rm -f {} \; 	# AAAZ
	@#.................................................
	@# Les fichiers de './Exemples' et './Exemples-C++11' ne doivent contenir aucune tabulation
	@IFS=$$'\n'; for  X in `find ./Exemples ./Exemples-C++11 -type f ! -name Makefile`; do if fgrep -q '	' "$$X" ; then \
		echo >&2 "'$$X' contient des tabulations"; fi; done
	@#.................................................
	@# './Corriges' ne doit pas contenir de fichiers, mais seulement des repertoires
	@cd ./Corriges && (rm -f * 2>/dev/null || exit 0)
	@#.................................................
	@# './Corriges-C++11' egalement
	@cd ./Corriges-C++11 && (rm -f * 2>/dev/null || exit 0)
	@#.................................................
	@# Lance tous les nettoyages qui doivent exister dans './Corriges'
	@IFS=$$'\n'; for  X in `ls -d ./Corriges/*`; do cd "$$X"; make --no-print-directory cleanrep; cd ../..; done
	@#.................................................
	@# Les fichiers de './Corriges/ss-reps' aussi ne doivent contenir aucune tabulation
	@IFS=$$'\n'; for  X in `ls ./Corriges/*/*`; do if fgrep -q '	' "$$X" ; then \
		if [[ "$${X##*/}" != 'Makefile' ]] ; then \
		echo >&2 "'$$X' contient des tabulations"; fi; fi; done
	@#.................................................
	@# Les fichiers '*.txt' de './Exemples' et './Exemples-C++11' doivent etre en '444'
	@find ./Exemples ./Exemples-C++11 -type f -name '*.txt' -exec chmod 444 {} \;
	@#.................................................
	@# Les fichiers 'a.out' sont tous effaces
	@find . -name 'a.out' -exec rm -f {} \;
	@#.................................................
	@# Les executables sont suspects
	@find . -type f -perm u+x
	@#.................................................
	@# Le compilateur par defaut du C++11 DOIT etre gcc
	@if [ $$(make --no-print-directory -f RegExp/Makefile cxx) != 'g++' ] ; then echo >&2 \
		"Le compilateur par defaut du C++11 n'est pas g++! Corrigez!"; fi

# FAIRE : Dans un meme repertoire il ne faut pas 2 fichiers qui ne varient que par la casse
#         Par exemple (28-Nov-2016) 'Vector' et 'vector' des exemples C++11




# ------------------------------------------------------------------------------------ 89
# Fonction facilitant le lancement des compilations. Voir commentaires dans le fichier
compile.sh: comp.sh
comp.sh: Makefile
	@echo  >./comp.sh "#!/bin/bash"
	@echo >>./comp.sh
	@echo >>./comp.sh "# Ce fichier doit etre charge dans le shell par 'source ./comp.sh'"
	@echo >>./comp.sh "# Une fois chargee, la fonction 'comp' trouve la ligne 'A compiler...'"
	@echo >>./comp.sh "# d'un fichier source, et lance la compilation en suivant les instructions"
	@echo >>./comp.sh "# Accessoirement ce fichier positionne aussi la variable LD_LIBRARY_PATH"
	@echo >>./comp.sh
	@echo >>./comp.sh "LD_LIBRARY_PATH=\$$LD_LIBRARY_PATH:/usr/lib/octave-3.0.1"
	@echo >>./comp.sh "export LD_LIBRARY_PATH"
	@echo >>./comp.sh
	@echo >>./comp.sh "function comp {"
	@echo >>./comp.sh
	@echo >>./comp.sh "local VERSION='comp (depuis \"./comp.sh\")	-	Version 1.0.1'"
	@echo >>./comp.sh "if [[ \$$# -ne 1 ]] ; then echo >&2 \"Usage: comp fichier\" ; return 1 ; fi"
	@echo >>./comp.sh "if [[ "\$$1" = '--version' ]] ; then echo -e \"\n\$$VERSION\n\" ; return 0 ; fi"
	@echo >>./comp.sh "if [[ ! -r "\$$1" ]]; then echo -e >&2 \"\n'\$$1' est introuvable ou illisible\n\"; return 1; fi"
	@echo >>./comp.sh
	@echo >>./comp.sh "local COMPIL=\$$(grep -i '[cC]ompiler' \"\$$1\"| sed -e \"s/[^']*'//\" -e \"s/'.*//\")"
	@echo >>./comp.sh "if [[ -n \"\$$COMPIL\" ]] ; then"
	@echo >>./comp.sh "	local EXE=\$$(echo \$$COMPIL | sed -e 's/.*-o //' -e 's/ .*//')"
	@echo >>./comp.sh "	if [[ \"\$$EXE\" = 'g++' ]]; then EXE='a.out'; fi"
	@echo >>./comp.sh "else"
	@#echo >>./comp.sh "	local EXE=\"\$${1%.*}\"; COMPIL=\"g++ -Wall \$$1 -o \$$EXE\" ; fi"
	@echo >>./comp.sh "	local EXE='a.out'; COMPIL=\"g++ -Wall \$$1 -o \$$EXE\" ; fi"
	@echo >>./comp.sh
	@echo >>./comp.sh "echo ; echo \"\$$COMPIL\" ; eval \$$COMPIL"
	@echo >>./comp.sh "if [[ \$$? -eq 0 ]]; then echo; eval './'\$$EXE; return 0; else echo; return 1; fi"
	@echo >>./comp.sh
	@echo >>./comp.sh "}"
	@echo >>./comp.sh
	@echo >>./comp.sh "# Fin du fichier 'comp.sh'"


# Fin de 'Makefile' du repertoire 'Home' du stagiaire (Pro*C, C++, C++11)
