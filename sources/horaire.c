#include <stdio.h>
#include <stdlib.h>

#include "../headers/horaire.h"

int calculer_horaire(int heure, int minute)
{
	return ((heure*60) + minute);
}