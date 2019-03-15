#include "visualisationT.h"

void visualisationT(temp_t myTemp){
    FILE *fichier, *verrouFile = NULL;
    float tempExt, tempInt;
    char *chaine = malloc(8 * sizeof(char));    // On alloue de la mémoire à la chaine de caractère

    if (access(".verrouData", F_OK) == -1){     // On vérifie que le fichier data.txt est pas déjà en lecture
        verrouFile = fopen(".verrouData", "w"); // Crée le fichier .verrouData afin de signifier que le fichier data.txt est en utilisation

        fichier = fopen("data.txt", "r");       // Permet d'ouvrir le fichier data.txt en lecture seule
        if (fichier != NULL){
            fscanf(fichier, "%f%f%s", &tempExt, &tempInt, chaine); // On récupère les valeurs déjà écrite dans data.txt
            fclose(fichier);
        }

        fichier = fopen("data.txt", "w");      // Permet d'ouvrir le fichier data.txt en écriture
        if (fichier != NULL){
            fprintf(fichier, "%.2f\n%.2f\n%s", myTemp.exterieure, myTemp.interieure, chaine);   // On écrit les valeurs de température et la valeur du chauffage qui était déjà écrit dans le fichier
            fclose(fichier);
        }
        fclose(verrouFile);
        remove(".verrouData"); // On enlève le verrou
        free(chaine);          // On libère l'espace alloué
    }
}