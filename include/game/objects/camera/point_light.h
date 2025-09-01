#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "object.h"
#include "gfx/model.h"
#include "actor_config.h"

typedef struct {
    u8 field_0x00[8];
    u32 field_0x08;
} struct_15;

typedef struct PointLightData {
    u8 field_0x00[2];
    s16 field_0x02;
    Vec3f position;
    Vec2f max_light_distance;
    RGBA color;
    struct_15 field_0x1C;
} PointLightData;

// ID: 0x006F
typedef struct PointLight {
    ObjectHeader header;
    u8 field_0x20[20];
    PointLightData data;
    u8 field_0x5C[20];
    ActorConfig* settings;
} PointLight;

extern void pointLight_entrypoint(PointLight* self);

#endif
