#pragma once

#include"common.h"

typedef GLuint Texture;

extern Texture CreateTexture();
extern void DeleteTexture(Texture* _texture);
extern void SetTextureData(Texture _texture, unsigned char _width, unsigned char _height, unsigned char* _data);
extern void DrawTexture(Texture _texture, unsigned int _x, unsigned int _y, unsigned char _width, unsigned char _height, unsigned char _pixelsize);