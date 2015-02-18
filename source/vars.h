#pragma once

#include"common.h"

extern unsigned int g_GameState;
extern bool g_IsExit;
extern HWND g_hWnd;
extern HDC g_hDC;
extern HGLRC g_hGLRc;
extern HINSTANCE g_pInst;
extern bcFont g_Fonts[32];
extern unsigned char g_CountOfFonts;
extern Font g_YellowFont;
extern Font g_WhiteFont;
extern Texture g_MapTextures[BC_MAP_COUNT];