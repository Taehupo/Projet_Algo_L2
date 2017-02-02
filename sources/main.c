#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/villes.h"
#include "../headers/voie.h"
#include "../headers/horaire.h"
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

	if (fichier != NULL) 													// Si le fichier existe
	{
		fgets(parsing, 100, fichier);										// Récupérer la première ligne
		ville_table_size = atoi(parsing);									// Récuprere le nombre de ville
		ville_table = (ville *) malloc(sizeof(ville) * ville_table_size);	// Allocation du tableau de villes
		printf("Il y a %d villes\n", ville_table_size);						// Debug

		for (int i = 0; i < ville_table_size; ++i)
		{
			fgets(parsing, 100, fichier);									// récup des donnée de la ville
			int tmp1;
			int tmp2;
			int j;
			tmp1 = atoi(parsing);											// récup le premier nombre
			int tmp = tmp1;
			for(j = 0; tmp != 0 ; ++j)										// calcul de la place du second chiffre
			{
				tmp = tmp / 10;
			}
			tmp2 = atoi(parsing+j);											// récup le second chiffre
			init_ville(&ville_table[i], tmp1, tmp2);						// Initialise la ville
		}
		display_all_ville(ville_table, ville_table_size);					// Affichage des villes + coordonnées

		fgets(parsing, 100, fichier);										// récup du nombre de lignes
		ligne_table_size = atoi(parsing);									// stockage de la taille du tableau de lignes
		ligne_table = (ligne *) malloc(sizeof(ligne) * ligne_table_size);	// Allocation dynamique
		printf("Il y as %d lignes\n", ligne_table_size);					// Debug

		for (int i = 0; i < ligne_table_size; ++i)
		{
			fgets(parsing, 100, fichier);									// Nb de ville dans la ligne
			int nb_ville_ligne = atoi(parsing);								// Stockage du nb ville dans ligne
			init_ligne_ville_tab(&ligne_table[i], atoi(parsing));			// Initialisation du tableau de ville de la ligne
			fgets(parsing, 100, fichier);									// Récup des villes de la lignes
			char * tmp_ville;
			tmp_ville = strtok(parsing, " ");
			int j = 0;
			while(tmp_ville != NULL)
			{
				int tmp_nb_ville = atoi(tmp_ville);
				add_ville(ligne_table[i].ville_tab, &ville_table[tmp_nb_ville], j);
				++j;
				tmp_ville = strtok(NULL, " ");
			}
			display_all_ville(ligne_table[i].ville_tab, nb_ville_ligne);
			fgets(parsing, 100, fichier);
			int nb_pass_ligne = atoi(parsing);
			init_horaire_table(&ligne_table[i], nb_pass_ligne, nb_ville_ligne);

		}
	}
	else
	{
		printf("Erreur, fichier non trouvé\n");
		exit(1);
	}

	return 0;
}