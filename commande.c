#include "commande.h"

void commande(FT_HANDLE ftHandle, float cmd){
    // if puissance = 0 OR puissance !=0
    // on écrit dans TxBuffer
    // on utilise FT_WRITE
    FT_STATUS ftStatus;
    DWORD BytesWritten = 1;
    char TxBuffer[1];           // Contient les valeurs à écrire sur la carte
    printf("CMD : %f\n",cmd);   // Affiche la valeur de la puissance 
    TxBuffer[0] = (cmd / 127) * 100;     // Permet d'avoir la valeur de la puissance
    printf("TxBuffer : %u\n",TxBuffer[0]);  // Affiche la valeur que l'on envoie à la carte

    ftStatus = FT_Write(ftHandle, TxBuffer, sizeof(TxBuffer), &BytesWritten);
}