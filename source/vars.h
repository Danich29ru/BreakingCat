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

extern unsigned int g_Game_Money;
extern unsigned int g_Game_Experience;
extern unsigned int g_Game_RawMaterials_V;
extern unsigned int g_Game_RawMaterials_N;
extern unsigned int g_Game_Product_1;
extern unsigned int g_Game_Product_2;
extern unsigned int g_Game_Chemists;
extern unsigned int g_Game_Farmers;
extern unsigned int g_Game_Addicts;
extern unsigned int g_Game_Hucksters;