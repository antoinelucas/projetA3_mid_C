#include "visualisationC.h"

void visualisationC(float puissance_f){
   FILE *fichier, *verrouFile = NULL;
   float tempExt, tempInt;
   char *chaine = malloc(8 * sizeof(char));     // On alloue de la mémoire à la chaine de caractère

   if (access(".verrouData", F_OK) == -1){      // On vérifie que le fichier data.txt est pas déjà en lecture
      verrouFile = fopen(".verrouData", "w");   // Crée le fichier .verrouData afin de signifier que le fichier data.txt est en utilisation

      fichier = fopen("data.txt", "r");         // Permet d'ouvrir le fichier data.txt en lecture seule
      if (fichier != NULL){
         fscanf(fichier, "%f%f%s", &tempExt, &tempInt, chaine);   // On récupère les valeurs déjà écrite dans data.txt
         fclose(fichier);
      }

      fichier = fopen("data.txt", "w");         // Permet d'ouvrir le fichier data.txt en écriture
      if (fichier != NULL){
         if(puissance_f == 0){
            fprintf(fichier, "%.2f\n%.2f\nfalse", tempExt, tempInt); // On écrit les valeurs de températures qui étaient déjà dans data.txt
         }else if(puissance_f > 0){                                  // et on met true ou false en fonction de la puissance pour savoir si on met en route le chauffage ou non
            fprintf(fichier, "%.2f\n%.2f\ntrue", tempExt, tempInt);
         }
         fclose(fichier);
      }
      fclose(verrouFile);
      remove(".verrouData");  // On enlève le verrou
      free(chaine);     // On libère l'espace alloué 
   }
}