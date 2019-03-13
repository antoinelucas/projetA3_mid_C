#include "..\define.h"
#include "releve.h"

int main(){
    temp_t *temperature;
    temperature = malloc(1 * sizeof(temp_t));
    releve(temperature);
    //temperature.exterieure, temperature.interieure =  releve();
    //temperature.exterieure = tempExtCelsius;
    //temperature.interieure = tempIntCelsius;
    printf("%.2f Celsius\n", temperature->exterieure);
    printf("%.2f Celsius\n", temperature->interieure);
    free(temperature);
    return 0;
}