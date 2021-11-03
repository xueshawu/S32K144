/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 * 
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with  
 * the terms contained in the written license agreement between you and ArcCore, 
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as 
 * published by the Free Software Foundation and appearing in the file 
 * LICENSE.GPL included in the packaging of this file or here 
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/









#include "Dcm.h"




/*********************
 * DCM Configuration *
 *********************/

/*
 * DSP configurations
 */
const Dcm_DspType Dsp = {
        .DspDid = NULL_PTR,
        .DspDidInfo = NULL_PTR,
        .DspEcuReset = NULL_PTR,
        .DspPid = NULL_PTR,
        .DspReadDTC = NULL_PTR,
        .DspRequestControl = NULL_PTR,
        .DspRoutine = NULL_PTR,
        .DspRoutineInfo = NULL_PTR,
        .DspSecurity = NULL_PTR,
        .DspSession = NULL_PTR,
        .DspTestResultByObdmid = NULL_PTR,
        .DspVehInfo = NULL_PTR,
};


/*
 * DSD configurations
 */
const Dcm_DsdType Dsd = {
        .DsdServiceTable = NULL_PTR
};


/*
 * DSL configurations
 */
const Dcm_DslType Dsl = {
        .DslBuffer = NULL_PTR,
        .DslCallbackDCMRequestService = NULL_PTR,
        .DslDiagResp = NULL_PTR,
        .DslProtocol = NULL_PTR,
        .DslProtocolTiming = NULL_PTR,
};

/*
 * DCM configurations
 */
const Dcm_ConfigType DCM_Config = {
        .Dsp = &Dsp,
        .Dsd = &Dsd,
        .Dsl = &Dsl
};
