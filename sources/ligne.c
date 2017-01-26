#include <stdio.h>
#include <stdlib.h>

#include "../headers/villes.h"
#include "../headers/voie.h"
#include "../headers/ligne.h"

void init_ligne(ligne * init_target, uint tab_size, uint nb_pass)
{
	init_target->nb_passage = nb_pass;
	init_target->ville_tab = (ville *) malloc(sizeof(ville) * tab_size);
}

void add_ville(ville * tab, ville * city, int place)
{
	*(tab+place) = *city;
}