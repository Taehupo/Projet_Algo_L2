#include <stdio.h>
#include <stdlib.h>

#include "../headers/villes.h"
#include "../headers/voie.h"
#include "../headers/horaire.h"
#include "../headers/ligne.h"

void init_ligne(ligne * init_target, uint nb_pass)
{
	init_target->nb_passage = nb_pass;
}

void add_ville(ville * tab, ville * city, int place)
{
	*(tab+place) = *city;
}

void init_ligne_ville_tab(ligne * init_target, uint tab_size)
{
	init_target->ville_tab = (ville *) malloc(sizeof(ville) * tab_size);
	init_target->nb_villes = tab_size;
}

void init_horaire_table(ligne * init_target, uint sizex, uint sizey)
{
	init_target->horaires = (int **) malloc(sizeof(int *) * sizex);
	for (int i = 0; i < sizex; ++i)
	{
		init_target->horaires[i] = (int *) malloc(sizeof(int) * sizey);
	}
}