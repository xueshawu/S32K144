/*
 * NvM_Cfg.c
 *
 *  Created on: 2020-12-16
 *      Author: nieqi
 */
#include "NvM_Cfg.h"




NvM_Block_BswBlock_DataGroupType	NvM_Block_BswBlock_DataGroup_RAM;
NvM_Block_AswBlock_DataGroupType    NvM_Block_AwwBlock_DataGroup_RAM;

const NvM_BlockDescriptorType BlockDescriptorList[] =
{
    {	/* NVM_BLOCK_ID_AswBlock */
		.NvramBlockIdentifier = NVM_BLOCK_ID_AswBlock,
		.BlockManagementType = 	NVM_BLOCK_REDUNDANT,
		.BlockJobPriority = 0,		
		.BlockWriteProt = FALSE,			
		.WriteBlockOnce = FALSE,
		.SelectBlockForReadall = TRUE,
		.ResistantToChangesSw = FALSE,
		.SingleBlockCallback = NULL_PTR,
		.NvBlockLength = 512,	
		.BlockUseCrc = TRUE,	
		.BlockCRCType = NVM_CRC16,			
		.RamBlockDataAddress = (void *)(&NvM_Block_AwwBlock_DataGroup_RAM),
		.CalcRamBlockCrc = TRUE,		
		.NvBlockNum = 2,
		.NvramDeviceId = 0,
		.NvBlockBaseNumber = FeeConf_FeeBlockConfiguration_NvM_AswBlock,
		.RomBlockNum = 0, 			
		.RomBlockDataAdress = NULL_PTR,
		.InitBlockCallback = NULL_PTR,	
	},
    {	/* NVM_BLOCK_ID_BswBlock */
		.NvramBlockIdentifier = NVM_BLOCK_ID_BswBlock,
		.BlockManagementType = 	NVM_BLOCK_NATIVE,
		.BlockJobPriority = 0,		
		.BlockWriteProt = FALSE,			
		.WriteBlockOnce = FALSE,
		.SelectBlockForReadall = TRUE,
		.ResistantToChangesSw = FALSE,
		.SingleBlockCallback = NULL_PTR,
		.NvBlockLength = sizeof(NvM_Block_BswBlock_DataGroupType),	
		.BlockUseCrc = TRUE,	
		.BlockCRCType = NVM_CRC16,			
		.RamBlockDataAddress = (void *)&NvM_Block_BswBlock_DataGroup_RAM,
		.CalcRamBlockCrc = TRUE,		
		.NvBlockNum = 1,
		.NvramDeviceId = 0,
		.NvBlockBaseNumber = FeeConf_FeeBlockConfiguration_NvM_BswBlock,
		.RomBlockNum = 0, 			
		.RomBlockDataAdress = NULL_PTR,
		.InitBlockCallback = NULL_PTR,	
	},	
};

const NvM_ConfigType NvM_Config = {
    .Common = {
        .MultiBlockCallback = NULL,
    },
    .BlockDescriptor = BlockDescriptorList,
};
