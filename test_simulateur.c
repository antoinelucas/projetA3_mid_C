#include <stdio.h>
#include <stdlib.h>
#include "simulateur.h"
#include "consigne.h"
#include "visualisationT.h"
#include "visualisationC.h"
#include "define.h"
#include "regulation.h"

#define CONSIGNE 0

int main(){
	temp_t temperature;
	float csgn = 0;
	float cmd = 0.0;
	int i=0; // increment de boucle
	temperature.exterieure = 10.0;
	temperature.interieure = 12.0;

	csgn = consigne(CONSIGNE);	// Appel à la fonction consigne pour récuperer la valeur de la consigne du fichier consigne
	printf("Valeur de la consigne : %.2f \n", csgn);

	visualisationT(temperature);

	struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialis�e � 0%
	float puissance = 0.0; // puissance de chauffage

	//visualisationC(puissance);

	float tabT[3]={15.0,16.0,17.0};

	cmd=regulationTest(2,19,tabT,30);

	for(i=0;i<30;i++){
		temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
	}

	simDestruct(monSimulateur_ps); // destruction de simulateur
	return EXIT_SUCCESS;
}
