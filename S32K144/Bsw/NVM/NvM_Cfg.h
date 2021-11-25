/*
 * NvM_Cfg.h
 *
 *  Created on: 2020-12-15
 *      Author: nieqi
 */

#ifndef NVM_CFG_H_
#define NVM_CFG_H_
#include "NvM_Types.h"
#include "NvM_ConfigTypes.h"
#include "Fee.h"
#include "Det.h"
#define NVM_DEV_ERROR_DETECT            STD_ON
#define NVM_VERSION_INFO_API            STD_ON
#define NVM_SET_RAM_BLOCK_STATUS_API    STD_OFF


#define NVM_API_CONFIG_CLASS            NVM_API_CONFIG_CLASS_3     // Class 1-3
#define NVM_COMPILED_CONFIG_ID          0                          // 0..65535
#define NVM_CRC_NUM_OF_BYTES            0                          // 1..65535
#define NVM_DATASET_SELECTION_BITS      0                          // 0..8
#define NVM_DRV_MODE_SWITCH             STD_OFF                    // OFF = SLOW, ON = FAST
#define NVM_DYNAMIC_CONFIGURATION       STD_OFF                    // OFF..ON
#define NVM_JOB_PRIORIZATION            STD_OFF                    // OFF..ON
#define NVM_MAX_NUMBER_OF_WRITE_RETRIES 2                          // 0..7
#define NVM_POLLING_MODE                STD_OFF                    // OFF..ON
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE    40                          // 1..255
#define NVM_SIZE_STANDARD_JOB_QUEUE     40                         // 1..255\n\n"""

/************** Block Id define ****************************/
#define NVM_BLOCK_ID_Admin              		0
#define NVM_BLOCK_ID_AswBlock           		1
#define NVM_BLOCK_ID_BswBlock           		2



#define NVM_NUM_OF_NVRAM_BLOCKS		2

/************** Block Types define ****************************/


typedef struct NvM_Cfg
{
    uint8 _BswRam[256];
}NvM_Block_BswBlock_DataGroupType;

typedef struct
{
    uint8 _BswRam[512];
}NvM_Block_AswBlock_DataGroupType;












#define NVM_MAX_BLOCK_LENGTH			2200




extern NvM_Block_BswBlock_DataGroupType	NvM_Block_BswBlock_DataGroup_RAM;




#define Rte_NvMReadBuffer(GroupName)    ((uint8*)&NvM_Block_##GroupName##_DataGroup_RAM)
#define Rte_NvMRead(GroupName,DataName) (NvM_Block_##GroupName##_DataGroup_RAM._##DataName)
#define Rte_NvMReadArrayBuffer(GroupName,DataName) ((uint8*)NvM_Block_##GroupName##_DataGroup_RAM._##DataName)
#define Rte_NvMReadArray(GroupName,DataName,Index) (NvM_Block_##GroupName##_DataGroup_RAM._##DataName[Index])

#define Rte_NvMReadBufferConst(GroupName)    ((uint8*)&NvM_Block_##GroupName##_DataGroup_ROM)
#define Rte_NvMReadConst(GroupName,DataName) (NvM_Block_##GroupName##_DataGroup_ROM._##DataName)
#define Rte_NvMReadArrayBufferConst(GroupName,DataName) ((uint8*)NvM_Block_##GroupName##_DataGroup_ROM._##DataName)
#define Rte_NvMReadArrayConst(GroupName,DataName,Index) (NvM_Block_##GroupName##_DataGroup_ROM._##DataName[Index])

#define Rte_NvMWrite(GroupName,DataName,Value) (NvM_Block_##GroupName##_DataGroup_RAM._##DataName = Value)
#define Rte_NvMWriteArray(GroupName,DataName,Index,Value) (NvM_Block_##GroupName##_DataGroup_RAM._##DataName[Index] = Value)

#define Rte_NvmWriteBlock(GroupName) NvM_WriteBlock(NVM_BLOCK_ID_##GroupName,(void*)&NvM_Block_##GroupName##_DataGroup_RAM)
#define Rte_NvmReadBlock(GroupName)  NvM_ReadBlock(NVM_BLOCK_ID_##GroupName,(void*)&NvM_Block_##GroupName##_DataGroup_RAM)


extern const NvM_BlockDescriptorType BlockDescriptorList[];


extern const NvM_ConfigType NvM_Config;




#endif /* NVM_CFG_H_ */
