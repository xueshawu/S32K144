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
 * Crc_calculateCRC8H2F
 *
 * \brief Calculates the rest of a of a polynomial division: input is divided by the CRC8H1D = SAE J 1850 polynomial
 *
 * Description: Calculates the crc remainder of a data stream. Crc polynomial is CRC8H2F polynomial.
 * The crc calculation starts with an initial value, Crc_StartValue8.
 * The data stream is transmitted via pointer *Crc_DataPtr and is of length Crc_Length.
 * The crc remainder is modified by a XOR operation using the value CRC_XOR_VALUE8H2F.
 *
 * \param    Crc_DataPtr,      Pointer to start address of data block
 * \param    Crc_Length,       Length of data block to be calculated in bytes
 * \param    Crc_StartValue8   Start value when the algorithm starts
 * \return                     Remainder after polynomial division *const Crc_DataPtr / CRC8H1D
 **********************************************************************************************************************
 */

/*
 **********************************************************************************************************************
 * TABLE Version, Revision_2
 **********************************************************************************************************************
*/

#define CRC_START_SEC_CONST_8
#include "Crc_MemMap.h"
const uint8  CRC_8_H2F_Tbl[((uint16)CRC_8_H2F_TABLESIZE)] =
{
        /*    0: */    0x0u,     0x2fu,    0x5eu,    0x71u,    0xbcu,    0x93u,    0xe2u,    0xcdu,
        /*    8: */    0x57u,    0x78u,    0x9u,     0x26u,    0xebu,    0xc4u,    0xb5u,    0x9au,
        /*   16: */    0xaeu,    0x81u,    0xf0u,    0xdfu,    0x12u,    0x3du,    0x4cu,    0x63u,
        /*   24: */    0xf9u,    0xd6u,    0xa7u,    0x88u,    0x45u,    0x6au,    0x1bu,    0x34u,
        /*   32: */    0x73u,    0x5cu,    0x2du,    0x2u,     0xcfu,    0xe0u,    0x91u,    0xbeu,
        /*   40: */    0x24u,    0xbu,     0x7au,    0x55u,    0x98u,    0xb7u,    0xc6u,    0xe9u,
        /*   48: */    0xddu,    0xf2u,    0x83u,    0xacu,    0x61u,    0x4eu,    0x3fu,    0x10u,
        /*   56: */    0x8au,    0xa5u,    0xd4u,    0xfbu,    0x36u,    0x19u,    0x68u,    0x47u,
        /*   64: */    0xe6u,    0xc9u,    0xb8u,    0x97u,    0x5au,    0x75u,    0x4u,     0x2bu,
        /*   72: */    0xb1u,    0x9eu,    0xefu,    0xc0u,    0xdu,     0x22u,    0x53u,    0x7cu,
        /*   80: */    0x48u,    0x67u,    0x16u,    0x39u,    0xf4u,    0xdbu,    0xaau,    0x85u,
        /*   88: */    0x1fu,    0x30u,    0x41u,    0x6eu,    0xa3u,    0x8cu,    0xfdu,    0xd2u,
        /*   96: */    0x95u,    0xbau,    0xcbu,    0xe4u,    0x29u,    0x6u,     0x77u,    0x58u,
        /*  104: */    0xc2u,    0xedu,    0x9cu,    0xb3u,    0x7eu,    0x51u,    0x20u,    0xfu,
        /*  112: */    0x3bu,    0x14u,    0x65u,    0x4au,    0x87u,    0xa8u,    0xd9u,    0xf6u,
        /*  120: */    0x6cu,    0x43u,    0x32u,    0x1du,    0xd0u,    0xffu,    0x8eu,    0xa1u,
        /*  128: */    0xe3u,    0xccu,    0xbdu,    0x92u,    0x5fu,    0x70u,    0x1u,     0x2eu,
        /*  136: */    0xb4u,    0x9bu,    0xeau,    0xc5u,    0x8u,     0x27u,    0x56u,    0x79u,
        /*  144: */    0x4du,    0x62u,    0x13u,    0x3cu,    0xf1u,    0xdeu,    0xafu,    0x80u,
        /*  152: */    0x1au,    0x35u,    0x44u,    0x6bu,    0xa6u,    0x89u,    0xf8u,    0xd7u,
        /*  160: */    0x90u,    0xbfu,    0xceu,    0xe1u,    0x2cu,    0x3u,     0x72u,    0x5du,
        /*  168: */    0xc7u,    0xe8u,    0x99u,    0xb6u,    0x7bu,    0x54u,    0x25u,    0xau,
        /*  176: */    0x3eu,    0x11u,    0x60u,    0x4fu,    0x82u,    0xadu,    0xdcu,    0xf3u,
        /*  184: */    0x69u,    0x46u,    0x37u,    0x18u,    0xd5u,    0xfau,    0x8bu,    0xa4u,
        /*  192: */    0x5u,     0x2au,    0x5bu,    0x74u,    0xb9u,    0x96u,    0xe7u,    0xc8u,
        /*  200: */    0x52u,    0x7du,    0xcu,     0x23u,    0xeeu,    0xc1u,    0xb0u,    0x9fu,
        /*  208: */    0xabu,    0x84u,    0xf5u,    0xdau,    0x17u,    0x38u,    0x49u,    0x66u,
        /*  216: */    0xfcu,    0xd3u,    0xa2u,    0x8du,    0x40u,    0x6fu,    0x1eu,    0x31u,
        /*  224: */    0x76u,    0x59u,    0x28u,    0x7u,     0xcau,    0xe5u,    0x94u,    0xbbu,
        /*  232: */    0x21u,    0xeu,     0x7fu,    0x50u,    0x9du,    0xb2u,    0xc3u,    0xecu,
        /*  240: */    0xd8u,    0xf7u,    0x86u,    0xa9u,    0x64u,    0x4bu,    0x3au,    0x15u,
        /*  248: */    0x8fu,    0xa0u,    0xd1u,    0xfeu,    0x33u,    0x1cu,    0x6du,    0x42u
};
#define CRC_STOP_SEC_CONST_8
#include "Crc_MemMap.h"
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"

uint8 Crc_CalculateCRC8H2F(const uint8* Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8,
                           boolean Crc_IsFirstCall)
{
    uint32_least  index;
    uint8         crcTemp;
    uint8         result;


    if (Crc_IsFirstCall != FALSE)
    {
        crcTemp = CRC_INITIAL_VALUE8H2F;
    }
    else
    {
        crcTemp = Crc_StartValue8 ^ CRC_XOR_VALUE8H2F;
    }

    for (index = 0U; index < Crc_Length; ++index)
    {
        /* Impact of temporary rest on next crc rest */
        crcTemp ^= Crc_DataPtr[index];

        /* Next temporary crc rest */
        crcTemp  = CRC_8_H2F_Tbl[crcTemp];
    }
    result = crcTemp ^ CRC_XOR_VALUE8H2F;

    return (result);
}

#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

