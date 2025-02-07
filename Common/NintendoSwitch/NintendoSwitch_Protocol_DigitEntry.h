/*  Digit Entry
 * 
 *  From: https://github.com/PokemonAutomation/Arduino-Source
 * 
 */

#ifndef PokemonAutomation_Protocol_SwitchDigitEntry_H
#define PokemonAutomation_Protocol_SwitchDigitEntry_H

#ifdef __AVR__
#include "NativePrograms/NintendoSwitch/Framework/Master.h"
#endif
#include "Common/Microcontroller/MessageProtocol.h"
#include "Common/NintendoSwitch/NintendoSwitch_ControllerDefs.h"

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Protocols
#if _WIN32
#pragma pack(push, 1)
#define PABB_PACK
#else
#define PABB_PACK   __attribute__((packed))
#endif
////////////////////////////////////////////////////////////////////////////////

#define PABB_MSG_COMMAND_ENTER_DIGITS                           0xa1
typedef struct{
    seqnum_t seqnum;
    uint8_t count;
    uint8_t digit_pairs[6];
} PABB_PACK pabb_enter_digits;

////////////////////////////////////////////////////////////////////////////////
#if _WIN32
#pragma pack(pop)
#endif
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#endif

