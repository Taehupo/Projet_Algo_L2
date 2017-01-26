#ifndef VILLES_H
#define VILLES_H

typedef unsigned int uint;

typedef struct
{
	uint abscisse;
	uint ordonnee;
}ville;

void init_ville(ville *, uint, uint);
uint get_abs(ville);
uint get_ord(ville);
void display_all_ville(ville *, int);

#endif