app: villes.o voie.o ligne.o main.o horaire.o
	gcc -Wall -g -std=c99 -o app main.o villes.o voie.o ligne.o horaire.o

main.o: sources/main.c
	gcc -Wall -g -std=c99 -c sources/main.c

villes.o: sources/villes.c
	gcc -Wall -g -std=c99 -c sources/villes.c

voie.o: sources/voie.c
	gcc -Wall -g -std=c99 -c sources/voie.c

ligne.o: sources/ligne.c
	gcc -Wall -g -std=c99 -c sources/ligne.c

horaire.o: sources/horaire.c
	gcc -Wall -g -std=c99 -c sources/horaire.c

clean_o:
	rm -f *.o

clean_app:
	rm -f app
