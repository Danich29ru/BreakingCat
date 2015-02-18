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

#ifndef __FLTUSED__
#define __FLTUSED__
   __declspec(selectany) int _fltused = 1;
#endif


typedef struct tagBCRECT
{
	int _top, _bottom, _left, _right;
}bcRect;

typedef struct tagBCFONT
{
	unsigned int _textures[COUNT_OF_SYMBOLS_IN_FONT];
}bcFont;

typedef struct tagBCMAPCELL
{
	unsigned char _type;
}bcMapCell;

typedef enum { false, true } bool;
typedef unsigned char Font;
typedef unsigned int Texture;

enum E_MAP_TEXTURE
{
	BC_MAP_BACKGROUND = 0,
	BC_MAP_CELL_BACKGROUND,
	BC_MAP_LAB,
	BC_MAP_COUNT
};

enum BC_GAME_STATE
{
	BC_LOGO = 0,
	BC_GAME,
	BC_HELP
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
#include"ui.h"
#include"input.h"