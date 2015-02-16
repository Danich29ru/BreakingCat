#include"game.h"


void __inline bcRenderGameObjects()
{
	bcDrawMap();
}


void __inline bcRenderUI()
{

}

void __inline bcRender()
{
	bcRenderGameObjects();
	bcRenderUI();
}


void __inline bcUpdate()
{
	
}


void __inline bcGameLoop()
{
	MSG msg;
	DWORD lastTime = 0;
	DWORD currentTime = 0;
	double deltaTime = 0;
	double elapsedTime = 0;
	UINT FPS = 0;
	bcRect fpsRect;
	wchar_t fpsText[10] = L"0";
	bcMapObject lab = { BC_MAP_TEXTURE_LAB1, 200, 200, 64, 64 };

	fpsRect._top = 5;
	fpsRect._left = 5;
	fpsRect._bottom = 15;
	fpsRect._right = 50;

	g_YellowFont = bcCreateFont(0xFFFF0000, 0x0000FFFF);

	bcInitMap();
	bcAddObjectMap(lab);

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
			bcDrawText(g_YellowFont, fpsText, 2, fpsRect);
			bcRender();
			bcEndRender();
			
			if (elapsedTime >= 1000.0)
			{
				elapsedTime = 0.0;
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

	bcFreeMap();
	bcDeleteFont(&g_YellowFont);
}