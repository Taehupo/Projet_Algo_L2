#include <stdio.h>
#include <stdlib.h>

#include "../headers/villes.h"

void init_ville(ville * city, uint abs, uint ord)
{
	city->abscisse = abs;
	city->ordonnee = ord;
}

uint get_abs(ville city)
{
	return city.abscisse;
}

uint get_ord(ville city)
{
	return city.ordonnee;
}

void display_all_ville(ville * table, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("La ville %d a une abscisse de %d et une ordonnée de %d\n", i, table[i].abscisse, table[i].ordonnee);
	}
}