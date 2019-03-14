#include "regulation.h"

float regulationTest(int regul,float csgn,float* tabT, int nT){
	SPID * pid;
	pid = malloc(1*sizeof(SPID));
	pid->newV = 0;
	pid->newV = tabT[0];
	pid->newI = (csgn - tabT[0]);
	pid->valueI = 0;
	float cmd = 100;
   int i = 0;
   for(i = 0; i < nT; i++){
		pid->previousV = pid->newV;
		pid->newV = tabT[i];
      cmd = regulation(regul,csgn,tabT[i],pid,i);
   }
	free(pid);
   return cmd;
}

float regulation(int regul, float csgn, float valueTemp,SPID * pid,int i){
	float KP = 1;
	float KD = 0.1;
	float KI = 0.1;
	float cmd = 0.0;
	if(regul == 1){
		if(csgn > valueTemp){
			cmd = 40.0;
		}else{
			cmd = 0.0;
		}
	}else{
		if(i != 0){
			pid->previousI = pid->newI;
			pid->newI = (csgn - valueTemp);
			pid->valueI = pid->valueI + ((pid->previousI + pid->newI) * 10) / 2;
		}
		pid->valueP = (csgn - valueTemp);
		pid->valueD = (pid->previousV - pid->newV) / 10;

		cmd = pid->valueD * KD + pid->valueP * KP + pid->valueI * KI;
	}
	return cmd;
}