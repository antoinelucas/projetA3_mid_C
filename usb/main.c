#include "..\define.h"
#include "releve.h"
#include "commande.h"

int main(){
    FT_HANDLE descr;
    temp_t *temperature;
    temperature = malloc(1 * sizeof(temp_t));
    descr = initUSB();
    
    do{
        releve(temperature, descr);
        commande(descr,0);
    //temperature.exterieure, temperature.interieure =  releve();
    //temperature.exterieure = tempExtCelsius;
    //temperature.interieure = tempIntCelsius;
        printf("%.2f Celsius Ext\n", temperature->exterieure);
        printf("%.2f Celsius Int\n\n\n", temperature->interieure);
    }while(1);
    free(temperature);
    finUSB(descr);
    return 0;
}