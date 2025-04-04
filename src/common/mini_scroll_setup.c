/**
 * @file mini_scroll_setup.c
 *
 * Contains different functions for creating and setting up the mini scroll,
 * used in certain scenarios, such as to display small Yes / No selection messages in front of it.
 *
 * @note The driver code that handles the actual mini scroll object can be found in the
 * `NI_OVL_MINI_SCROLL` overlay.
 */

#include "objects/menu/mini_scroll.h"
#include "game/gfx/model.h"

MiniScroll* MiniScroll_create(void* parent, Camera* camera, s32 param_3, s32 param_4) {
    MiniScroll* obj_mini_scroll;
    MiniScrollInner* inner;

    obj_mini_scroll                   = (*object_create)(parent, MENU_MINI_SCROLL);
    inner                             = &obj_mini_scroll->inner;
    inner->flags                      = 0;
    inner->scrolling_timer            = 320;
    inner->scroll_offset              = 0;
    inner->scrolling_speed            = 1;
    inner->width.x                    = 1.0f;
    inner->width.y                    = 1.0f;
    inner->scroll_opened_bottom_limit = 1.0f;
    inner->position.x                 = 0.0f;
    inner->position.y                 = 0.0f;
    inner->open_max_height            = 20.0f;

    if (param_3 != 0) {
        inner->field_0x2C = param_3;
        inner->field_0x30 = param_4;
    } else {
        inner->field_0x2C = 0;
        inner->field_0x30 = 0;
    }

    inner->field_0x34 = 0;

    if (camera != NULL) {
        inner->display_camera = camera;
    } else {
        inner->display_camera = NULL;
    }

    return obj_mini_scroll;
}

void MiniScroll_setPosition(MiniScroll* self, f32 X, f32 Y, f32 Z) {
    self->inner.position.x = X;
    self->inner.position.y = Y;
    self->inner.position.z = Z;
}

void MiniScroll_setScrollingParams(MiniScroll* self, f32 open_max_height, s32 scrolling_speed) {
    self->inner.scrolling_speed = scrolling_speed;
    self->inner.open_max_height = open_max_height;
}

void MiniScroll_setWidth(MiniScroll* self, f32 X, f32 Y, f32 scroll_opened_bottom_limit) {
    self->inner.width.x                    = X;
    self->inner.width.y                    = Y;
    self->inner.scroll_opened_bottom_limit = scroll_opened_bottom_limit;
}

Model* MiniScroll_getModel(MiniScroll* self) {
    return self->model;
}

void MiniScroll_setState(MiniScroll* self, u32 state) {
    self->inner.flags |= (state & 0xF);
}

void MiniScroll_editFlags(MiniScroll* self, u32 flags, s32 setFlags) {
    MiniScrollInner* inner = &self->inner;

    if (setFlags) {
        inner->flags |= flags;
    } else {
        inner->flags &= ~flags;
    }
}

u32 MiniScroll_checkFlags(MiniScroll* self, u32 flags) {
    return self->inner.flags & flags;
}
