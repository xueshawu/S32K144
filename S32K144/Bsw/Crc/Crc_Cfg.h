/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.1
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



#ifndef CRC_CFG_H
#define CRC_CFG_H

/*
**********************************************************************************************************************
* Includes
**********************************************************************************************************************
*/

/*
**********************************************************************************************************************
* Defines/Macros
**********************************************************************************************************************
*/

/*
 * CRC modes
 */

#define CRC_8_H2F_TABLE 0
#define CRC_8_H2F_RUNTIME 1
#define CRC_8_H2F_HARDWARE 2

#define CRC_8_H2F_MODE      CRC_8H2F_TABLE

#define CRC_8_TABLE 0
#define CRC_8_RUNTIME 1
#define CRC_8_HARDWARE 2

#define CRC_8_MODE          CRC_8_TABLE

#define CRC_16_TABLE 0
#define CRC_16_RUNTIME 1
#define CRC_16_HARDWARE 2

#define CRC_16_MODE         CRC_16_TABLE

#define CRC_32_TABLE 0
#define CRC_32_RUNTIME 1
#define CRC_32_HARDWARE 2

#define CRC_32_MODE         CRC_32_TABLE

#define CRC_32P4_TABLE 0
#define CRC_32P4_RUNTIME 1
#define CRC_32P4_HARDWARE 2

#define CRC_32P4_MODE         CRC_32P4_RUNTIME
#define CRC_64_TABLE 0
#define CRC_64_RUNTIME 1
#define CRC_64_HARDWARE 2

#define CRC_64_MODE         CRC_64_TABLE

/*
 * Defines for supported hardware (only used if CRC calculation method HARDWARE is selected)
 */
#define CRC_HW_RH850_R1X        0
#define CRC_HW_RH850_P1X        0
#define CRC_SUPPORTED_HW_IFX    0
#define CRC_SUPPORTED_HW_JDP    0
#define CRC_SUPPORT_REFL_HW_JDP 0

/*
 * Revision of CRC
 */
#define CRC_AR_RELEASE_REVISION_VERSION  2


/*
**********************************************************************************************************************
* Type definitions
**********************************************************************************************************************
*/

/*
**********************************************************************************************************************
* Variables
**********************************************************************************************************************
*/


/*
**********************************************************************************************************************
* Extern declarations
**********************************************************************************************************************
*/

/* CRC_CFG_H */
#endif

