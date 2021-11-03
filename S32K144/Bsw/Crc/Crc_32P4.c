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

/**
 **********************************************************************************************************************
 * Crc_calculateCRC32P4
 *
 * \brief Calculates the remainder of a polynomial division: input is divided by the CRC32P4 polynomial
 *
 * Crc_CalculateCRC32P4 calculates the remainder of a polynomial divided by the crc polynomial with Hex-value
 * 0x1F4ACFB13.
 * Crc calculation starts with an initial value, Crc_StartValue32.
 * The Crc remainder is calculated over a reflected data stream *Crc_DataPtr of length Crc_Length.
 * Note, 0xC8DF352F is the reflected data stream of 0xF4ACFB13. 0xF4ACFB13 describes the truncated crc polynomial .
 * Thus, 0xC8DF352F is the reflected data stream of the truncated crc polynomial.
 * The result data are reflected, too.
 * At the end the remainder is manipulated by a XOR operation using the value CRC_XOR_VALUE32.
 *
 * \param    Crc_DataPtr,      Pointer to start address of data block
 * \param    Crc_Length,       Length of data block to be calculated in bytes
 * \param    Crc_StartValue32  Start value when the algorithm starts
 * \return                     Remainder after polynomial division *const Crc_DataPtr / CRC32P4
 **********************************************************************************************************************
 */
/*
 **********************************************************************************************************************
 * RUNTIME Version, Revision_2
 **********************************************************************************************************************
 */

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"


uint32 Crc_CalculateCRC32P4(const uint8* Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32,
                            boolean Crc_IsFirstCall)
{
    uint32_least  index;
    uint32        crcTemp;
    uint32        result;
    uint32        crcSave;
    uint8_least   bitPos;


    if (Crc_IsFirstCall != FALSE)
    {
        crcTemp = CRC_INITIAL_VALUE32P4;
    }
    else
    {
        crcTemp = Crc_StartValue32 ^ CRC_XOR_VALUE32P4;
    }

    for (index = 0U; index < Crc_Length; ++index)
    {
         /* Impact of temporary rest on next crc rest */
         crcTemp ^= Crc_DataPtr[index];

         for (bitPos = CRC_32P4_CHUNK; bitPos > 0U; bitPos--)
         {
               crcSave = crcTemp;
               crcTemp >>= 1U;

               /* Length of rest = order of crc polynomial, but reverted */
               if (0U != (crcSave & CRC_32P4_POLYNOMIAL_BITMASK))
               {
                   crcTemp ^= CRC_32P4_POLYNOMIAL;
               }
         }
    }
    result = crcTemp ^ CRC_XOR_VALUE32P4;

    return (result);
}

#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"
