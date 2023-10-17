
#include "dpad.h"

#include "assets/textures/icon_item_static/icon_item_static.h"

// Sprite/texture references.

// sprite_t sprDPad = { "__OTR__dpad", 32, 32, G_IM_FMT_IA, G_IM_SIZ_16b };                        // Need dpad.otr file!!!
sprite_t sprFairyOcarina = { gItemIconOcarinaFairyTex, 32, 32, G_IM_FMT_RGBA, G_IM_SIZ_32b };
sprite_t sprHoverBoots = { gItemIconBootsHoverTex, 32, 32, G_IM_FMT_RGBA, G_IM_SIZ_32b };
sprite_t sprIronBoots = { gItemIconBootsIronTex, 32, 32, G_IM_FMT_RGBA, G_IM_SIZ_32b };
sprite_t sprOcarinaOfTime = { gItemIconOcarinaOfTimeTex, 32, 32, G_IM_FMT_RGBA, G_IM_SIZ_32b };

u16 alpha = 0xFF;

/**
 * Handles the DPad shortcuts, such as toggling iron/hover boots
 * and playing the ocarina.
 */
void handle_dpad(PlayState* play) {
    Input* p1Input = &play->state.input[0];
    Player* player = GET_PLAYER(play);

    if (!CAN_USE_DPAD || !DISPLAY_DPAD)
        return;

    // Don't allow toggling from the pause menu if DPad Support is enabled for pause/file select.
    if (play->pauseCtx.state != 0)
        return;

    // Boots shortcuts.
    if (LINK_AGE_IN_YEARS == YEARS_ADULT) {
        // Toggle Iron Boots.
        if (CHECK_BTN_ALL(p1Input->press.button, BTN_DLEFT) && CHECK_OWNED_EQUIP(EQUIP_TYPE_BOOTS, EQUIP_VALUE_BOOTS_IRON)) {
            Inventory_ChangeEquipment(EQUIP_TYPE_BOOTS, CUR_EQUIP_VALUE(EQUIP_TYPE_BOOTS) != EQUIP_VALUE_BOOTS_IRON ? EQUIP_VALUE_BOOTS_IRON : EQUIP_VALUE_BOOTS_KOKIRI);
            Player_SetEquipmentData(play, player);
            // Audio_PlaySoundGeneral(NA_SE_PL_CHANGE_ARMS, &gSfxDefaultPos, 4, &gSfxDefaultFreqAndVolScale, &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);
        }

        // Toggle Hover Boots.
        if (CHECK_BTN_ALL(p1Input->press.button, BTN_DRIGHT) && CHECK_OWNED_EQUIP(EQUIP_TYPE_BOOTS, EQUIP_VALUE_BOOTS_HOVER)) {
            Inventory_ChangeEquipment(EQUIP_TYPE_BOOTS, CUR_EQUIP_VALUE(EQUIP_TYPE_BOOTS) != EQUIP_VALUE_BOOTS_HOVER ? EQUIP_VALUE_BOOTS_HOVER : EQUIP_VALUE_BOOTS_KOKIRI);
            Player_SetEquipmentData(play, player);
            // Audio_PlaySoundGeneral(NA_SE_PL_CHANGE_ARMS, &gSfxDefaultPos, 4, &gSfxDefaultFreqAndVolScale, &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);
        }
    }

    // Ocarina shortcut.
    if (CHECK_BTN_ALL(p1Input->press.button, BTN_DDOWN) && CAN_USE_OCARINA) {
        // Bad/undocumented function name :((((
        // @TODO Maybe extract this to a nicely named utility?
        // func_80835F44(&play, player, INV_CONTENT(ITEM_OCARINA_FAIRY) == ITEM_OCARINA_FAIRY ? ITEM_OCARINA_FAIRY : ITEM_OCARINA_TIME);
    }
}

/**
 * Draws the DPad UI.
 */
void draw_dpad(PlayState* play) {
    if (!DISPLAY_DPAD)
        return;

    OPEN_DISPS(play->state.gfxCtx, "dpad.c", 67);
    gDPPipeSync(OVERLAY_DISP++);
    gDPSetCombineMode(OVERLAY_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    alpha = play->interfaceCtx.magicAlpha;

    if (alpha == 0xAA) {
        alpha = 0xFF;
    }

    // Draw DPad Icon.
    // gDPSetPrimColor(OVERLAY_DISP++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
    // sprite_load(&sprDPad);
    // sprite_draw(&sprDPad, 271, 64, 16, 16);

    if (alpha == 0xFF && !CAN_USE_DPAD) {
        gDPSetPrimColor(OVERLAY_DISP++, 0, 0, 0xFF, 0xFF, 0xFF, 0x46);
    }

    // Draw Iron Boots
    if (CHECK_OWNED_EQUIP(EQUIP_TYPE_BOOTS, 1) && LINK_AGE_IN_YEARS != YEARS_CHILD) {
        sprite_load(play->state.gfxCtx, &sprIronBoots);

        if (CUR_EQUIP_VALUE(EQUIP_TYPE_BOOTS) == 2) {
            sprite_draw(play->state.gfxCtx, &sprIronBoots, 258, 64, 16, 16);
        } else {
            sprite_draw(play->state.gfxCtx, &sprIronBoots, 260, 66, 12, 12);
        }
    }

    // Draw Hover Boots
    if (CHECK_OWNED_EQUIP(EQUIP_TYPE_BOOTS, 2) && LINK_AGE_IN_YEARS != YEARS_CHILD) {
        sprite_load(play->state.gfxCtx, &sprHoverBoots);

        if (CUR_EQUIP_VALUE(EQUIP_TYPE_BOOTS) == 3) {
            sprite_draw(play->state.gfxCtx, &sprHoverBoots, 283, 64, 16, 16);
        } else {
            sprite_draw(play->state.gfxCtx, &sprHoverBoots, 285, 66, 12, 12);
        }
    }

    // Draw Ocarina
    if (INV_CONTENT(ITEM_OCARINA_FAIRY) == ITEM_OCARINA_FAIRY || INV_CONTENT(ITEM_OCARINA_FAIRY) == ITEM_OCARINA_OF_TIME) {
        if (alpha == 0xFF && !CAN_USE_OCARINA) {
            gDPSetPrimColor(OVERLAY_DISP++, 0, 0, 0xFF, 0xFF, 0xFF, 0x46);
        }

        sprite_load(play->state.gfxCtx, INV_CONTENT(ITEM_OCARINA_FAIRY) == ITEM_OCARINA_FAIRY ? &sprFairyOcarina : &sprOcarinaOfTime);
        sprite_draw(play->state.gfxCtx, &sprFairyOcarina, 273, 77, 12, 12); // Doesn't matter which sprite you use here since they're the same size.
    }

    gDPPipeSync(OVERLAY_DISP++);

    CLOSE_DISPS(play->state.gfxCtx, "dpad.c", 113);
}
