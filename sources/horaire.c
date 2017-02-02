#include <stdio.h>
#include <stdlib.h>

#include "../headers/horaire.h"

int calculer_horaire(int heure, int minute)
{
	return ((heure*60) + minute);
}

void afficher_horaires_all(int ** table, int sizex, int sizey)
{
	for (int x = 0; x < sizex; ++x)
	{
		for (int y = 0; y < sizey; ++y)
		{
			int tmp_h = table[x][y] / 60;
			int tmp_m = table[x][y] % 60;
			printf("Passage %d horaire %d : %dh%d\n", x, y, tmp_h, tmp_m);
		}
	}
}