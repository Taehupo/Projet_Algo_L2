app: sources/villes.o sources/voie.o sources/ligne.o sources/main.o
	gcc -Wall -g -o app main.o villes.o voie.o ligne.o

sources/main.o: sources/main.c
	gcc -Wall -g -c sources/main.c

sources/villes.o: sources/villes.c
	gcc -Wall -g -c sources/villes.c

sources/voie.o: sources/voie.c
	gcc -Wall -g -c sources/voie.c

sources/ligne.o: sources/ligne.c
	gcc -Wall -g -c sources/ligne.c

clean_o:
	rm -f *.o

clean_app:
	rm -f app