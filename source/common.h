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
	unsigned int _top, _bottom, _left, _right;
}bcRect;

typedef struct tagBCFONT
{
	unsigned int _textures[COUNT_OF_SYMBOLS_IN_FONT];
}bcFont;

typedef enum { false, true } bool;
typedef unsigned char Font;
typedef unsigned int Texture;

#pragma comment(linker,"/SECTION:.text,ERW")
#pragma comment(linker,"/MERGE:.rdata=.text")

#include"vars.h"
#include"glwnd.h"
#include"game.h"
#include"texture.h"
#include"tcbm.h"