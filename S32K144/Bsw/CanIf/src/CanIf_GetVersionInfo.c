

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "CanIf_Priv.h"

/*
 ***************************************************************************************************
 * used functions
 ***************************************************************************************************
 */
/**************************************************************************************************/
/* Function name    : CanIf_GetVersionInfo                                                        */
/* Syntax           : FUNC(void, CANIF_CODE) CanIf_GetVersionInfo(Std_VersionInfoType *VersionInfo)                 */
/* Description      : This service returns the version information of this module.                */
/* Parameter        : VersionInfo                                                                 */
/* Return value     : None                                                                        */
/**************************************************************************************************/
#if (CANIF_VERSION_INFO_API != STD_OFF)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* HIS METRIC COMF VIOLATION IN CanIf_GetVersionInfo: Function contains very simple "else if" statements and "switch-cases". HIS metric compliance would decrease readability and maintainability. */
FUNC(void, CANIF_CODE) CanIf_GetVersionInfo (P2VAR(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_DATA) VersionInfo)
{

    /*Report DET error if Null pointer is passed as a parametre*/
    CANIF_DET_REPORT_ERROR(VersionInfo == NULL_PTR,CANIF_GET_VERSION_INFO_SID,CANIF_E_PARAM_POINTER)

    VersionInfo->vendorID = CANIF_VENDOR_ID;
    VersionInfo->moduleID = CANIF_MODULE_ID;
    VersionInfo->sw_major_version = CANIF_SW_MAJOR_VERSION;
    VersionInfo->sw_minor_version = CANIF_SW_MINOR_VERSION;
    VersionInfo->sw_patch_version = CANIF_SW_PATCH_VERSION;

} /*End of CanIf_GetVersionInfo( ) */

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif


