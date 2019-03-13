#include "commande.h"

void commande(FT_HANDLE ftHandle, float cmd){
    // if puissance = 0 OR puissance !=0
    // on écrit dans TxBuffer
    // on utilise FT_WRITE
    FT_STATUS ftStatus;
    DWORD BytesWritten = 1;
    char TxBuffer[1];// Contains data to write to device
    printf("CMD : %f\n",cmd);
    TxBuffer[0] = cmd*1.27;
    printf("TxBuffer : %u\n",TxBuffer[0]);

    ftStatus = FT_Write(ftHandle, TxBuffer, sizeof(TxBuffer), &BytesWritten);
    if (ftStatus == FT_OK) {
        // FT_Write OK
    }else{
        // FT_Write Failed
    }
}