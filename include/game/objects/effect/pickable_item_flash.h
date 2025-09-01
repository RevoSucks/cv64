#ifndef PICKABLE_ITEM_FLASH_H
#define PICKABLE_ITEM_FLASH_H

#include "effect.h"
#include "object.h"

// ID: 0x00E5
typedef struct PickableItemFlash {
    ObjectHeader header;
    u8 field_0x20[4];
    Model* model;
    u8 field_0x28[7];
    u8 textbox_option;
    u8 field_0x30[60];
    EffectVisualInfo* visual_info;
    ActorConfig* settings;
} PickableItemFlash;

void pickableItemFlash_entrypoint(PickableItemFlash* self);
void pickableItemFlash_init(PickableItemFlash* self);
void pickableItemFlash_loop(PickableItemFlash* self);
void pickableItemFlash_destroy(PickableItemFlash* self);

typedef void (*PickableItemFlashFunc)(PickableItemFlash*);

#endif
