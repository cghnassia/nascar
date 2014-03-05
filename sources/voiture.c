#include "config.h"
#include <pthread.h>
#include "circuit.h"
#include "voiture.h"

//fonction correspondant au thread voiture
void *fn_voiture(void *param) { 	
	int id = (int) param;
	
	position_t position;
	getPositionStartFromId(id, &position);
	
	voiture_t voiture = {
		.id = id,
		.vitesse = 0,
		.position = position,
		.carburant = MAX_CARBURANT,
		.pneus = MAX_PNEUS,
	};
}

void initVoitures() {
	int i;
	int j;
	for(i = 0; i < NB_EQUIPES; i++) {
		for(j = 0; j < NB_VOITURES_EQUIPE; j++) {	
			pthread_create(&voitures[i], NULL, fn_voiture, (void *) getIdVoiture(i + 1, j + 1));
		}
	}
}

//permet d'avoir un id de voiture en fonction de son équipe de son num dans l'équipe
int getIdVoiture(int iEquipe, int iVoiture) {
	return iEquipe * 10 + iVoiture;
}

//permet de recupérer le numéro d'équipe d'une voiture en fonction de son id
int getEquipeFromId(int id) {
	return (id - id % 10) / 10;
}

//pour placer les voitures dans la bonne case au départ de la course
void getPositionStartFromId(int id, position_t* position) {

	int res, i;
	for(i = 0; i < NB_VOITURES_EQUIPE * NB_EQUIPES; ++i) {
		if(positionsDepart[i] == id) {
			res = i;
			break;
		}
	}
	
	position->iSegment = 0;
	position->iLigne = res / 2; 
	position->iCase = res % 2;
}
