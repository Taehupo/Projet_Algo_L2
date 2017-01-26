#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/villes.h"
#include "../headers/voie.h"
#include "../headers/ligne.h"

int main(int argc, char const *argv[])
{
	FILE * fichier;

	char parsing[100];

	ville * ville_table;

	ligne * ligne_table;

	int ville_table_size;
	int ligne_table_size;

	fichier = fopen("test", "r");

	if (fichier != NULL)
	{
		fgets(parsing, 100, fichier);
		ville_table_size = atoi(parsing);
		ville_table = (ville *) malloc(sizeof(ville) * ville_table_size);
		printf("Il y a %d villes\n", ville_table_size);

		for (int i = 0; i < ville_table_size; ++i)
		{
			fgets(parsing, 100, fichier);
			int tmp1;
			int tmp2;
			int j;
			tmp1 = atoi(parsing);
			int tmp = tmp1;
			for(j = 0; tmp != 0 ; ++j)
			{
				tmp = tmp / 10;
			}
			tmp2 = atoi(parsing+j);
			init_ville(&ville_table[i], tmp1, tmp2);
		}
		display_all_ville(ville_table, ville_table_size);

		fgets(parsing, 100, fichier);
		ligne_table_size = atoi(parsing);
		ligne_table = (ligne *) malloc(sizeof(ligne) * ligne_table_size);
		printf("Il y as %d lignes\n", ligne_table_size);

	}
	else
	{
		printf("Erreur, fichier non trouvé\n");
		exit(1);
	}

	return 0;
}