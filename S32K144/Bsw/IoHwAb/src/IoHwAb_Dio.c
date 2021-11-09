#include "IoHwAb_Dio.h"


void IoHwAb_Dio_MainFunction(void)
{
    static Dio_LevelType regBuledLed_Level = STD_LOW;
    Dio_WriteChannel(DioConf_DioChannel_Dio_Rgb_Blue, regBuledLed_Level);
    regBuledLed_Level = !regBuledLed_Level;
}