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
	char verif = ' ';
	csgn = consigne(CONSIGNE);	// Appel à la fonction consigne pour récuperer la valeur de la consigne du fichier consigne
	printf("Valeur de la consigne : %.2f \n", csgn);

	FILE* myfile = fopen("trace.txt", "r");
	int ch, number_of_lines = 0;

	do {
    	ch = fgetc(myfile);
		verif = fgetc(myfile);
    	if(ch == '\n')
        	number_of_lines++;
		if(verif=="false")
			verif="false";
		else if(verif=="true")
			verif="true";
	} while (ch != EOF);

	// last line doesn't end with a new line!
	// but there has to be a line at least before the last line
	if(ch != '\n' && number_of_lines != 0) 
    	number_of_lines++;

	fclose(myfile);

	printf("number of lines in test.txt = %d\n", number_of_lines);
	printf("Value of verif : %d\n",verif);

	

	

	temp_t temperature;
	temperature.exterieure = 30.0;
	temperature.interieure = 40.0;

	visualisationT(temperature);

	struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialis�e � 0%
	int i=0; // increment de boucle
	float puissance = 10.0; // puissance de chauffage

	visualisationC(puissance);

	for(i=0;i< 30;i++){
		temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
	}
	simDestruct(monSimulateur_ps); // destruction de simulateur
	return EXIT_SUCCESS;
}
