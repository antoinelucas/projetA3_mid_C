#include <stdio.h>
#include <stdlib.h>
#include "simulateur.h"
#include "consigne.h"
#include "visualisationT.h"
#include "visualisationC.h"
#include "define.h"

#define CONSIGNE 0

int main(){
	float csgn = 0;
	csgn = consigne(CONSIGNE);	// Appel à la fonction consigne pour récuperer la valeur de la consigne du fichier consigne
	printf("Valeur de la consigne : %.2f \n", csgn);

	

	temp_t temperature;
	temperature.exterieure = 80.0;
	temperature.interieure = 20.0;

	visualisationT(temperature);

	struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialis�e � 0%
	int i=0; // increment de boucle
	float puissance = 0.0; // puissance de chauffage

	visualisationC(puissance);

	for(i=0;i< 30;i++){
		temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
	}
	simDestruct(monSimulateur_ps); // destruction de simulateur
	return EXIT_SUCCESS;
}
