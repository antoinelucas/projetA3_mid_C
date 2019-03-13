#include "..\define.h"
#include "releve.h"

int main(){
    temp_t *temperature;
    temperature = malloc(1 * sizeof(temp_t));
    FT_HANDLE ftHandle;
    releve(temperature);
    commande(ftHandle,127);
    //temperature.exterieure, temperature.interieure =  releve();
    //temperature.exterieure = tempExtCelsius;
    //temperature.interieure = tempIntCelsius;
    printf("%.2f Celsius\n", temperature->exterieure);
    printf("%.2f Celsius\n", temperature->interieure);
    free(temperature);
    return 0;
}