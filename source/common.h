#pragma once

#include<windows.h>
#include<gl/gl.h>
#include<gl/glu.h>

#define MAX_STRING_SIZE 10240

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_NAME L"96k"
#define WINDOW_STYLE WS_OVERLAPPED | WS_SYSMENU | WS_CLIPSIBLINGS | WS_CLIPCHILDREN

typedef enum { false, true } bool;

#ifndef __FLTUSED__
#define __FLTUSED__
   __declspec(selectany) int _fltused = 1;
#endif

typedef struct
{
	unsigned int _top, _bottom, _left, _right;
}Rect;

#pragma comment(linker,"/SECTION:.text,ERW")
#pragma comment(linker,"/MERGE:.rdata=.text")

extern bool g_IsExit;
extern HWND g_hWnd;
extern HDC g_hDC;
extern HGLRC g_hGLRc;
extern HINSTANCE g_pInst;

#include"glwnd.h"
#include"game.h"
#include"texture.h"
#include"tcbm.h"