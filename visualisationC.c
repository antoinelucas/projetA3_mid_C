#include "visualisationC.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void visualisationC(float puissance_f){
   FILE *fichier, *verrouFile = NULL;
   float tempExt, tempInt;
   char *chaine = malloc(8 * sizeof(char));

   if (access(".verrouData", F_OK) == -1){      // On vérifie que le fichier data.txt est pas déjà en lecture
      verrouFile = fopen(".verrouData", "w");   // Crée le fichier .verrouData afin de signifier que le fichier data.txt est en utilisation

      fichier = fopen("data.txt", "r"); // Permet d'ouvrir le fichier data.txt
      if (fichier != NULL){
         fscanf(fichier, "%f%f%s", &tempExt, &tempInt, chaine);
         fclose(fichier);
      }

      fichier = fopen("data.txt", "w");
      if (fichier != NULL){
         if(puissance_f == 0){
            fprintf(fichier, "%.2f\n%.2f\nfalse", tempExt, tempInt);
         }else if(puissance_f > 0){
            fprintf(fichier, "%.2f\n%.2f\ntrue", tempExt, tempInt);
         }
         fclose(fichier);
         fclose(verrouFile);
         remove(".verrouData");
      }

   }else{
      printf("\n\n Le fichier data est déjà ouvert\n\n");
   }
}
