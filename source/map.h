#pragma once

#include"common.h"

extern void bcMapInitialize();
extern void bcMapShutdown();

extern void bcMapDraw();

extern void bcMapGetCell(const unsigned char _x, const unsigned char _y, bcMapCell* _object);
extern void bcMapSetCell(const unsigned char _x, const unsigned char _y, bcMapCell _object);