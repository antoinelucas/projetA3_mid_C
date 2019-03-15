#include "integration.h"
#include "regulation.h"
#include "visualisationT.h"
#include "visualisationC.h"
#include "consigne.h"
#include "simulateur.h"
#include "define.h"

void integrationTest(int regul,temp_t tInit,int nIterations){
    //initialisation variable
    temp_t temperature;
    temperature = tInit; //temperature prend les valeurs des températures initiales
    float csgn,cmd = 0;
    int i = 0;
    int mode_PID = 2;

    SPID * pid;
	pid = malloc(1*sizeof(SPID)); //allocation de mémoire
    pid->valueI = 0;

    printf("TOR (1) ou PID (2) ?\n"); // choix du mode de régulation
    scanf("%d",&regul);

    struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialisée à 0%
    
    for(i = 0; i < nIterations; i++){
        pid->newV = temperature.interieure;
	    pid->newI = (csgn - temperature.interieure);
        visualisationT(temperature); //écrit dans data.txt les valeurs des températures
        csgn = consigne(csgn); //lit la valeur de la consigne dans consigne.txt
        cmd = regulation(regul,csgn,temperature.interieure,pid,i,mode_PID); //retourne la valeur de la puissance
        visualisationC(cmd); //écrit dans data.txt si le chauffage est en route ou ne l'est pas
        temperature = simCalc(cmd,monSimulateur_ps); // simulation de l'environnement
    }
    simDestruct(monSimulateur_ps); // destruction de simulateur
    free(pid); //libére la mémoire alloué par pid
}