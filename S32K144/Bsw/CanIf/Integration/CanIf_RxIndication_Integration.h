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

#ifndef CANIF_RX_INDICATION_MCAL_VERSION_H
#define CANIF_RX_INDICATION_MCAL_VERSION_H
/*
 ********************************************************************************************************
 * The Integrator must define here which Autosar minor version is used									*
 * This will determine which API is used for CanIf_RxIndication()										*
 * For AR versions < 4.1, this API is used:															*
 * FUNC(void, CANIF_CODE) CanIf_RxIndication(															*
 *                                           VAR(Can_HwHandleType, AUTOMATIC) Hrh,						*
 *                                           VAR(Can_IdType, AUTOMATIC) CanId,							*
 *                                           VAR(uint8, AUTOMATIC) CanDlc,								*
 *                                           P2CONST (uint8, AUTOMATIC, CANIF_APPL_DATA) CanSduPtr		*
 *                                           )															*
 * For AR versions >= 4.1, this API is used:															*
 * FUNC(void, CANIF_CODE) CanIf_RxIndication(															*
 *                                        P2CONST (Can_HwType, AUTOMATIC, CANIF_APPL_DATA) Mailbox,		*
 *                                        P2CONST (PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr	*
 *                                           )															*
 ********************************************************************************************************
*/

/*
 *  Set the MCAL minor release version here.
 *  Example:
 *  For AR 4.0.3, the minor version is 0U
 *  For AR 4.2.2, the minor version is 2U
 *  Default is CAN_AR_RELEASE_MINOR_VERSION
*/
#define CANIF_RX_INDICATION_VERSION (1U)

#include "CanIf.h"

#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

#if(CANIF_RX_INDICATION_VERSION < 1)
extern FUNC(void, CANIF_CODE) CanIf_RxIndication(
                                                 VAR(Can_HwHandleType, AUTOMATIC) Hrh,
                                                 VAR(Can_IdType, AUTOMATIC) CanId,
                                                 VAR(uint8, AUTOMATIC) CanDlc,
                                                 P2CONST (uint8, AUTOMATIC, CANIF_APPL_DATA) CanSduPtr
                                                );
#elif(CANIF_RX_INDICATION_VERSION >= 1)
extern FUNC(void, CANIF_CODE) CanIf_RxIndication(
                                            P2CONST (Can_HwType, AUTOMATIC, CANIF_APPL_DATA) Mailbox,
                                            P2CONST (PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
                                         );
#endif

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#endif /* CANIF_RX_INDICATION_MCAL_VERSION_H */
