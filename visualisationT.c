#include "visualisationT.h"
#include <unistd.h>


void visualisationT(temp_t myTemp){
    FILE* fichier;
    FILE *verrouFile;
    float tempExt;
    float tempInt;
    char* chaine = malloc(8*sizeof(char));
    //printf("%d",access(".verrouData", F_OK));

        if (access(".verrouData", F_OK) != -1){ // On vérifie que le fichier data.txt est pas déjà en lecture
        }else{
            verrouFile = fopen(".verrouData", "w");
       
            fichier = fopen("data.txt", "r"); // Permet d'ouvrir le fichier data.txt
            printf("Erreur8");
            //if (fichier != NULL){
                fscanf(fichier, "%f", &tempExt);
                printf("Erreur7");
                fscanf(fichier, "%f", &tempInt);
                printf("Erreur9");
                fscanf(fichier, "%s", chaine);
                printf("Erreur1");
                //fclose(fichier);
            //}
            //fichier = fopen("data.txt", "w+");
            //if (fichier != NULL){
                printf("Erreur2");
                fprintf(fichier, "%.2f\n", myTemp.exterieure);
                fprintf(fichier, "%.2f\n", myTemp.interieure);
                fprintf(fichier, "%s", chaine);
                printf("Erreur3");
                fclose(fichier);
                fclose(verrouFile);
                remove(".verrouData");
            /*}else{
                printf("Erreur");
            }*/
        }
}

