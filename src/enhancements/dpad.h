#ifndef DPAD_ENHANCEMENT_H
#define DPAD_ENHANCEMENT_H

#include "gfx.h"
#include "global.h"
#include "z64.h"

extern PlayState* play;

// Flags that block use of DPad from Link State 1
// https://wiki.cloudmodding.com/oot/Player_actor#Link_State_I
#define BLOCK_DPAD (0x00000001 | 0x00000002 | 0x00000080 | 0x00000400 | 0x10000000 | 0x20000000)

// Flags that block the use of Ocarina from Link State 1
#define BLOCK_OCARINA (0x00800000 | 0x00000800 | 0x00200000 | 0x08000000)

#define DISPLAY_DPAD                                                                                                   \
    ((CHECK_OWNED_EQUIP(EQUIP_TYPE_BOOTS, EQUIP_VALUE_BOOTS_IRON) || CHECK_OWNED_EQUIP(EQUIP_TYPE_BOOTS, EQUIP_VALUE_BOOTS_HOVER)) && (LINK_AGE_IN_YEARS == YEARS_ADULT) || \
     INV_CONTENT(ITEM_OCARINA_FAIRY) == ITEM_OCARINA_FAIRY || INV_CONTENT(ITEM_OCARINA_FAIRY) == ITEM_OCARINA_OF_TIME)

// #define CAN_USE_DPAD                                              \
//     (((GET_PLAYER(play)->stateFlags1 & BLOCK_DPAD) == 0) && \
//      ((u32)play->state.destroy == gGameStateOverlayTable[3].destroy) && (gSaveContext.gameMode == 0))
//((z64_event_state_1 & 0x20) == 0)) // @NOTE Figure out what this relates to? Pretty sure it's a flag for scene
// transition.
// Watched RAM address 0x800EF1B0 in BizHawk and it only ever flipped to 0x20 during
// scene transitions from my testing. BLOCK_DPAD should take care of this and this check
// may just be redundant in the randomizer repo.

#define CAN_USE_DPAD ((GET_PLAYER(play)->stateFlags1 & BLOCK_DPAD) == 0)

#define CAN_USE_OCARINA                                        \
    (play->pauseCtx.state == 0 &&                        \
     (INV_CONTENT(ITEM_OCARINA_FAIRY) == ITEM_OCARINA_FAIRY || \
      INV_CONTENT(ITEM_OCARINA_FAIRY) == ITEM_OCARINA_OF_TIME) && \
     !play->interfaceCtx.restrictions.ocarina && ((GET_PLAYER(play)->stateFlags1 & BLOCK_OCARINA) == 0))

void handle_dpad(PlayState* play);
void draw_dpad(PlayState* play);

#endif
