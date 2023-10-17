#ifndef GFX_ENHANCEMENT_H
#define GFX_ENHANCEMENT_H

#include "z64.h"

typedef struct {
    void* tex;
    u16 width;
    u16 height;
    u8 im_fmt;
    u8 im_siz;
} sprite_t;

void sprite_load(GraphicsContext* gfxCtx, sprite_t* sprite);
void sprite_draw(GraphicsContext* gfxCtx, sprite_t* sprite, int left, int top, int width, int height);

#endif
