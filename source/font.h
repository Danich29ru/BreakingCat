#pragma once

#include"common.h"

extern Font bcCreateFont(const unsigned int _color, const unsigned int _color2);
extern void bcDeleteFont(Font* _font);
extern void bcSetAdditionalPixels(const unsigned int _n);
extern void bcDrawText(Font _font, wchar_t* _text, const int _pixelScale, bcRect _rc);