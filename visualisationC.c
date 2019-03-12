#include "visualisationC.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void visualisationC(float puissance_f){
   FILE *fichier, *verrouFile = NULL;
   //float tempExt = 0;
   //float tempInt = 0;

   if (access(".verrouData", F_OK) == -1){      // On vérifie que le fichier data.txt est pas déjà en lecture
      verrouFile = fopen(".verrouData", "w");   // Crée le fichier .verrouData afin de signifier que le fichier data.txt est en utilisation

      fichier = fopen("data.txt", "a"); // Permet d'ouvrir le fichier data.txt

      if (fichier != NULL){
         //fscanf(fichier, "%f\n%f\n", &tempExt, &tempInt);
         //printf("%f\n%f\n", tempExt, tempInt);
         if(puissance_f == 0){
            fprintf(fichier, "false");
         }else if(puissance_f > 0){
            fprintf(fichier, "true");
         }
         fclose(fichier);
         fclose(verrouFile);
         remove(".verrouData");
      }else{
         printf("Impossible d'ouvrir le fichier data.txt");
      }
   }else{
      printf("\n\n Le fichier data est déjà ouvert\n\n");
   }
}
