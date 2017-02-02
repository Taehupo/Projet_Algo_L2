#ifndef LIGNE_H
#define LIGNE_H

typedef unsigned int uint;

typedef struct
{
	ville * ville_tab;
	uint nb_villes;
	uint nb_passage;
	int ** horaires;
}ligne;

void init_ligne(ligne *, uint);
void add_ville(ville *, ville *, int);
void init_ligne_ville_tab(ligne *, uint);
void init_horaire_table(ligne *, uint, uint);

#endif