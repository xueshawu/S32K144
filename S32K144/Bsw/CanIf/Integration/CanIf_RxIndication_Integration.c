/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */
#ifndef NOT_READY_FOR_TESTING_OR_DEPLOYMENT

#else
#warning The content of this file is a template which provides empty stubs. The content of this file must be completed by the integrator accordingly to project specific requirements
#endif /* NOT_READY_FOR_TESTING_OR_DEPLOYMENT */

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "CanIf_RxIndication_Integration.h"
#include "Std_Types.h"
#include "CanIf_Cbk.h"

/***************************************************************************************************
 Function name    : CanIf_RxIndication

 Description      : This service indicates a successful reception of a received CAN Rx LPDU
                      to the CanIf after passing all filters and validation checks. The actual handling
                      of received data is implemented in CanIf_RxIndication_Internal(), which is called
                      at the end of this function.
                    The function prototype can be changed using CANIF_RX_INDICATION_VERSION.
   For AR versions < 4.1, this API is used:
   FUNC(void, CANIF_CODE) CanIf_RxIndication(
                                             VAR(Can_HwHandleType, AUTOMATIC) Hrh,
                                             VAR(Can_IdType, AUTOMATIC) CanId,
                                             VAR(uint8, AUTOMATIC) CanDlc,
                                             P2CONST (uint8, AUTOMATIC, CANIF_APPL_DATA) CanSduPtr
                                            )
 \param       Hrh: ID of the corresponding Hardware Object
 \param       CanId: Standard/Extended CAN ID of CAN L-PDU that has been successfully received
 \param       CanDlc: Data Length Code (length of CAN L-PDU payload)
 \param       CanSduPtr: Pointer to received L-SDU (payload)

 \return      void

   For AR versions >= 4.1, this API is used:
   FUNC(void, CANIF_CODE) CanIf_RxIndication(
                                             P2CONST (Can_HwType, AUTOMATIC, CANIF_APPL_DATA) Mailbox,
                                             P2CONST (PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
                                            )
 \param       Mailbox: Identifies the HRH and its corresponding CAN Controller
 \param       PduInfoPtr: Pointer to the received L-PDU

 \return      void
 ***************************************************************************************************
 */

#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

#if(CANIF_RX_INDICATION_VERSION < 1)
FUNC(void, CANIF_CODE) CanIf_RxIndication(
                                                 VAR(Can_HwHandleType, AUTOMATIC) Hrh,
                                                 VAR(Can_IdType, AUTOMATIC) CanId,
                                                 VAR(uint8, AUTOMATIC) CanDlc,
                                                 P2CONST (uint8, AUTOMATIC, CANIF_APPL_DATA) CanSduPtr
                                          )
{
#elif(CANIF_RX_INDICATION_VERSION >= 1)
FUNC(void, CANIF_CODE) CanIf_RxIndication(
                                            P2CONST (Can_HwType, AUTOMATIC, CANIF_APPL_DATA) Mailbox,
                                            P2CONST (PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
                                         )
{
    VAR(Can_HwHandleType, AUTOMATIC) Hrh = (Can_HwHandleType)Mailbox->Hoh;
    VAR(Can_IdType, AUTOMATIC) CanId = (Can_IdType)Mailbox->CanId;
    VAR(uint8, AUTOMATIC) CanDlc = (uint8)PduInfoPtr->SduLength;
    P2CONST (uint8, AUTOMATIC, CANIF_APPL_DATA) CanSduPtr = (uint8*)PduInfoPtr->SduDataPtr;
#endif

/*
 * Below is the sample implementation for DLC remapping (from 4-bit DLC code to Can L-PDU length).
 * Some MCALs have this remapping already before calling CanIf_RxIndication. Therefore, please check carefully
 * if this remapping is required. Otherwise, remove this piece of code.
 */
//#if(CANIF_FD_SUPPORT == STD_ON)
//    const uint8 CAN_FD_LENGTH_MAPPING[]= {12U,16U,20U,24U,32U,48U,64U};
//
/* Perform the remapping if the DLC is larger than 8 bytes*/
//    if(CanDlc > 8)
//    {
//        CanDlc = CAN_FD_LENGTH_MAPPING[CanDlc-9];
//    }
//#endif
    CanIf_RxIndication_Internal(Hrh, CanId, CanDlc, CanSduPtr);

}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

