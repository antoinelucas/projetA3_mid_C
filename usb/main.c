#include "..\define.h"
#include "releve.h"

int main(){
    FT_HANDLE descr;
    temp_t *temperature;
    temperature = malloc(1 * sizeof(temp_t));
    descr = initUSB();
    releve(temperature, descr);
    //temperature.exterieure, temperature.interieure =  releve();
    //temperature.exterieure = tempExtCelsius;
    //temperature.interieure = tempIntCelsius;
    printf("%.2f Celsius\n", temperature->exterieure);
    printf("%.2f Celsius\n", temperature->interieure);
    free(temperature);
    finUSB(descr);
    return 0;
}