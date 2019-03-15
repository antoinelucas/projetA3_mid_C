#include "simulateur.h"
#include "consigne.h"
#include "visualisationT.h"
#include "visualisationC.h"
#include "define.h"
#include "regulation.h"
#include "integration.h"

#define CONSIGNE 0

int main(){
	temp_t temperature;
	temperature.exterieure = 14.0;
	temperature.interieure = 16.0;

	integrationTest(2,temperature,100);
	
	return EXIT_SUCCESS;
}
