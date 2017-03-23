#include <stdio.h>
#include <stdlib.h>

#include "../headers/villes.h"

void init_ville(ville * city, uint abs, uint ord)
{
	city->abscisse = abs;
	city->ordonnee = ord;
	city->in_ligne = (int *) malloc(sizeof(int) * 200);
	city->rank_ligne = (int *) malloc(sizeof(int) * 200);
	for (int i = 0; i < 200; ++i)
	{
		city->in_ligne[i] = -1;
		city->rank_ligne[i] = -1;
	}
}

uint get_abs(ville * city)
{
	return city->abscisse;
}

uint get_ord(ville * city)
{
	return city->ordonnee;
}

void display_all_ville(ville * table, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("La ville %d a une abscisse de %d et une ordonnée de %d\n", i, get_abs(&table[i]), get_ord(&table[i]));
	}
}

void display_lignes_of_villes(ville * table, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0;j < 200; ++j)
		{
			if (table[i].in_ligne[j] != -1)
			{
				printf("La ville %d est dans la ligne %d au rang %d\n", i, table[i].in_ligne[j], table[i].rank_ligne[j]+1);
			}	
		}		
	}
}