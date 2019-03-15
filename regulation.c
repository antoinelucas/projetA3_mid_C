#include "regulation.h"

float regulationTest(int regul,float csgn,float* tabT, int nT){
	// initialisation variable
	SPID * pid;
	pid = malloc(1*sizeof(SPID));
	pid->newV = tabT[0];
	pid->newI = (csgn - tabT[0]); //on calcule l'erreur en cours
	pid->valueI = 0;
	float cmd = 100;
   int i = 0;

   for(i = 0; i < nT; i++){
		pid->previousV = pid->newV; // on garde en mémoire la valeur de la température intérieure
		pid->newV = tabT[i]; //on prend la nouvelle valeur de la température intérieure
      cmd = regulation(regul,csgn,tabT[i],pid,i,1); //on retourne la valeur de la puissance
   }
	free(pid);
   return cmd;
}

float regulation(int regul, float csgn, float valueTemp,SPID * pid,int i,int mode_PID){
	float cmd = 0.0;
	float KP,KI,KD = 0.0;

	switch(mode_PID){
		case 1: // test unitaire
			KP = 1; 
			KI = 0.1;
			KD = 0.1;
			break;
		case 2: // test pour l'intégration
			KP = 12; 
			KI = 0.12;
			KD = 0.03;
			break;
	}

	if(regul == 1){ // choix de la régulation TOR
		if(csgn > valueTemp){
			cmd = 40.0;
		}else{
			cmd = 0.0;
		}
	}else{ // choix de la régulation PID
		if(i != 0){
			pid->previousI = pid->newI; 
			pid->newI = (csgn - valueTemp);
			pid->valueI += ((pid->previousI + pid->newI) * 10) / 2; // on calcule l'intégral en utilisant la méthode des trapèzes
		}
		pid->valueP = (csgn - valueTemp); //calcule de l'erreur
		pid->valueD = (pid->previousV - pid->newV) / 10; //on calcule la dérivée en utilisant la taux d'accroisement

		cmd = (pid->valueP * KP) + (pid->valueI * KI) + (pid->valueD * KD); // application de la formule pour calculer le PID
	}
	return cmd;
}