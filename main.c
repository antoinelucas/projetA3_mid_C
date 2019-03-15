#include "define.h"
#include "releve.h"
#include "commande.h"
#include "regulation.h"
#include "visualisationT.h"
#include "visualisationC.h"
#include "consigne.h"
#include "simulateur.h"


int main(){
    //Déclaration
    FT_HANDLE descr;
    temp_t temperature;
    float csgn, cmd = 0.0;
    int regul = 0;
    int i = 0;
    SPID *pid;
    pid = malloc(1 * sizeof(SPID));
    pid->valueI = 0;
    int mode_PID = 1;

    printf("TOR (1) or PID (2) ?\n");   // On demande à l'utilisateur de choisir entre le mode ToR ou PID
    scanf("%d", &regul);
    descr = initUSB(); // Initialise la connexion USB

    do{
        temperature = releve(temperature, descr);   // Récupère les valeurs de températures de la carte via USB
        pid->newV = temperature.interieure;     
        pid->newI = (csgn - temperature.interieure);
        visualisationT(temperature);    // Permet de mettre les températures dans le fichier data.txt
        csgn = consigne(csgn);          // Permet de récupérer la valeur de consigne du fichier consigne.txt
        cmd = regulation(regul, csgn, temperature.interieure, pid, i,mode_PID);  // Retourne la valeur de la puissance
        visualisationC(cmd);    // Ecrit dans data.txt si le chauffage est en route ou non
        commande(descr,cmd);    // Envoie la valeur de la puissance (en %) à la carte via USB

        printf("%.2f Celsius Ext\n", temperature.exterieure);
        printf("%.2f Celsius Int\n\n\n", temperature.interieure);
    }while( csgn > 5 && csgn < 40);

    free(pid);      // On libère l'espace réservé pour la structure SPID
    finUSB(descr);  // On ferme la liaison USB
    return 0;
}