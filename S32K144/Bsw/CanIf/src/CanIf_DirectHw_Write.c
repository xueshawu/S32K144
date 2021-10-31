

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
/*******************************************************************************************************************************************************************/
/* Function name    : CanIf_DirectHw_Write
   Syntax           : FUNC(Std_ReturnType, CANIF_CODE) CanIf_DirectHw_Write (P2VAR(uint32, AUTOMATIC, CANIF_APPL_DATA) p_tx_data_buff_u32,
                                                                             VAR(uint32, AUTOMATIC) data_len_u32,
                                                                             P2VAR(rba_CanDirectHWInfo_o, AUTOMATIC, CANIF_APPL_DATA) hw_info_po)
 Description      : This service initiates a request for direct HW write for CAN L-PDU specified by the CanTxPduId
 Parameter        : p_tx_data_buff_u32, data_len_u32, hw_info_pco
 Return value     : E_OK / E_NOT_OK

 Notes:
 - This is not an AUTOSAR function.
 - This function must be AS FAST AS POSSIBLE.
 - The only check perofmed is to avoid sending data while CAN Drv not confirmed "running"  (Device mode == STARTED)
   More background info:
    XCP is the only user of this. Not checking if CAN iF is "online" is acceptable because:
    - XCP is used only in diagnose environment (not in "drive software"
    - there are scenarios where the XCP diag data is actually expected as fast as possible,
    thus may actually be desirable to send before BSWM goes online
********************************************************************************************************************************************************************/
#if (CANIF_DIRECT_HW_WRITE == STD_ON)


#define CANIF_START_SEC_CODE_FAST
#include "CanIf_MemMap.h"
/* HIS METRIC COMF VIOLATION IN CanIf_DirectHw_Write: Function contains very simple "else if" statements and "switch-cases". HIS metric compliance would decrease readability and maintainability. */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_DirectHw_Write (P2CONST(uint32, AUTOMATIC, CANIF_APPL_DATA) p_tx_data_buff_u32,
    VAR(uint32, AUTOMATIC) data_len_u32,
    P2CONST(rba_CanDirectHWInfo_o, AUTOMATIC, CANIF_APPL_DATA) hw_info_po)
{
    VAR(uint8,AUTOMATIC) Controller;
    VAR (CanIf_ControllerModeType, AUTOMATIC) DeviceMode_Temp;
    VAR (Std_ReturnType, AUTOMATIC ) Status;

   /*Make a local copy of Device Mode. Try to get the CAN Drv controller state*/
    #if(CANIF_VARIANT_INFO == 1)
    Controller = CanIf_TxPduConfig[hw_info_po->swPduHandle].ControllerRefId;
    DeviceMode_Temp = CanIf_ControllerState[Controller].DeviceMode;
    #else
    Controller = CanIf_ConfigSetPtr->TxPduConfig[hw_info_po->swPduHandle].ControllerRefId;
    DeviceMode_Temp = CanIf_ConfigSetPtr->CtrlStatePtr[Controller].DeviceMode;
    #endif

  if (CANIF_CS_STARTED == DeviceMode_Temp)
    {
    Status = rba_Can_DirectHw_Write (p_tx_data_buff_u32, data_len_u32, hw_info_po);
    }
  else
  {
    Status = E_NOT_OK;
  }

    return Status;
}
#define CANIF_STOP_SEC_CODE_FAST
#include "CanIf_MemMap.h"

#endif

/* FC_FileVariationPoint_END */


