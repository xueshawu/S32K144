/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Archie
 * @Date: 2020-04-19 14:28:17
 * @LastEditors: Archie
 * @LastEditTime: 2020-04-25 11:56:33
 */
/*因为数据类型定义的问题，MCAL相关的头文件必须在OS的头文件之前包含 */
#include "Dio.h"
#include "TaskEntity.h"

TASK(Task1)
{
  static Dio_LevelType ledBlue = STD_HIGH;
  Dio_WriteChannel(DioConf_DioChannel_Dio_Rgb_Blue, ledBlue);
  ledBlue = (Dio_LevelType)(!ledBlue);
}

TASK(Task2)
{

}