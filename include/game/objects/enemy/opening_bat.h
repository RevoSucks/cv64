#ifndef OPENING_BAT_H
#define OPENING_BAT_H

#include "actor.h"

#define OPENINGBAT_NUMBER_OF_LIMBS 5 + 1

typedef struct {
    u8 field_0x00[8];
    Model* model;
    ModelLighting* lighting;
    animationMgr* animMgr;
} openingBatDataInner;

typedef struct {
    u8 field_0x00[4];
    openingBatDataInner inner;
    u8 field_0x18[144];
} openingBatData;

// ID: 0x20A6
typedef struct OpeningBat {
    ObjectHeader header;
    u8 field_0x20[4];
    Model* model;
    openingBatData* data;
    u8 field_0x2C[68];
    ActorConfig* settings;
} OpeningBat;

void openingBat_entrypoint(OpeningBat* self);
void openingBat_createData(OpeningBat* self);
void openingBat_init(OpeningBat* self);
void openingBat_loop(OpeningBat* self);
void openingBat_destroy(OpeningBat* self);

typedef void (*OpeningBatFunc)(OpeningBat*);

typedef enum OpeningBatFuncID {
    OPENINGBAT_CREATEDATA,
    OPENINGBAT_INIT,
    OPENINGBAT_LOOP,
    OPENINGBAT_DESTROY
} OpeningBatFuncID;

extern const u32 OPENINGBAT_DLIST;

#endif
