#pragma once

#include"common.h"

extern Texture bcCreateTexture();
extern void bcDeleteTexture(Texture* _texture);
extern void bcSetTextureData(Texture _texture, unsigned char _width, unsigned char _height, unsigned char* _data);
extern void bcDrawTexture(Texture _texture, unsigned int _x, unsigned int _y, unsigned int _width, unsigned int _height);