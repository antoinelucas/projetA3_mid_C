   #include "regulation.h"
	 
	float regulationTest(int regul,float csgn,float* tabT, int nT){
		float cmd=100.0;
      int i=0;
      for(i=0;i<nT;i++){
          cmd=regulation(regul,csgn,tabT[i]);
      }
      return cmd;
		/*float cmd=100.0;
		FILE * fichier = NULL;
		fichier = fopen("data.txt","r"); // ouvre le fichier data.txt
		char etat_chauffage = ' '; //si false => chauffage allumé | si true => chauffage éteint

      if (fichier != NULL){
         fscanf(fichier, "%c", &etat_chauffage); // Lit la dernière valeur du fichier
			printf("%c\n",etat_chauffage);
			if(regul==1){
				/* TOUT OU RIEN 
				for (int i=0;i<nT;i++){
					if (tabT[i] < csgn) { 
						cmd*=0.4;
					}
				}
			} else if(regul == 2){
				/* PID 
			}
         fclose(fichier);
      }
      else{
         printf("Impossible d'ouvrir le fichier data.txt.\n");
      }
		return cmd;*/
   }
    
	float regulation(int regul, float csgn, float valueTemp){
		if(regul==1){
			if(csgn>valueTemp){

			}
		}else if(regul==2){
			
		}
	}
   