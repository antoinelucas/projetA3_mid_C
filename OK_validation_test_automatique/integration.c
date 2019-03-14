#include "integration.h"
#include "regulation.h"
#include "visualisationT.h"
#include "visualisationC.h"
#include "consigne.h"
#include "simulateur.h"
#include "define.h"

void integrationTest(int regul,temp_t tInit,int nIterations){
    temp_t temperature;
    temperature = tInit;
    float csgn,cmd = 0;
    int i = 0;
    
    SPID * pid;
	pid = malloc(1*sizeof(SPID));
    pid->valueI = 0;

   /* printf("TOR (1) or PID (2) ?\n");
    scanf("%d", &regul);*/

    struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialisée à 0%
    
    for(i = 0; i < nIterations; i++){
        pid->newV = temperature.interieure;
	    pid->newI = (csgn - temperature.interieure);
        visualisationT(temperature);
        csgn = consigne(csgn);
        cmd = regulation(regul,csgn,temperature.interieure,pid,i);
        visualisationC(cmd);
        temperature = simCalc(cmd,monSimulateur_ps); // simulation de l'environnement
    }
    simDestruct(monSimulateur_ps); // destruction de simulateur
}