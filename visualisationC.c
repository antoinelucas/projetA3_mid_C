#include "visualisationC.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void visualisationC(float puissance_f){
   FILE *fichier, *verrouFile = NULL;

   if (access(".verrouData", F_OK) == -1){      // On vérifie que le fichier data.txt est pas déjà en lecture
      verrouFile = fopen(".verrouData", "a");   // Crée le fichier .verrouData afin de signifier que le fichier data.txt est en utilisation
      fichier = fopen("data.txt", "a");         // Permet d'ouvrir le fichier data.txt

      if (fichier != NULL){
         printf("ok5\n");
         if(puissance_f == 0){
            printf("ok6\n");
            fprintf(fichier, "false");
         }else if(puissance_f > 0){
            printf("ok7\n");
            fprintf(fichier, "\n\ntrue");
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
