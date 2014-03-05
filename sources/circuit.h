#ifndef CIRCUIT_H
#define CIRCUIT_H

//correspond à une case du circuit
typedef struct case_t case_t;
struct case_t {
	int isOccupe;
	pthread_cond_t condition;
};

//permet d'identifier une case sur le circuit
typedef struct position_t position_t;
struct position_t {
	int iSegment;
	int iLigne;
	int iCase;
};


//attributs
static case_t circuit[NB_SEGMENTS][NB_LIGNES][NB_CASES];
static pthread_mutex_t verrouCircuit = PTHREAD_MUTEX_INITIALIZER;

int initCircuit();

int isLibre(position_t *position);

void getCaseSuivante(position_t *position);

void updatePosition(position_t *ancienne, position_t *nouvelle);

#endif
