#include "releve.h"

 FT_HANDLE initUSB(){
    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    ftStatus = FT_Open(0, &ftHandle);
    if (ftStatus != FT_OK){
        // FT_Open failed  return;
    }
    return ftHandle;
}


void releve(temp_t *temperature, FT_HANDLE ftHandle){
    int tempExtBytes = 0;
    float tempExtCelsius = 0;
    int tempIntBytes = 0;
    float tempIntCelsius = 0;
    int octet1 = 0;
    FT_STATUS ftStatus;
    DWORD RxBytes = 6;
    DWORD BytesReceived;
    char RxBuffer[256];

    ftStatus = FT_Read(ftHandle, RxBuffer, RxBytes, &BytesReceived);
    if (ftStatus == FT_OK){
        if (BytesReceived == RxBytes){
            // FT_Read OK
            octet1 = RxBuffer[0] & 0xF0;

            switch (octet1){

            case 0x00:
                tempExtBytes = ((RxBuffer[0] & 0b00001111) << 8) | ((RxBuffer[1] & 0b00001111) << 4) | (RxBuffer[2] & 0b00001111);
                tempExtCelsius = -39.64 + 0.04 * tempExtBytes;

                tempIntBytes = ((RxBuffer[3] & 0b00001111) << 8) | ((RxBuffer[4] & 0b00001111) << 4) | (RxBuffer[5] & 0b00001111);
                tempIntCelsius = -39.64 + 0.04 * tempIntBytes;
                break;

            case 0x10:
                tempExtBytes = ((RxBuffer[5] & 0b00001111) << 8) | ((RxBuffer[0] & 0b00001111) << 4) | (RxBuffer[1] & 0b00001111);
                tempExtCelsius = -39.64 + 0.04 * tempExtBytes;

                tempIntBytes = ((RxBuffer[2] & 0b00001111) << 8) | ((RxBuffer[3] & 0b00001111) << 4) | (RxBuffer[4] & 0b00001111);
                tempIntCelsius = -39.64 + 0.04 * tempIntBytes;
                break;

            case 0x20:
                tempExtBytes = ((RxBuffer[4] & 0b00001111) << 8) | ((RxBuffer[5] & 0b00001111) << 4) | (RxBuffer[0] & 0b00001111);
                tempExtCelsius = -39.64 + 0.04 * tempExtBytes;

                tempIntBytes = ((RxBuffer[1] & 0b00001111) << 8) | ((RxBuffer[2] & 0b00001111) << 4) | (RxBuffer[3] & 0b00001111);
                tempIntCelsius = -39.64 + 0.04 * tempIntBytes;
                break;

            case 0x80:
                tempExtBytes = ((RxBuffer[3] & 0b00001111) << 8) | ((RxBuffer[4] & 0b00001111) << 4) | (RxBuffer[5] & 0b00001111);
                tempExtCelsius = -39.64 + 0.04 * tempExtBytes;

                tempIntBytes = ((RxBuffer[0] & 0b00001111) << 8) | ((RxBuffer[1] & 0b00001111) << 4) | (RxBuffer[2] & 0b00001111);
                tempIntCelsius = -39.64 + 0.04 * tempIntBytes;
                break;

            case 0x90:
                tempExtBytes = ((RxBuffer[2] & 0b00001111) << 8) | ((RxBuffer[3] & 0b00001111) << 4) | (RxBuffer[4] & 0b00001111);
                tempExtCelsius = -39.64 + 0.04 * tempExtBytes;

                tempIntBytes = ((RxBuffer[5] & 0b00001111) << 8) | ((RxBuffer[0] & 0b00001111) << 4) | (RxBuffer[1] & 0b00001111);
                tempIntCelsius = -39.64 + 0.04 * tempIntBytes;
                break;

            case 0xA0:
                tempExtBytes = ((RxBuffer[1] & 0b00001111) << 8) | ((RxBuffer[2] & 0b00001111) << 4) | (RxBuffer[3] & 0b00001111);
                tempExtCelsius = -39.64 + 0.04 * tempExtBytes;

                tempIntBytes = ((RxBuffer[4] & 0b00001111) << 8) | ((RxBuffer[5] & 0b00001111) << 4) | (RxBuffer[0] & 0b00001111);
                tempIntCelsius = -39.64 + 0.04 * tempIntBytes;
                break;
            }
            temperature->exterieure = tempExtCelsius;
            temperature->interieure = tempIntCelsius;
        }
    }
    else{
        // FT_Read Failed
    }
}

void finUSB(FT_HANDLE ftHandle){
    FT_Close(ftHandle);
}