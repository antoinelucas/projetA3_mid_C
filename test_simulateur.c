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
	int i=0; // increment de boucle
	float stamp1,stamp2,stamp3=0.0;
	char* token;
	

	csgn = consigne(CONSIGNE);	// Appel à la fonction consigne pour récuperer la valeur de la consigne du fichier consigne
	printf("Valeur de la consigne : %.2f \n", csgn);

	/*FILE* myfile = fopen("trace.txt", "r");
	int ch, number_of_lines = 0;

	do {
    	ch = fgetc(myfile);
    	if(ch == '\n')
        	number_of_lines++;
	} while (ch != EOF);

	// last line doesn't end with a new line!
	// but there has to be a line at least before the last line
	if(ch != '\n' && number_of_lines != 0) 
    	number_of_lines++;

	printf("number of lines in trace.txt = %d\n", number_of_lines);

	float tabT[number_of_lines];

	/*do {
    	ch = fgetc(myfile);
		token=strtok(ch,'\t');
		while(token != NULL){
			printf( " %s\n", token );
     		token = strtok(NULL, '\t');
		}
		tabT[i]=strtod(token,NULL);
		i++;
	} while (ch != EOF);*/

	for(i=0;i<number_of_lines;i++){
		fscanf(myfile,"%f %f %f %f",&stamp1,&stamp2,&stamp3,&tabT[i]);	
		printf("%f %f %f %f \n",stamp1,stamp2,stamp3,tabT[i]);
		stamp1,stamp2,stamp3=0.0;
	}

	/*for(i=0;i<number_of_lines;i++){
		printf("%f\n",&tabT[i]);
	}*/

	fclose(myfile);

	printf("number of lines in test.txt = %d\n", number_of_lines);
	printf("Value of verif : %d\n",verif);

	*/

	

	temp_t temperature;
	temperature.exterieure = 10.0;
	temperature.interieure = 12.0;

	visualisationT(temperature);

	struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialis�e � 0%
	float puissance = 0.0; // puissance de chauffage


	//visualisationC(puissance);

	for(i=0;i< 30;i++){
		temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
	}
	simDestruct(monSimulateur_ps); // destruction de simulateur
	return EXIT_SUCCESS;
}
