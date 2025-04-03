#ifndef ENTRANCE_MAP_NAME_DISPLAY_H
#define ENTRANCE_MAP_NAME_DISPLAY_H

#include "actor.h"
#include "objects/menu/mfds.h"

// Text IDs for `entranceMapNameDisplay_mapList`
typedef enum EntranceMapNameID {
    ENTRANCE_MAP_NAME_NONE         = -1,
    ENTRANCE_MAP_NAME_MORI         = 0,
    ENTRANCE_MAP_NAME_TOUOKUJI     = 1,
    ENTRANCE_MAP_NAME_NAKANIWA     = 2,
    ENTRANCE_MAP_NAME_CHIKA_KODO   = 3,
    ENTRANCE_MAP_NAME_CHIKA_SUIRO  = 4,
    ENTRANCE_MAP_NAME_HONMARU_B1F  = 5,
    ENTRANCE_MAP_NAME_KETTOU_TOU   = 6,
    ENTRANCE_MAP_NAME_KAGAKU_TOU   = 7,
    ENTRANCE_MAP_NAME_SHOKEI_TOU   = 8,
    ENTRANCE_MAP_NAME_MAHOU_TOU    = 9,
    ENTRANCE_MAP_NAME_TOU_TURO     = 10,
    ENTRANCE_MAP_NAME_TOKEITOU_NAI = 11,
    ENTRANCE_MAP_NAME_TENSHU       = 12
} EntranceMapNameID;

// ID: 0x213A
typedef struct EntranceMapNameDisplay {
    ObjectHeader header;
    u8 field_0x20[4];
    /**
     * The background model (the small rectangle rendered behind the map name's text)
     */
    Model* bg_model;
    u8 field_0x28[16];
    s32 bg_model_transparency;
    Vec2f text_position_offset;
    u8 field_0x44[4];
    s32 max_active_time;
    s32 current_active_time;
    /**
     * Hides the map name's text (but not the background model)
     */
    s32 should_hide;
    MfdsState* map_name_textbox;
    s32 hide_text;
    s32 field_0x5C;
    EntranceMapNameID text_ID;
    u8 field_0x64[12];
    ActorConfig* settings;
} EntranceMapNameDisplay;

void EntranceMapNameDisplay_entrypoint(EntranceMapNameDisplay* self);
void EntranceMapNameDisplay_init(EntranceMapNameDisplay* self);
void EntranceMapNameDisplay_show(EntranceMapNameDisplay* self);
void EntranceMapNameDisplay_idle(EntranceMapNameDisplay* self);
void EntranceMapNameDisplay_hide(EntranceMapNameDisplay* self);
void EntranceMapNameDisplay_destroy(EntranceMapNameDisplay* self);

typedef void (*EntranceMapNameDisplayFunc)(EntranceMapNameDisplay*);

#endif
