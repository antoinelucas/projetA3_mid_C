#include "integration.h"
#include "regulation.h"
#include "visualisationT.h"
#include "visualisationC.h"
#include "consigne.h"

void integrationTest(int regul,temp_t tInit,int nIterations){
    temp_t temperature;
    SPID * pid;
	pid=malloc(1*sizeof(SPID));
    float csgn=0.0;
    float cmd=0.0;
    int i=0;

    csgn=consigne(CONSIGNE);

	pid->newV=temperature.interieure;
	pid->newI=(csgn-temperature.interieure);
	pid->valueI=0;
    
    for(i=0;i<nIterations;i++){
        pid->previousV=pid->newV;
		pid->newV=temperature.interieure;
        visualisationT(temperature);
        cmd=regulation(regul,csgn,temperature.interieure,pid,i);
        csgn=consigne(CONSIGNE);
        visualisationC(cmd);
    }
}
