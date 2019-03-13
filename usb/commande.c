#include "commande.h"

void commande(FT_HANDLE ftHandle, float cmd){
    // if puissance = 0 OR puissance !=0
    // on écrit dans TxBuffer
    // on utilise FT_WRITE
    FT_STATUS ftStatus;
    DWORD BytesWritten = 1;
    char TxBuffer[256];// Contains data to write to device
    float puissance = (cmd/127)*100;
    ftStatus = FT_Open(0, &ftHandle);
    if(ftStatus != FT_OK) {
        // FT_Open failed
    }
    ftStatus = FT_Write(ftHandle, TxBuffer, sizeof(TxBuffer), &BytesWritten);
    if (ftStatus == FT_OK) {
        if((int)puissance==0){
            TxBuffer[0]= (int)cmd & 0x7F;
            TxBuffer[0] &= ~(1<<7);
        }else{
            TxBuffer[0]= (int)cmd & 0x7F;
            TxBuffer[0] |= (1<<7);
        }
        // FT_Write OK
    }else{
        // FT_Write Failed
    }
    printf("Value of TxBUFFER[0]:%d\n",TxBuffer[0]);
    FT_Close(ftHandle);
}

