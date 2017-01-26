#include <stdio.h>
#include <stdlib.h>

#include "villes.h"

void init_ville(ville * city, uint abs, uint ord)
{
	ville->abscisse = abs;
	ville->ordonnee = ord;
}

uint get_abs(ville * city)
{
	return city->abscisse;
}

uint get_ord(ville * city)
{
	return city->ordonnee;
}