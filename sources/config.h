#ifndef CONFIG_H
#define CONFIG_H

#define NB_SEGMENTS 3 	//nb_segments sur la course
#define NB_LIGNES 3 	// nb_lignes 
#define NB_CASES 30 	// nb de cases par ligne

#define NB_VOITURES_EQUIPE 1	//nb voitures par equipe
#define NB_EQUIPES 1		//nb équipes au total

#define HANDICAP_LIGNE_2 1.2
#define HANDICAP_LIGNE_3 1.5
#define KEY "/tmp/lock"

#define VOITURE_VITESSE_CROISIERE_MIN 250
#define VOITURE_VITESSE_CROISIERE_MAX 300
#define VOITURE_ACCELERATION_MAX 3
#define VOITURE_DECELERATION_MAX 3
#define LONGUEUR_CASE 0.1

#define MAX_CARBURANT = 100
#define MAX_PNEUS = 100

#endif
