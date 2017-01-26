#ifndef LIGNE_H
#define LIGNE_H

typedef unsigned int uint;

typedef struct
{
	ville * ville_tab;
	uint nb_passage;
}ligne;

void init_ligne(ligne *, uint, uint);
void add_ville(ville *, ville *, int);

#endif