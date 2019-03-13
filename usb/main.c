#include "..\define.h"

int main(){
    int tempExtBytes = 0;
    float tempExtCelsius = 0;
    int tempIntBytes = 0;
    float tempIntCelsius = 0;

    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    DWORD RxBytes = 6;
    DWORD BytesReceived;
    char RxBuffer[256];

    ftStatus = FT_Open(0, &ftHandle);
    if (ftStatus != FT_OK){
        // FT_Open failed  return; 
    }
    ftStatus = FT_Read(ftHandle, RxBuffer, RxBytes, &BytesReceived);
    if (ftStatus == FT_OK){
        if (BytesReceived == RxBytes){
            // FT_Read OK
            printf("%s\n", RxBuffer);
            printf("%d\n", sizeof(RxBuffer));
            

            switch (RxBuffer[0]){
                case (RxBuffer[0] & 0x0F):
                    tempExtBytes = ((RxBuffer[0] & 0b00001111) << 8) | ((RxBuffer[1] & 0b00001111) << 4) | (RxBuffer[2] & 0b00001111);
                    tempExtCelsius = -39.64 + 0.04 * tempExtBytes;
                    printf("%.2f Celsius\n", tempExtCelsius);

                    tempIntBytes = ((RxBuffer[3] & 0b00001111) << 8) | ((RxBuffer[4] & 0b00001111) << 4) | (RxBuffer[5] & 0b00001111);
                    tempIntCelsius = -39.64 + 0.04 * tempIntBytes;
                    printf("%.2f Celsius\n", tempIntCelsius);
                break;

                case (RxBuffer[0] & 0b00011111):
                    tempExtBytes = ((RxBuffer[5] & 0b00001111) << 8) | ((RxBuffer[0] & 0b00001111) << 4) | (RxBuffer[1] & 0b00001111);
                    tempExtCelsius = -39.64 + 0.04 * tempExtBytes;
                    printf("%.2f Celsius\n", tempExtCelsius);

                    tempIntBytes = ((RxBuffer[2] & 0b00001111) << 8) | ((RxBuffer[3] & 0b00001111) << 4) | (RxBuffer[4] & 0b00001111);
                    tempIntCelsius = -39.64 + 0.04 * tempIntBytes;
                    printf("%.2f Celsius\n", tempIntCelsius);
            }
        }
    }else{
        // FT_Read Failed
    }
    FT_Close(ftHandle);



    return 0;
}