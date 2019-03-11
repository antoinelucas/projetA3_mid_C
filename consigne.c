#include "consigne.h"

// Fonction qui permet de récupérer la valeur de la commande de chauffage du fichier consigne.txt
float consigne(float csgn){
   FILE * fichier, *verrouFile = NULL;
   verrouFile = fopen(".verrouConsigne", "r");

   if (verrouFile == NULL){
      fichier = fopen("consigne.txt", "r"); // Permet d'ouvrir le fichier consigne.txt

      if (fichier != NULL){
         fscanf(fichier, "%f", &csgn); // Lit la première valeur du fichier
         fclose(fichier);
      }
      else{
         printf("Impossible d'ouvrir le fichier consigne.txt");
      }
   }
   return csgn;
}