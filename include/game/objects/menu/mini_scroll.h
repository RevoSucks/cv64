#ifndef MINI_SCROLL_H
#define MINI_SCROLL_H

#include "object.h"
#include "gfx/camera.h"
#include "gfx/graphic_container.h"

// Forward declarations to avoid recursive includes
struct Model;
struct MfdsState;

typedef enum MiniScrollFlag {
    MINISCROLL_FLAG_DESTROY_IF_CLOSED = BIT(24),
    MINISCROLL_FLAG_SCROLLING_UPWARDS = BIT(24),
    MINISCROLL_FLAG_END_SCROLLING     = BIT(25),
    MINISCROLL_FLAG_CLOSED            = BIT(26),
    MINISCROLL_FLAG_OPENED            = BIT(27)
} MiniScrollFlag;

/**
 * The mini scroll's state corresponds to the
 * 15 least significant bits from `MiniScrollInner`'s `flags` field
 */
typedef enum MiniScrollState {
    MINISCROLL_STATE_OPEN             = 1, // Real name: `SCROLL_REQ_OPEN`
    MINISCROLL_STATE_CLOSE            = 2, // Real name: `SCROLL_REQ_CLOSE`
    MINISCROLL_STATE_SCROLL_UPWARDS   = 3, // Real name: `SCROLL_REQ_UP`
    MINISCROLL_STATE_SCROLL_DOWNWARDS = 4, // Real name: `SCROLL_REQ_DOWN`
    MINISCROLL_STATE_DESTROY          = 5  // Real name: `SCROLL_REQ_KILL`
} MiniScrollState;

typedef struct MiniScrollInner {
    u32 flags;
    s32 scrolling_timer;
    s32 scroll_offset; // Determines the vertical location of the texture while scrolling
    s32 scrolling_speed;
    Vec3f position;
    f32 open_max_height;
    Vec2f width;
    f32 scroll_opened_bottom_limit; // How far the scroll opens up downwards
    s32 field_0x2C;
    s32 field_0x30;
    s32 field_0x34;
    Camera* display_camera;
} MiniScrollInner;

typedef struct MiniScrollVertexBuffer {
    GraphicContainerHeader header;
    Vtx vertices[2][230];
} MiniScrollVertexBuffer;

// ID: 0x213E
typedef struct MiniScroll {
    ObjectHeader header;
    u8 field_0x20[4];
    struct Model* model;
    /**
     * Assumption based on `func_0F0011F8` from the `NI_OVL_MINI_SCROLL` overlay
     */
    struct Model* field_0x28;
    u8 field_0x2C[8];
    MiniScrollVertexBuffer* vtx_buffer;
    MiniScrollInner inner;
} MiniScroll;

/**
 * This is used sometimes to store variables related to the
 * usage of a mini scroll
 */
typedef struct MiniScrollParameters {
    s32 state;
    /**
     * Where to go (for example, what menu) after the scroll is destroyed
     */
    s32 after_quit_state;
    u32 scroll_init_delay_timer;
    MiniScroll* scroll;
    struct MfdsState* textbox;
    u8 field_0x14[44];
} MiniScrollParameters;

MiniScroll* MiniScroll_create(void* parent, Camera* camera, s32 param_3, s32 param_4);
u32 MiniScroll_checkFlags(MiniScroll* self, u32 flags);
void MiniScroll_editFlags(MiniScroll* self, u32 flags, s32 setFlags);
struct Model* MiniScroll_getModel(MiniScroll* self);
void MiniScroll_setState(MiniScroll* self, u32 state);
void MiniScroll_setScrollingParams(MiniScroll* self, f32 open_max_height, s32 scrolling_speed);
void MiniScroll_setPosition(MiniScroll* self, f32 X, f32 Y, f32 Z);
void MiniScroll_setWidth(MiniScroll* self, f32 X, f32 Y, f32 scroll_opened_bottom_limit);

extern void MiniScroll_entrypoint(MiniScroll* self);
extern void MiniScroll_init(MiniScroll* self);
extern void MiniScroll_loop(MiniScroll* self);
extern void MiniScroll_open(MiniScroll* self);
extern void MiniScroll_close(MiniScroll* self);
extern void MiniScroll_scrollUpwards(MiniScroll* self);
extern void MiniScroll_scrollDownwards(MiniScroll* self);
extern void MiniScroll_destroy(MiniScroll* self);
extern u32
MiniScroll_renderScroll(MiniScroll* self, s32 scroll_offset, s32 scroll_vertical_position);
extern void MiniScroll_animateOpen(MiniScroll* self);
extern void MiniScroll_animateClose(MiniScroll* self);
extern void MiniScroll_animateScrolling(MiniScroll* self);
extern void func_0F0011F8(MiniScroll* self);
extern void func_0F001248(MiniScroll* self);
extern void func_0F001250(MiniScroll* self);
extern void func_0F001258(MiniScroll* self);

typedef void (*MiniScrollFunc)(MiniScroll*);

#endif
