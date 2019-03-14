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
    int i=0;
    SPID *pid;
    pid = malloc(1 * sizeof(SPID));
    pid->valueI = 0;


    printf("TOR (1) or PID (2) ?\n");   // On demande à l'utilisateur de choisir entre le mode ToR ou PID
    scanf("%d", &regul);
    descr = initUSB(); // Initialise la connexion USB

    do{
        temperature = releve(temperature, descr);
        pid->newV = temperature.interieure;
        pid->newI = (csgn - temperature.interieure);
        visualisationT(temperature);
        csgn = consigne(csgn);
        cmd = regulation(regul, csgn, temperature.interieure, pid, i);
        visualisationC(cmd);
        commande(descr,cmd);

        printf("%.2f Celsius Ext\n", temperature.exterieure);
        printf("%.2f Celsius Int\n\n\n", temperature.interieure);
    }while( csgn > 5);
    free(pid);
    finUSB(descr);
    return 0;
}