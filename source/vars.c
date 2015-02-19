#include"vars.h"

unsigned int g_GameState = 0;
bool g_IsExit = false;
HWND g_hWnd = 0;
HDC g_hDC = 0;
HGLRC g_hGLRc = 0;
HINSTANCE g_pInst = 0;
bcFont g_Fonts[32];
unsigned char g_CountOfFonts = 0;
Font g_YellowFont = 0;
Font g_WhiteFont = 0;
Texture g_MapTextures[BC_MAP_COUNT];

unsigned int g_Game_Money = 50000;
unsigned int g_Game_Experience = 0;
unsigned int g_Game_RawMaterials_V = 0;
unsigned int g_Game_RawMaterials_N = 0;
unsigned int g_Game_Product_1 = 0;
unsigned int g_Game_Product_2 = 0;
unsigned int g_Game_Chemists = 0;
unsigned int g_Game_Farmers = 0;
unsigned int g_Game_Addicts = 0;
unsigned int g_Game_Hucksters = 0;