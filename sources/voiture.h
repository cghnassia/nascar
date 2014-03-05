#ifndef VOITURE_H
#define VOITURE_H

typedef struct voiture_t voiture_t;
struct voiture_t {
	int id; 	//numéro voiture dans l'équipe
	int vitesse; 	//vitesse courrante
	position_t position; 	//position de la voiture
	//int avancement:	//avancement de la voiture sur la position
	int carburant;	//niveau de carburant
	int pneus;	//niveau des pneus 	
};

static pthread_t voitures[NB_VOITURES_EQUIPE * NB_EQUIPES];
static int positionsDepart[NB_VOITURES_EQUIPE * NB_EQUIPES];

void initVoitures();

//permet d'avoir un id de voiture en fonction de son équipe de son num dans l'équipe
int constuireIdVoiture(int iEquipe, int iVoiture);

int getEquipeFromId(int id);

void getPositionStartFromId(int id, position_t* position);

#endif
