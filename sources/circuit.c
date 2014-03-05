#include <pthread.h>
#include "config.h"
#include "circuit.h"

int initCircuit() {
	int i;
	int j;
	int z;

	for(i = 0; i < NB_SEGMENTS; i++) {
		for(j = 0; j < NB_LIGNES; j++) {
			for(z = 0; z < NB_CASES; z++) {
				case_t pCase;
				pCase.isOccupe = 0;
				pthread_cond_init(&(pCase.condition), NULL);
				circuit[i][j][z] = pCase;
			}
		}
	}

	return 0;
}

int isLibre(position_t *position) {

	return (! circuit[position->iSegment][position->iLigne][position->iCase].isOccupe);
}

void getCaseSuivante(position_t *position) {
	int res;

	if(position->iCase > NB_CASES - 1) {
		position->iCase = 0;
		position->iSegment = (position->iSegment + 1) % NB_SEGMENTS;
	}
	else {
		position->iCase++;
	}
}

void updatePosition(position_t *ancienne, position_t *nouvelle) {
	//on prend la case
	circuit[nouvelle->iSegment][nouvelle->iLigne][nouvelle->iCase].isOccupe = 1;
	pthread_cond_wait(&circuit[nouvelle->iSegment][nouvelle->iLigne][nouvelle->iCase].condition, &verrouCircuit);

	//on avertit qu'on a libéré la case
	circuit[ancienne->iSegment][ancienne->iLigne][ancienne->iCase].isOccupe = 0;
	pthread_cond_signal(&circuit[ancienne->iSegment][ancienne->iLigne][ancienne->iCase].condition);
}
