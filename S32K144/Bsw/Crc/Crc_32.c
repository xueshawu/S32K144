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
 * Crc_calculateCRC32
 *
 * \brief Calculates the remainder of a polynomial division: input is divided by the CRC32H04C11DB7 polynomial
 *
 * Crc_calculateCRC32 calculates the remainder of a polynomial divided by the crc polynomial with Hex-value 0x104C11DB7.
 * Crc calculation starts with an initial value, Crc_StartValue32.
 * The Crc remainder is calculated over a reflected data stream *Crc_DataPtr of length Crc_Length.
 * Note, 0xEDB88320 is the reflected data stream of 0x04C11DB7. 0x04C11DB7 describes the truncated crc polynomial .
 * Thus, 0xEDB88320 is the reflected data stream of the truncated crc polynomial.
 * The result data are reflected, too.
 * At the end the remainder is manipulated by a XOR operation using the value CRC_XOR_VALUE32.
 *
 * \param    Crc_DataPtr,      Pointer to start address of data block
 * \param    Crc_Length,       Length of data block to be calculated in bytes
 * \param    Crc_StartValue32  Start value when the algorithm starts
 * \return                     Remainder after polynomial division *const Crc_DataPtr / CRC32
 **********************************************************************************************************************
 */
/*
 **********************************************************************************************************************
 * TABLE Version, Revision_2
 **********************************************************************************************************************
*/

#define CRC_START_SEC_CONST_32
#include "Crc_MemMap.h"
const uint32  CRC_32_REVH04C11DB7_Tbl[((uint16)CRC_32_TABLESIZE)] =
{
    /*  0:*/ 0x00000000uL, 0x77073096uL, 0xee0e612cuL, 0x990951bauL,
    /*  4:*/ 0x076dc419uL, 0x706af48fuL, 0xe963a535uL, 0x9e6495a3uL,
    /*  8:*/ 0x0edb8832uL, 0x79dcb8a4uL, 0xe0d5e91euL, 0x97d2d988uL,
    /*  8:*/ 0x09b64c2buL, 0x7eb17cbduL, 0xe7b82d07uL, 0x90bf1d91uL,
    /* 16:*/ 0x1db71064uL, 0x6ab020f2uL, 0xf3b97148uL, 0x84be41deuL,
    /* 20:*/ 0x1adad47duL, 0x6ddde4ebuL, 0xf4d4b551uL, 0x83d385c7uL,
    /* 24:*/ 0x136c9856uL, 0x646ba8c0uL, 0xfd62f97auL, 0x8a65c9ecuL,
    /* 28:*/ 0x14015c4fuL, 0x63066cd9uL, 0xfa0f3d63uL, 0x8d080df5uL,
    /* 32:*/ 0x3b6e20c8uL, 0x4c69105euL, 0xd56041e4uL, 0xa2677172uL,
    /* 36:*/ 0x3c03e4d1uL, 0x4b04d447uL, 0xd20d85fduL, 0xa50ab56buL,
    /* 40:*/ 0x35b5a8fauL, 0x42b2986cuL, 0xdbbbc9d6uL, 0xacbcf940uL,
    /* 44:*/ 0x32d86ce3uL, 0x45df5c75uL, 0xdcd60dcfuL, 0xabd13d59uL,
    /* 48:*/ 0x26d930acuL, 0x51de003auL, 0xc8d75180uL, 0xbfd06116uL,
    /* 52:*/ 0x21b4f4b5uL, 0x56b3c423uL, 0xcfba9599uL, 0xb8bda50fuL,
    /* 56:*/ 0x2802b89euL, 0x5f058808uL, 0xc60cd9b2uL, 0xb10be924uL,
    /* 60:*/ 0x2f6f7c87uL, 0x58684c11uL, 0xc1611dabuL, 0xb6662d3duL,
    /* 64:*/ 0x76dc4190uL, 0x01db7106uL, 0x98d220bcuL, 0xefd5102auL,
    /* 68:*/ 0x71b18589uL, 0x06b6b51fuL, 0x9fbfe4a5uL, 0xe8b8d433uL,
    /* 72:*/ 0x7807c9a2uL, 0x0f00f934uL, 0x9609a88euL, 0xe10e9818uL,
    /* 76:*/ 0x7f6a0dbbuL, 0x086d3d2duL, 0x91646c97uL, 0xe6635c01uL,
    /* 80:*/ 0x6b6b51f4uL, 0x1c6c6162uL, 0x856530d8uL, 0xf262004euL,
    /* 84:*/ 0x6c0695eduL, 0x1b01a57buL, 0x8208f4c1uL, 0xf50fc457uL,
    /* 88:*/ 0x65b0d9c6uL, 0x12b7e950uL, 0x8bbeb8eauL, 0xfcb9887cuL,
    /* 92:*/ 0x62dd1ddfuL, 0x15da2d49uL, 0x8cd37cf3uL, 0xfbd44c65uL,
    /* 96:*/ 0x4db26158uL, 0x3ab551ceuL, 0xa3bc0074uL, 0xd4bb30e2uL,
    /*100:*/ 0x4adfa541uL, 0x3dd895d7uL, 0xa4d1c46duL, 0xd3d6f4fbuL,
    /*104:*/ 0x4369e96auL, 0x346ed9fcuL, 0xad678846uL, 0xda60b8d0uL,
    /*108:*/ 0x44042d73uL, 0x33031de5uL, 0xaa0a4c5fuL, 0xdd0d7cc9uL,
    /*112:*/ 0x5005713cuL, 0x270241aauL, 0xbe0b1010uL, 0xc90c2086uL,
    /*116:*/ 0x5768b525uL, 0x206f85b3uL, 0xb966d409uL, 0xce61e49fuL,
    /*120:*/ 0x5edef90euL, 0x29d9c998uL, 0xb0d09822uL, 0xc7d7a8b4uL,
    /*124:*/ 0x59b33d17uL, 0x2eb40d81uL, 0xb7bd5c3buL, 0xc0ba6caduL,
    /*128:*/ 0xedb88320uL, 0x9abfb3b6uL, 0x03b6e20cuL, 0x74b1d29auL,
    /*132:*/ 0xead54739uL, 0x9dd277afuL, 0x04db2615uL, 0x73dc1683uL,
    /*136:*/ 0xe3630b12uL, 0x94643b84uL, 0x0d6d6a3euL, 0x7a6a5aa8uL,
    /*140:*/ 0xe40ecf0buL, 0x9309ff9duL, 0x0a00ae27uL, 0x7d079eb1uL,
    /*144:*/ 0xf00f9344uL, 0x8708a3d2uL, 0x1e01f268uL, 0x6906c2feuL,
    /*148:*/ 0xf762575duL, 0x806567cbuL, 0x196c3671uL, 0x6e6b06e7uL,
    /*152:*/ 0xfed41b76uL, 0x89d32be0uL, 0x10da7a5auL, 0x67dd4accuL,
    /*156:*/ 0xf9b9df6fuL, 0x8ebeeff9uL, 0x17b7be43uL, 0x60b08ed5uL,
    /*160:*/ 0xd6d6a3e8uL, 0xa1d1937euL, 0x38d8c2c4uL, 0x4fdff252uL,
    /*164:*/ 0xd1bb67f1uL, 0xa6bc5767uL, 0x3fb506dduL, 0x48b2364buL,
    /*168:*/ 0xd80d2bdauL, 0xaf0a1b4cuL, 0x36034af6uL, 0x41047a60uL,
    /*172:*/ 0xdf60efc3uL, 0xa867df55uL, 0x316e8eefuL, 0x4669be79uL,
    /*176:*/ 0xcb61b38cuL, 0xbc66831auL, 0x256fd2a0uL, 0x5268e236uL,
    /*180:*/ 0xcc0c7795uL, 0xbb0b4703uL, 0x220216b9uL, 0x5505262fuL,
    /*184:*/ 0xc5ba3bbeuL, 0xb2bd0b28uL, 0x2bb45a92uL, 0x5cb36a04uL,
    /*188:*/ 0xc2d7ffa7uL, 0xb5d0cf31uL, 0x2cd99e8buL, 0x5bdeae1duL,
    /*192:*/ 0x9b64c2b0uL, 0xec63f226uL, 0x756aa39cuL, 0x026d930auL,
    /*196:*/ 0x9c0906a9uL, 0xeb0e363fuL, 0x72076785uL, 0x05005713uL,
    /*200:*/ 0x95bf4a82uL, 0xe2b87a14uL, 0x7bb12baeuL, 0x0cb61b38uL,
    /*204:*/ 0x92d28e9buL, 0xe5d5be0duL, 0x7cdcefb7uL, 0x0bdbdf21uL,
    /*208:*/ 0x86d3d2d4uL, 0xf1d4e242uL, 0x68ddb3f8uL, 0x1fda836euL,
    /*212:*/ 0x81be16cduL, 0xf6b9265buL, 0x6fb077e1uL, 0x18b74777uL,
    /*216:*/ 0x88085ae6uL, 0xff0f6a70uL, 0x66063bcauL, 0x11010b5cuL,
    /*220:*/ 0x8f659effuL, 0xf862ae69uL, 0x616bffd3uL, 0x166ccf45uL,
    /*224:*/ 0xa00ae278uL, 0xd70dd2eeuL, 0x4e048354uL, 0x3903b3c2uL,
    /*228:*/ 0xa7672661uL, 0xd06016f7uL, 0x4969474duL, 0x3e6e77dbuL,
    /*232:*/ 0xaed16a4auL, 0xd9d65adcuL, 0x40df0b66uL, 0x37d83bf0uL,
    /*236:*/ 0xa9bcae53uL, 0xdebb9ec5uL, 0x47b2cf7fuL, 0x30b5ffe9uL,
    /*240:*/ 0xbdbdf21cuL, 0xcabac28auL, 0x53b39330uL, 0x24b4a3a6uL,
    /*244:*/ 0xbad03605uL, 0xcdd70693uL, 0x54de5729uL, 0x23d967bfuL,
    /*248:*/ 0xb3667a2euL, 0xc4614ab8uL, 0x5d681b02uL, 0x2a6f2b94uL,
    /*252:*/ 0xb40bbe37uL, 0xc30c8ea1uL, 0x5a05df1buL, 0x2d02ef8duL
};
#define CRC_STOP_SEC_CONST_32
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"




uint32 Crc_CalculateCRC32(const uint8* Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32,
                          boolean Crc_IsFirstCall)
{
    uint32_least  index;
    uint32        crcTemp;
    uint32        result;


    if (Crc_IsFirstCall != FALSE)
    {
        crcTemp = CRC_INITIAL_VALUE32;
    }
    else
    {
        crcTemp = Crc_StartValue32 ^ CRC_XOR_VALUE32;
    }

    for (index = 0U; index < Crc_Length; ++index)
    {
        /* Impact of temporary rest on next crc rest */
        crcTemp ^= Crc_DataPtr[index];

        crcTemp = (crcTemp >> ((uint8)CRC_32_REVH04C11DB7_JUNK)) ^
                   CRC_32_REVH04C11DB7_Tbl[crcTemp & ((uint8)CRC_32_TABLEMASK)];
    }
    result = crcTemp ^ CRC_XOR_VALUE32;

    return (result);
}

#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

