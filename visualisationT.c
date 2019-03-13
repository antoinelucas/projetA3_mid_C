#include "visualisationT.h"

void visualisationT(temp_t myTemp){
    FILE *fichier, *verrouFile = NULL;
    float tempExt, tempInt;
    char* chaine = malloc(8*sizeof(char));

    if (access(".verrouData", F_OK) == -1){ // On vérifie que le fichier data.txt est pas déjà en lecture
        verrouFile = fopen(".verrouData", "w");

        fichier = fopen("data.txt", "r"); // Permet d'ouvrir le fichier data.txt
        if (fichier != NULL){
            fscanf(fichier, "%f%f%s", &tempExt, &tempInt, chaine);
            fclose(fichier);
        }

        fichier = fopen("data.txt", "w");
        if (fichier != NULL){
            fprintf(fichier, "%.2f\n%.2f\n%s", myTemp.exterieure, myTemp.interieure, chaine);
            fclose(fichier);
            fclose(verrouFile);
            remove(".verrouData");
        }
    }
}
