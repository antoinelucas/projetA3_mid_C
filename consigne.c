#include "consigne.h"
#include <unistd.h>

// Fonction qui permet de récupérer la valeur de la commande de chauffage du fichier consigne.txt
float consigne(float csgn){
   FILE * fichier = NULL;

   if (access(".verrouConsigne", F_OK) == -1){ // On vérifie que le fichier consigne.txt est pas déjà en lecture par le programme Java
      fichier = fopen("consigne.txt", "r"); // Permet d'ouvrir le fichier consigne.txt

      if (fichier != NULL){
         fscanf(fichier, "%f", &csgn); // Lit la première valeur du fichier
         fclose(fichier);
      }else{
         printf("Impossible d'ouvrir le fichier consigne.txt");
      }
   }
   return csgn;
}