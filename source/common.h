#pragma once

#include<windows.h>
#include<gl/gl.h>
#include<gl/glu.h>
#include<mmsystem.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_NAME L"96k"
#define WINDOW_STYLE WS_OVERLAPPED | WS_SYSMENU | WS_CLIPSIBLINGS | WS_CLIPCHILDREN

#define COUNT_OF_SYMBOLS_IN_FONT 57
#define MAP_MAX_OBJECTS 128

#define UIBAR_SIZE 100

#ifndef __FLTUSED__
#define __FLTUSED__
   __declspec(selectany) int _fltused = 1;
#endif


typedef struct tagBCRECT
{
	unsigned int _top, _bottom, _left, _right;
}bcRect;

typedef struct tagBCFONT
{
	unsigned int _textures[COUNT_OF_SYMBOLS_IN_FONT];
}bcFont;

typedef struct tagBCMAPOBJECT
{
	unsigned char _type;
	unsigned int _x, _y;
}bcMapObject;

typedef enum { false, true } bool;
typedef unsigned char Font;
typedef unsigned int Texture;

enum E_MAP_TEXTURE
{
	BC_MAP_TEXTURE_BACKGROUND = 0,
	BC_MAP_TEXTURE_GREEN_QUAD,
	BC_MAP_TEXTURE_LAB1,
	BC_MAP_TEXTURES_COUNT
};

#pragma comment(linker,"/SECTION:.text,ERW")
#pragma comment(linker,"/MERGE:.rdata=.text")

#include"vars.h"
#include"glwnd.h"
#include"game.h"
#include"texture.h"
#include"tcbm.h"
#include"font.h"
#include"map.h"