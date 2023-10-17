#include "gfx.h"

#include "global.h"
#include "z64.h"

/**
 * Simple wrapper to load a texture to be drawn.
 */
void sprite_load(GraphicsContext* gfxCtx, sprite_t* sprite) {
    OPEN_DISPS(gfxCtx, "gfx.c", 10);

    if (sprite->im_siz == G_IM_SIZ_16b) {
        gDPLoadTextureBlock(
            OVERLAY_DISP++,
            sprite->tex,
            sprite->im_fmt,
            G_IM_SIZ_16b, // @TEMP until I figure out how to use sprite->im_siz
            sprite->width, sprite->height,
            0,
            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
            G_TX_NOMASK, G_TX_NOMASK,
            G_TX_NOLOD, G_TX_NOLOD
        );
    } else {
        gDPLoadTextureBlock(
            OVERLAY_DISP++,
            sprite->tex,
            sprite->im_fmt,
            G_IM_SIZ_32b, // @TEMP until I figure out how to use sprite->im_siz
            sprite->width, sprite->height,
            0,
            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
            G_TX_NOMASK, G_TX_NOMASK,
            G_TX_NOLOD, G_TX_NOLOD
        );
    }

    CLOSE_DISPS(gfxCtx, "gfx.c", 38);
}

/**
 * Simple wrapper to draw a sprite/texture on the screen.
 * sprite_load needs to be ran right before this.
 */
void sprite_draw(GraphicsContext* gfxCtx, sprite_t* sprite, int left, int top, int width, int height) {
    int width_factor = (1 << 10) * sprite->width / width;
    int height_factor = (1 << 10) * sprite->height / height;

    OPEN_DISPS(gfxCtx, "gfx.c", 49);

    // gSPWideTextureRectangle(
    //     OVERLAY_DISP++,
    //     OTRGetRectDimensionFromRightEdge(left) << 2, top << 2,
    //     (OTRGetRectDimensionFromRightEdge(left) + width) << 2, (top + height) << 2,
    //     G_TX_RENDERTILE,
    //     0, 0,
    //     width_factor, height_factor
    // );

    gSPTextureRectangle(
        OVERLAY_DISP++,
        left<<2, top<<2,
        (left + width)<<2, (top + height)<<2,
        G_TX_RENDERTILE,
        0, 0,
        width_factor, height_factor
    );

    CLOSE_DISPS(gfxCtx, "gfx.c", 60);
}
