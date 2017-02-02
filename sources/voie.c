#include <stdio.h>
#include <stdlib.h>

#include "../headers/villes.h"
#include "../headers/horaire.h"
#include "../headers/voie.h"

void init_voie(voie * init_target, ville * v1, ville * v2, uint temps)
{
	init_target->depart = v1;
	init_target->arrivee = v2;
	init_target->duree = temps;
}