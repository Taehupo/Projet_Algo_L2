#ifndef VOIE_H
#define VOIE_H

typedef unsigned int uint;

typedef struct
{
	ville * depart;
	ville * arrivee;

	uint duree;
}voie;

void init_voie(voie *, ville *, ville *, uint);

#endif