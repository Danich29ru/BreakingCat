#pragma once

#include"common.h"

typedef unsigned char Font;

extern Font bcCreateFont(const unsigned int _color);
extern void bcDeleteFont(Font* _font);
extern void bcDrawText(Font _font, wchar_t* _text, const unsigned char _pixelScale, Rect _rc);