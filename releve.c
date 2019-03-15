#include "releve.h"

 FT_HANDLE initUSB(){
    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    ftStatus = FT_Open(0, &ftHandle);   // On initialise la liaison USB
    return ftHandle;
}


temp_t releve(temp_t temperature, FT_HANDLE ftHandle){
    int tempExtBytes = 0;
    int tempIntBytes = 0;
    int octet1 = 0;
    FT_STATUS ftStatus;
    DWORD RxBytes = 6;     // On veut récupérer les 6 octets de la température extérieure et intérieure (format SOT) 
    DWORD BytesReceived;
    char RxBuffer[256];

    ftStatus = FT_Read(ftHandle, RxBuffer, RxBytes, &BytesReceived);
    if (ftStatus == FT_OK && BytesReceived == RxBytes){
        // FT_Read OK
        octet1 = RxBuffer[0] & 0xF0;    // On applique un masque à l'octet reçu afin de savoir quel octet à été reçu en premier
                                        // On masque les bits du formats SOT pour n'avoir plus que les bits formant le "mot clé"

        switch (octet1){  // On éffectue les décalages nécessaire afin de n'avoir que les 12 bits de SOT 
                          // On repère avant quel est le premier octet reçu de la liaison USB

            case 0x00:  // Si le premier octet reçu est l'octet 1 du format SOT
                tempExtBytes = ((RxBuffer[0] & 0b00001111) << 8) | ((RxBuffer[1] & 0b00001111) << 4) | (RxBuffer[2] & 0b00001111);
                tempIntBytes = ((RxBuffer[3] & 0b00001111) << 8) | ((RxBuffer[4] & 0b00001111) << 4) | (RxBuffer[5] & 0b00001111);
                break;

            case 0x10: // Si le premier octet reçu est l'octet 2 du format SOT
                tempExtBytes = ((RxBuffer[5] & 0b00001111) << 8) | ((RxBuffer[0] & 0b00001111) << 4) | (RxBuffer[1] & 0b00001111);
                tempIntBytes = ((RxBuffer[2] & 0b00001111) << 8) | ((RxBuffer[3] & 0b00001111) << 4) | (RxBuffer[4] & 0b00001111);
                break;

            case 0x20: // Si le premier octet reçu est l'octet 3 du format SOT
                tempExtBytes = ((RxBuffer[4] & 0b00001111) << 8) | ((RxBuffer[5] & 0b00001111) << 4) | (RxBuffer[0] & 0b00001111);
                tempIntBytes = ((RxBuffer[1] & 0b00001111) << 8) | ((RxBuffer[2] & 0b00001111) << 4) | (RxBuffer[3] & 0b00001111);
                break;

            case 0x80: // Si le premier octet reçu est l'octet 4 du format SOT
                tempExtBytes = ((RxBuffer[3] & 0b00001111) << 8) | ((RxBuffer[4] & 0b00001111) << 4) | (RxBuffer[5] & 0b00001111);
                tempIntBytes = ((RxBuffer[0] & 0b00001111) << 8) | ((RxBuffer[1] & 0b00001111) << 4) | (RxBuffer[2] & 0b00001111);
                break;

            case 0x90: // Si le premier octet reçu est l'octet 5 du format SOT
                tempExtBytes = ((RxBuffer[2] & 0b00001111) << 8) | ((RxBuffer[3] & 0b00001111) << 4) | (RxBuffer[4] & 0b00001111);
                tempIntBytes = ((RxBuffer[5] & 0b00001111) << 8) | ((RxBuffer[0] & 0b00001111) << 4) | (RxBuffer[1] & 0b00001111);
                break;

            case 0xA0: // Si le premier octet reçu est l'octet 6 du format SOT
                tempExtBytes = ((RxBuffer[1] & 0b00001111) << 8) | ((RxBuffer[2] & 0b00001111) << 4) | (RxBuffer[3] & 0b00001111);
                tempIntBytes = ((RxBuffer[4] & 0b00001111) << 8) | ((RxBuffer[5] & 0b00001111) << 4) | (RxBuffer[0] & 0b00001111);
                break;
            
            default:    
                tempExtBytes = 0x00;
                tempIntBytes = 0x00;
                break;
        }
        temperature.exterieure = -39.64 + 0.04 * tempExtBytes;  // Convertion de la température du format SOT en degré celsius
        temperature.interieure = -39.64 + 0.04 * tempIntBytes;
    }
    return temperature;    // On retourne 
}

void finUSB(FT_HANDLE ftHandle){
    FT_Close(ftHandle);     // On cloture la liaison USB
}