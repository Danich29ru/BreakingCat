#include"game.h"

bool g_ShowFPS;

enum BC_BUTTON_ID
{
	BC_BUTTON_ADD_LAB = 0,
	BC_BUTTON_ADD_FARM_VALERIANA,
	BC_BUTTON_ADD_FARM_NEPETA,
	BC_BUTTON_ADD_FARMER,
	BC_BUTTON_ADD_CHEMIST,
	BC_BUTTON_ADD_SELL_PRODUCT,
};

void bcOnButtonClick(int i)
{
	switch (i)
	{
	case BC_BUTTON_ADD_LAB:
		break;
	case BC_BUTTON_ADD_FARM_VALERIANA:
		break;
	case BC_BUTTON_ADD_FARM_NEPETA:
		break;
	case BC_BUTTON_ADD_FARMER:
		break;
	case BC_BUTTON_ADD_CHEMIST:
		break;
	case BC_BUTTON_ADD_SELL_PRODUCT:
		break;
	default:
		break;
	}
}

void __inline bcRenderGameObjects()
{
	if (g_GameState == BC_GAME)
	{
		bcMapDraw();
	}

	if (g_GameState == BC_LOGO)
	{
		bcDrawLogo();
	}
}


void __inline bcRenderUI()
{
	if (g_GameState == BC_GAME)
	{
		bcDrawGameUI();
	}

	if (g_GameState == BC_HELP)
	{
		bcDrawHelpMessage();
	}
}


void __inline bcRender()
{
	bcRenderGameObjects();
	bcRenderUI();
}


void __inline bcUpdate()
{
	if (g_GameState == BC_HELP)
	{
		bcHelpMsgUpdate();
	}

	if (g_GameState == BC_GAME)
	{
		if (GetAsyncKeyState(VK_F1))
		{
			g_GameState = BC_HELP;
		}

		bcGameUIUpdate();
	}

	if (GetAsyncKeyState(VK_F2))
	{
		g_ShowFPS = g_ShowFPS == true ? false : true;
		Sleep(500);
	}
}


void __inline bcGameInit()
{
	g_GameState = BC_LOGO;
	g_ShowFPS = false;

}


void __inline bcGameShutdown()
{

}


void __inline bcGameLoop()
{
	MSG msg;
	DWORD lastTime = timeGetTime();
	DWORD currentTime = 0;
	double deltaTime = 0;
	double elapsedTime = 0.0;
	UINT FPS = 0;
	bcRect fpsRect;
	wchar_t fpsText[10] = L"0";

	fpsRect._top = 5;
	fpsRect._left = 5;
	fpsRect._bottom = 15;
	fpsRect._right = 50;

	g_YellowFont = bcCreateFont(0xFFFF0000, 0x0000FFFF);
	g_WhiteFont = bcCreateFont(0xFFFFFF00, 0x000000FF);

	bcMapInitialize();
	bcInitializeGameUI();
	bcGameInit();

	do
	{
		currentTime = timeGetTime();
		deltaTime = ((double)currentTime - (double)lastTime);

		if (deltaTime >= (1000.0 / 60.0))
		{
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			bcUpdate();
			bcBeginRender();
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			bcRender();
			if (g_ShowFPS == true)
				bcDrawText(g_YellowFont, fpsText, 2, fpsRect);
			bcEndRender();
			
			if (elapsedTime >= 1000.0)
			{
				if (g_GameState != BC_LOGO)
				{
					elapsedTime = 0.0;
				}
				else if (elapsedTime >= 4000.0 && g_GameState == BC_LOGO)
				{
					g_GameState = BC_HELP;
				}
				
				wsprintf(fpsText, L"%d", FPS);
				FPS = 0;
			}
			
			FPS++;
			elapsedTime += deltaTime;
			lastTime = currentTime;
		}
		else
		{
			Sleep(1);
		}
		
	}while(true != g_IsExit);

	bcGameShutdown();

	bcMapShutdown();
	bcDeleteFont(&g_YellowFont);
	bcDeleteFont(&g_WhiteFont);
}