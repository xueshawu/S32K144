/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.1
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Crc.h"

/*
 ***********************************************************************************************************************
 * Crc common routines
 ***********************************************************************************************************************
 */

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
void Crc_GetVersionInfo(Std_VersionInfoType * const VersionInfo)
{
     VersionInfo->vendorID         = ((uint16)CRC_VENDOR_ID);
     VersionInfo->moduleID         = ((uint16)CRC_MODULE_ID);
     VersionInfo->sw_major_version = ((uint8)CRC_SW_MAJOR_VERSION);
     VersionInfo->sw_minor_version = ((uint8)CRC_SW_MINOR_VERSION);
     VersionInfo->sw_patch_version = ((uint8)CRC_SW_PATCH_VERSION);
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

