#include "simulateur.h"
#include "consigne.h"
#include "visualisationT.h"
#include "visualisationC.h"
#include "define.h"
#include "regulation.h"
#include "integration.h"

#define CONSIGNE 0

int main(){
	/*temp_t temperature;
	temperature.exterieure = 14.0;
	temperature.interieure = 15.0;
	struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialisée à 0%
	int i=0; // increment de boucle

	csgn = consigne(CONSIGNE);	// Appel à la fonction consigne pour récuperer la valeur de la consigne du fichier consigne
	printf("Valeur de la consigne : %.2f \n", csgn);

	visualisationT(temperature);

	struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialis�e � 0%
	float puissance = 15.0; // puissance de chauffage


	visualisationC(puissance);

	for(i=0;i< 30;i++){
		temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
		integrationTest(2,temperature,i);
	}
	simDestruct(monSimulateur_ps); // destruction de simulateur*/
	return EXIT_SUCCESS;
}
