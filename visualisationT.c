#include "visualisationT.h"
#include <unistd.h>

void visualisationT(temp_t myTemp){
    FILE *fichier, *verrouFile = NULL;

    if (access(".verrouData", F_OK) == -1){ // On vérifie que le fichier data.txt est pas déjà en lecture par le programme Java
        verrouFile = fopen(".verrouData", "a");
        fichier = fopen("data.txt", "w"); // Permet d'ouvrir le fichier data.txt
            
        if (fichier != NULL){
            fprintf(fichier, "%f\n%f\n", myTemp.exterieure, myTemp.interieure);
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

