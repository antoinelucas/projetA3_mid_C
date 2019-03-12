#include "visualisationT.h"
#include <unistd.h>

#define TAILLE_MAX 10 // Tableau de taille 5

void visualisationT(temp_t myTemp){
    FILE *fichier, *verrouFile = NULL;
    //char chaine[TAILLE_MAX] = "";
    //int i = 0;

        if (access(".verrouData", F_OK) == -1)
    { // On vérifie que le fichier data.txt est pas déjà en lecture
        verrouFile = fopen(".verrouData", "w");
        fclose(verrouFile);
        fichier = fopen("data.txt", "w"); // Permet d'ouvrir le fichier data.txt

        if (fichier != NULL){
            /*while(i != 3){
                fgets(chaine, TAILLE_MAX, fichier);
                i++;
                printf("\n\n%d\n\n", i);
                printf("%s", chaine);
            }*/
            //fscanf(fichier, "\n\n%c", chaine);
            //printf("%s", chaine);
            //fputs("%.2f\n%.2f\n%s", myTemp.exterieure, myTemp.interieure, chaine, fichier);
            
            fprintf(fichier, "%.2f\n%.2f\n", myTemp.exterieure, myTemp.interieure);
            //printf("%s", chaine);
            fclose(fichier);
            remove(".verrouData");
        }else{
            printf("Impossible d'ouvrir le fichier data.txt");
        }
    }else{
        printf("\n\n Le fichier data est déjà ouvert\n\n");
    }
}

