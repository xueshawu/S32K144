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

/*
 **********************************************************************************************************************
 * TABLE Version
 **********************************************************************************************************************
 */

#define CRC_START_SEC_CONST_64
#include "Crc_MemMap.h"
const uint64 CRC_64_REV_ECMA182_Tbl[CRC_64_TABLESIZE] =
{
    /*  0:*/ 0x0000000000000000ULL, 0xb32e4cbe03a75f6fULL, 0xf4843657a840a05bULL, 0x47aa7ae9abe7ff34ULL,
    /*  4:*/ 0x7bd0c384ff8f5e33ULL, 0xc8fe8f3afc28015cULL, 0x8f54f5d357cffe68ULL, 0x3c7ab96d5468a107ULL,
    /*  8:*/ 0xf7a18709ff1ebc66ULL, 0x448fcbb7fcb9e309ULL, 0x0325b15e575e1c3dULL, 0xb00bfde054f94352ULL,
    /* 12:*/ 0x8c71448d0091e255ULL, 0x3f5f08330336bd3aULL, 0x78f572daa8d1420eULL, 0xcbdb3e64ab761d61ULL,
    /* 16:*/ 0x7d9ba13851336649ULL, 0xceb5ed8652943926ULL, 0x891f976ff973c612ULL, 0x3a31dbd1fad4997dULL,
    /* 20:*/ 0x064b62bcaebc387aULL, 0xb5652e02ad1b6715ULL, 0xf2cf54eb06fc9821ULL, 0x41e11855055bc74eULL,
    /* 24:*/ 0x8a3a2631ae2dda2fULL, 0x39146a8fad8a8540ULL, 0x7ebe1066066d7a74ULL, 0xcd905cd805ca251bULL,
    /* 28:*/ 0xf1eae5b551a2841cULL, 0x42c4a90b5205db73ULL, 0x056ed3e2f9e22447ULL, 0xb6409f5cfa457b28ULL,
    /* 32:*/ 0xfb374270a266cc92ULL, 0x48190ecea1c193fdULL, 0x0fb374270a266cc9ULL, 0xbc9d3899098133a6ULL,
    /* 36:*/ 0x80e781f45de992a1ULL, 0x33c9cd4a5e4ecdceULL, 0x7463b7a3f5a932faULL, 0xc74dfb1df60e6d95ULL,
    /* 40:*/ 0x0c96c5795d7870f4ULL, 0xbfb889c75edf2f9bULL, 0xf812f32ef538d0afULL, 0x4b3cbf90f69f8fc0ULL,
    /* 44:*/ 0x774606fda2f72ec7ULL, 0xc4684a43a15071a8ULL, 0x83c230aa0ab78e9cULL, 0x30ec7c140910d1f3ULL,
    /* 48:*/ 0x86ace348f355aadbULL, 0x3582aff6f0f2f5b4ULL, 0x7228d51f5b150a80ULL, 0xc10699a158b255efULL,
    /* 52:*/ 0xfd7c20cc0cdaf4e8ULL, 0x4e526c720f7dab87ULL, 0x09f8169ba49a54b3ULL, 0xbad65a25a73d0bdcULL,
    /* 56:*/ 0x710d64410c4b16bdULL, 0xc22328ff0fec49d2ULL, 0x85895216a40bb6e6ULL, 0x36a71ea8a7ace989ULL,
    /* 60:*/ 0x0adda7c5f3c4488eULL, 0xb9f3eb7bf06317e1ULL, 0xfe5991925b84e8d5ULL, 0x4d77dd2c5823b7baULL,
    /* 64:*/ 0x64b62bcaebc387a1ULL, 0xd7986774e864d8ceULL, 0x90321d9d438327faULL, 0x231c512340247895ULL,
    /* 68:*/ 0x1f66e84e144cd992ULL, 0xac48a4f017eb86fdULL, 0xebe2de19bc0c79c9ULL, 0x58cc92a7bfab26a6ULL,
    /* 72:*/ 0x9317acc314dd3bc7ULL, 0x2039e07d177a64a8ULL, 0x67939a94bc9d9b9cULL, 0xd4bdd62abf3ac4f3ULL,
    /* 76:*/ 0xe8c76f47eb5265f4ULL, 0x5be923f9e8f53a9bULL, 0x1c4359104312c5afULL, 0xaf6d15ae40b59ac0ULL,
    /* 80:*/ 0x192d8af2baf0e1e8ULL, 0xaa03c64cb957be87ULL, 0xeda9bca512b041b3ULL, 0x5e87f01b11171edcULL,
    /* 84:*/ 0x62fd4976457fbfdbULL, 0xd1d305c846d8e0b4ULL, 0x96797f21ed3f1f80ULL, 0x2557339fee9840efULL,
    /* 88:*/ 0xee8c0dfb45ee5d8eULL, 0x5da24145464902e1ULL, 0x1a083bacedaefdd5ULL, 0xa9267712ee09a2baULL,
    /* 92:*/ 0x955cce7fba6103bdULL, 0x267282c1b9c65cd2ULL, 0x61d8f8281221a3e6ULL, 0xd2f6b4961186fc89ULL,
    /* 96:*/ 0x9f8169ba49a54b33ULL, 0x2caf25044a02145cULL, 0x6b055fede1e5eb68ULL, 0xd82b1353e242b407ULL,
    /*100:*/ 0xe451aa3eb62a1500ULL, 0x577fe680b58d4a6fULL, 0x10d59c691e6ab55bULL, 0xa3fbd0d71dcdea34ULL,
    /*104:*/ 0x6820eeb3b6bbf755ULL, 0xdb0ea20db51ca83aULL, 0x9ca4d8e41efb570eULL, 0x2f8a945a1d5c0861ULL,
    /*108:*/ 0x13f02d374934a966ULL, 0xa0de61894a93f609ULL, 0xe7741b60e174093dULL, 0x545a57dee2d35652ULL,
    /*112:*/ 0xe21ac88218962d7aULL, 0x5134843c1b317215ULL, 0x169efed5b0d68d21ULL, 0xa5b0b26bb371d24eULL,
    /*116:*/ 0x99ca0b06e7197349ULL, 0x2ae447b8e4be2c26ULL, 0x6d4e3d514f59d312ULL, 0xde6071ef4cfe8c7dULL,
    /*120:*/ 0x15bb4f8be788911cULL, 0xa6950335e42fce73ULL, 0xe13f79dc4fc83147ULL, 0x521135624c6f6e28ULL,
    /*124:*/ 0x6e6b8c0f1807cf2fULL, 0xdd45c0b11ba09040ULL, 0x9aefba58b0476f74ULL, 0x29c1f6e6b3e0301bULL,
    /*128:*/ 0xc96c5795d7870f42ULL, 0x7a421b2bd420502dULL, 0x3de861c27fc7af19ULL, 0x8ec62d7c7c60f076ULL,
    /*132:*/ 0xb2bc941128085171ULL, 0x0192d8af2baf0e1eULL, 0x4638a2468048f12aULL, 0xf516eef883efae45ULL,
    /*136:*/ 0x3ecdd09c2899b324ULL, 0x8de39c222b3eec4bULL, 0xca49e6cb80d9137fULL, 0x7967aa75837e4c10ULL,
    /*140:*/ 0x451d1318d716ed17ULL, 0xf6335fa6d4b1b278ULL, 0xb199254f7f564d4cULL, 0x02b769f17cf11223ULL,
    /*144:*/ 0xb4f7f6ad86b4690bULL, 0x07d9ba1385133664ULL, 0x4073c0fa2ef4c950ULL, 0xf35d8c442d53963fULL,
    /*148:*/ 0xcf273529793b3738ULL, 0x7c0979977a9c6857ULL, 0x3ba3037ed17b9763ULL, 0x888d4fc0d2dcc80cULL,
    /*152:*/ 0x435671a479aad56dULL, 0xf0783d1a7a0d8a02ULL, 0xb7d247f3d1ea7536ULL, 0x04fc0b4dd24d2a59ULL,
    /*156:*/ 0x3886b22086258b5eULL, 0x8ba8fe9e8582d431ULL, 0xcc0284772e652b05ULL, 0x7f2cc8c92dc2746aULL,
    /*160:*/ 0x325b15e575e1c3d0ULL, 0x8175595b76469cbfULL, 0xc6df23b2dda1638bULL, 0x75f16f0cde063ce4ULL,
    /*164:*/ 0x498bd6618a6e9de3ULL, 0xfaa59adf89c9c28cULL, 0xbd0fe036222e3db8ULL, 0x0e21ac88218962d7ULL,
    /*168:*/ 0xc5fa92ec8aff7fb6ULL, 0x76d4de52895820d9ULL, 0x317ea4bb22bfdfedULL, 0x8250e80521188082ULL,
    /*172:*/ 0xbe2a516875702185ULL, 0x0d041dd676d77eeaULL, 0x4aae673fdd3081deULL, 0xf9802b81de97deb1ULL,
    /*176:*/ 0x4fc0b4dd24d2a599ULL, 0xfceef8632775faf6ULL, 0xbb44828a8c9205c2ULL, 0x086ace348f355aadULL,
    /*180:*/ 0x34107759db5dfbaaULL, 0x873e3be7d8faa4c5ULL, 0xc094410e731d5bf1ULL, 0x73ba0db070ba049eULL,
    /*184:*/ 0xb86133d4dbcc19ffULL, 0x0b4f7f6ad86b4690ULL, 0x4ce50583738cb9a4ULL, 0xffcb493d702be6cbULL,
    /*188:*/ 0xc3b1f050244347ccULL, 0x709fbcee27e418a3ULL, 0x3735c6078c03e797ULL, 0x841b8ab98fa4b8f8ULL,
    /*192:*/ 0xadda7c5f3c4488e3ULL, 0x1ef430e13fe3d78cULL, 0x595e4a08940428b8ULL, 0xea7006b697a377d7ULL,
    /*196:*/ 0xd60abfdbc3cbd6d0ULL, 0x6524f365c06c89bfULL, 0x228e898c6b8b768bULL, 0x91a0c532682c29e4ULL,
    /*200:*/ 0x5a7bfb56c35a3485ULL, 0xe955b7e8c0fd6beaULL, 0xaeffcd016b1a94deULL, 0x1dd181bf68bdcbb1ULL,
    /*204:*/ 0x21ab38d23cd56ab6ULL, 0x9285746c3f7235d9ULL, 0xd52f0e859495caedULL, 0x6601423b97329582ULL,
    /*208:*/ 0xd041dd676d77eeaaULL, 0x636f91d96ed0b1c5ULL, 0x24c5eb30c5374ef1ULL, 0x97eba78ec690119eULL,
    /*212:*/ 0xab911ee392f8b099ULL, 0x18bf525d915feff6ULL, 0x5f1528b43ab810c2ULL, 0xec3b640a391f4fadULL,
    /*216:*/ 0x27e05a6e926952ccULL, 0x94ce16d091ce0da3ULL, 0xd3646c393a29f297ULL, 0x604a2087398eadf8ULL,
    /*220:*/ 0x5c3099ea6de60cffULL, 0xef1ed5546e415390ULL, 0xa8b4afbdc5a6aca4ULL, 0x1b9ae303c601f3cbULL,
    /*224:*/ 0x56ed3e2f9e224471ULL, 0xe5c372919d851b1eULL, 0xa26908783662e42aULL, 0x114744c635c5bb45ULL,
    /*228:*/ 0x2d3dfdab61ad1a42ULL, 0x9e13b115620a452dULL, 0xd9b9cbfcc9edba19ULL, 0x6a978742ca4ae576ULL,
    /*232:*/ 0xa14cb926613cf817ULL, 0x1262f598629ba778ULL, 0x55c88f71c97c584cULL, 0xe6e6c3cfcadb0723ULL,
    /*236:*/ 0xda9c7aa29eb3a624ULL, 0x69b2361c9d14f94bULL, 0x2e184cf536f3067fULL, 0x9d36004b35545910ULL,
    /*240:*/ 0x2b769f17cf112238ULL, 0x9858d3a9ccb67d57ULL, 0xdff2a94067518263ULL, 0x6cdce5fe64f6dd0cULL,
    /*244:*/ 0x50a65c93309e7c0bULL, 0xe388102d33392364ULL, 0xa4226ac498dedc50ULL, 0x170c267a9b79833fULL,
    /*248:*/ 0xdcd7181e300f9e5eULL, 0x6ff954a033a8c131ULL, 0x28532e49984f3e05ULL, 0x9b7d62f79be8616aULL,
    /*252:*/ 0xa707db9acf80c06dULL, 0x14299724cc279f02ULL, 0x5383edcd67c06036ULL, 0xe0ada17364673f59ULL
};
#define CRC_STOP_SEC_CONST_64
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"

/**
 **********************************************************************************************************************
 * Crc_CalculateCRC64
 *
 * \brief Calculates the remainder of a polynomial division: input is divided by the CRC64_ECMA polynomial
 *
 * Crc_CalculateCRC64 calculates the remainder of a polynomial division by the CRC polynomial with Hex-value
 * 0x142F0E1EBA9EA3693.
 *
 * CRC calculation starts with an initial value, Crc_StartValue64. 
 *
 * The CRC remainder is calculated over a reflected data stream *Crc_DataPtr of length Crc_Length.  The resulting CRC 
 * remainder is also reflected. The final remainder is then combined with the value of CRC_XOR_VALUE64 using a bitwise 
 * XOR operation.
 *
 * To reduce the computation time required to reflect the incoming data stream and the final result, the CRC polynomial 
 * is reflected instead. 
 * Using the reflected CRC polynomial with unreflected input and output results in the same CRC value
 * as using the truncated polynomial with reflected input and output data.
 * The reflected CRC64 ECMA polynomial for the truncated polynomial 0x42F0E1EBA9EA3693 is 0xC96C5795D7870F42.
 *
 * \param    Crc_DataPtr       Pointer to start address of data block
 * \param    Crc_Length        Length of data block to be calculated in bytes
 * \param    Crc_StartValue64  Start value when the algorithm starts
 * \param    Crc_IsFirstCall   Set to TRUE when this is the first call in a sequence or an individual CRC calculation.
 *                             Calculation starts from CRC_INITIAL_VALUE64, the parameter Crc_StartValue64 is ignored.
 *                             Set to FALSE when this is a subsequent call in a call sequence, Crc_StartValue64 is 
 *                             taken as the unmodified return value of the previous call to this function.
 * \return                     Remainder after polynomial division *const Crc_DataPtr / CRC64
 **********************************************************************************************************************
 */
uint64 Crc_CalculateCRC64(const uint8* Crc_DataPtr, uint32 Crc_Length, uint64 Crc_StartValue64,
                          boolean Crc_IsFirstCall)
{
    uint64       result_u64;
    uint32_least index_u32;


    if (TRUE == Crc_IsFirstCall)
    {
        result_u64 = CRC_INITIAL_VALUE64;
    }
    else
    {
        result_u64 = Crc_StartValue64 ^ CRC_XOR_VALUE64;
    }

    for (index_u32 = 0U; index_u32 < Crc_Length; ++index_u32)
    {
        /* Impact of temporary remainder on next crc remainder */
        result_u64 ^= Crc_DataPtr[index_u32];

        result_u64 = (result_u64 >> CRC_64_REV_ECMA182_CHUNK_SIZE)
                     ^ CRC_64_REV_ECMA182_Tbl[ (uint8)result_u64 ];
    }

    result_u64 = result_u64 ^ CRC_XOR_VALUE64;


    return (result_u64);
}

#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"
