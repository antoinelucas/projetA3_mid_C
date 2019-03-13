#include "commande.h"

void commande(FT_HANDLE ftHandle, float cmd){
    float puissance = (cmd/127)*100;
    // if puissance = 0 OR puissance !=0
    // on écrit dans TxBuffer
    // on utilise FT_WRITE
}