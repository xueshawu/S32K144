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




#ifndef CANIF_CFG_SCHM_H
#define CANIF_CFG_SCHM_H

#include "SchM.h"

/* If the RTE code generation is Involved please include the below files */
#include "SchM_CanIf.h"
#include "SchM_Can.h"

/* The integrator shall implement the particular services SchM_Enter and SchM_Exit */

/* Since there is currently only one resource used, there is no need to consider the resource name */

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_TxBufAccessNoNest(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_TxBufAccessNoNest(void);

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_RxBufAccessNoNest(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_RxBufAccessNoNest(void);

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_ControllerState(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_ControllerState(void);

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_NewMsgRxWkpEvtNoNest(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_NewMsgRxWkpEvtNoNest(void);

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_TxRxNotifNoNest(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_TxRxNotifNoNest(void);

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_DynIdNoNest(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_DynIdNoNest(void);

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_PNPduStatusNoNest(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_PNPduStatusNoNest(void);

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_TxMuxing(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_TxMuxing(void);



LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_TxBufAccessNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_TxBufAccessNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
}


LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_RxBufAccessNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_RxBufAccessNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
}


LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_ControllerState(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_ControllerState(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
}


LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_NewMsgRxWkpEvtNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_NewMsgRxWkpEvtNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
}


LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_TxRxNotifNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_TxRxNotifNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
}


LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_DynIdNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_DynIdNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
}


LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_PNPduStatusNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_PNPduStatusNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
}


LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_TxMuxing(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
    /*NOTE: This lock shall ensure to disable TX-request and TX-confirmation interrupts since this is used in
     * CanIf_Transmit() and CanIf_TxConfirmation(); else it would affect the TX-multiplexing behaviour.*/
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_TxMuxing(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
}

#endif /* CANIF_CFG_SCHM_H */



