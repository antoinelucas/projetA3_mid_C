#include "visualisationT.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void visualisationT(temp_t myTemp){
    FILE *fichier, *verrouFile = NULL;

    if (access(".verrouData", F_OK) == -1){ // On vérifie que le fichier data.txt est pas déjà en lecture
        verrouFile = fopen(".verrouData", "a");
        fichier = fopen("data.txt", "w"); // Permet d'ouvrir le fichier data.txt
            
        if (fichier != NULL){
            fprintf(fichier, "%.2f\n%.2f\n", myTemp.exterieure, myTemp.interieure);
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

