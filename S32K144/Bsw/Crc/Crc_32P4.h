/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.1
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



#ifndef CRC_32P4_H
#define CRC_32P4_H

/*
**********************************************************************************************************************
* Defines/Macros
**********************************************************************************************************************
*/
/* Initial values for CRC calculation */
#define CRC_INITIAL_VALUE32P4             ((uint32)0xFFFFFFFFUL)

/* XOR values for CRC result modification */
#define CRC_XOR_VALUE32P4                 ((uint32)0xFFFFFFFFUL)

/* Implementation specific define, used as well for TABLE as for RUNTIME version */
/* size of transmitted chunks via of the data stream */
#define  CRC_32P4_CHUNK ((uint8)8U)


/*
 **********************************************************************************************************************
 * RUNTIME Version
 **********************************************************************************************************************
 */
#define  CRC_32P4_POLYNOMIAL                  ((uint32)0xC8DF352FUL) /* truncated polynomial */
#define  CRC_32P4_POLYNOMIAL_BITMASK          ((uint32)1U)           /* crc polynomial of order 32 and reverse data stream */

/*
**********************************************************************************************************************
* Variables
**********************************************************************************************************************
*/



/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
extern uint32 Crc_CalculateCRC32P4(const uint8* Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32,
                                 boolean Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


/* CRC_32P4_H */
#endif
