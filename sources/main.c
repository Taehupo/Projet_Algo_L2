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

	if (fichier != NULL) 																	// Si le fichier existe
	{
		fgets(parsing, 100, fichier);														// Récupérer la première ligne
		ville_table_size = atoi(parsing);													// Récuprere le nombre de ville
		ville_table = (ville *) malloc(sizeof(ville) * ville_table_size);					// Allocation du tableau de villes
		printf("Il y a %d villes\n", ville_table_size);										// Debug

		for (int i = 0; i < ville_table_size; ++i)
		{
			fgets(parsing, 100, fichier);													// récup des donnée de la ville
			int tmp1;
			int tmp2;
			int j;
			tmp1 = atoi(parsing);															// récup le premier nombre
			int tmp = tmp1;
			for(j = 0; tmp != 0 ; ++j)														// calcul de la place du second chiffre
			{
				tmp = tmp / 10;
			}
			tmp2 = atoi(parsing+j);															// récup le second chiffre
			init_ville(&ville_table[i], tmp1, tmp2);										// Initialise la ville
		}
		display_all_ville(ville_table, ville_table_size);									// Affichage des villes + coordonnées

		fgets(parsing, 100, fichier);														// récup du nombre de lignes
		ligne_table_size = atoi(parsing);													// stockage de la taille du tableau de lignes
		ligne_table = (ligne *) malloc(sizeof(ligne) * ligne_table_size);					// Allocation dynamique
		printf("Il y as %d lignes\n", ligne_table_size);									// Debug

		for (int i = 0; i < ligne_table_size; ++i)
		{
			fgets(parsing, 100, fichier);													// Nb de ville dans la ligne
			int nb_ville_ligne = atoi(parsing);												// Stockage du nb ville dans ligne
			init_ligne_ville_tab(&ligne_table[i], atoi(parsing));							// Initialisation du tableau de ville de la ligne
			fgets(parsing, 100, fichier);													// Récup des villes de la lignes
			char * tmp_ville;																// Préparation du parsing de la liste de ville de la ligne
			tmp_ville = strtok(parsing, " ");												// Parsing de la liste de ville en cour, en utilisant l'espace comme séparateur
			int j = 0;
			while(tmp_ville != NULL)														// Boucle de parsing
			{
				int tmp_nb_ville = atoi(tmp_ville);											// Récup de l'id de la ville
				add_ville(ligne_table[i].ville_tab, &ville_table[tmp_nb_ville], j);			// Ajout de la ville au tableau de ville
				++j;
				tmp_ville = strtok(NULL, " ");
			}
			printf("Ligne %d\n", i);														// Debug
			display_all_ville(ligne_table[i].ville_tab, nb_ville_ligne);					// Affichage de toute les villes enregistrées
			fgets(parsing, 100, fichier);													// Récupération du nombre de ligne
			int nb_pass_ligne = atoi(parsing);												// Convertion du nombre de ligne en nombre entier
			init_horaire_table(&ligne_table[i], nb_pass_ligne, nb_ville_ligne);				// Initailisation de la table des horaires
			for (int x = 0; x < nb_pass_ligne; ++x)											// Début du parsing des horaires de la lignes
			{
				fgets(parsing, 100, fichier);												// Récupération de la ligne

				int tmp_heure = 0;
				int tmp_minute = 0;
				int differentiateur = 0;
				int y = 0;
				int tmp_duree = 0;
				char * tmp_horaire = strtok(parsing, " h");									// Récupération du premier composant de l'horaire en utilisant l'espace et h comme séparateur
				while(tmp_horaire != NULL && y < nb_ville_ligne)							// Boucle de récupération des reste des composant d'horaires par passages
				{
					if (differentiateur == 0)												// Récupération de l'heure
					{
						tmp_heure = atoi(tmp_horaire);
					} 
					else if (differentiateur == 1)
					{
						tmp_minute = atoi(tmp_horaire);										// Récupération des minutes
						tmp_duree = calculer_horaire(tmp_heure, tmp_minute);				// Conversion du temps au format heurehminutes en minutes
						ligne_table[i].horaires[x][y] = tmp_duree;							// Insertion dans le tableau
						tmp_heure = 0;														// Réinistialisation du temps heure
						tmp_minute = 0;														// Réinitialisation du temps minute
						y++;																// On avance la boucle de 1
					}
					if (differentiateur == 0)												// Gestion de l'heure ou minute via le differentiateur
						differentiateur = 1;
					else
						differentiateur = 0;
					tmp_horaire = strtok(NULL, " h");										// Parsing de l'élément suivant, utilisant l'espace et h comme séparateurs
				}
			}
			afficher_horaires_all(ligne_table[i].horaires, nb_pass_ligne, nb_ville_ligne);	// Affichage de debug des horaires d'une ligne
		}
	/*	for (int i = 0; i < ligne_table_size; ++i)
			{
				for (int j = 0; j < ligne_table[i].nb_villes; ++j)
				{
					for (int x = 0; x < ville_table_size; ++x)
					{
						if ((ligne_table[i].ville_tab[j].abscisse == ville_table[x].abscisse) && (ligne_table[i].ville_tab[j].ordonnee == ville_table[x].ordonnee))
						{
							for (int y = 0; y < 200 || ville_table[x].in_ligne[y] != -1; ++y)
							{
								ville_table[x].in_ligne[y] = i;
								ville_table[x].rank_ligne[y] = j;
							}
						}
					}
				}
			}*/ //Pas encore fonctionnel
	}
	else																					// Si le fichier n'est pas charger
	{
		printf("Erreur, fichier non trouvé\n");												// Alors erreur
		exit(1);																			// Sortie du programme
	}

	return 0;
}