#include"game.h"
#include"font.h"


void __inline bcRender()
{
	
}


void __inline bcUpdate()
{
	
}


void __inline bcGameLoop()
{
	MSG msg;
	
	float lastTime = (float)timeGetTime();
	float timeDelta = 0;
	float elapsedTime = 0;

	UINT FPS = 0;
	UINT FPSTemp = 0;

	Rect fpsRect;

	wchar_t fpsText[10] = L"50";

	fpsRect._top = 5;
	fpsRect._left = 5;
	fpsRect._bottom = 15;
	fpsRect._right = 50;

	g_YellowFont = bcCreateFont(0xFFFF00FF, 0x000000FF);

	do
	{
		while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		timeDelta = (float)timeGetTime() - lastTime;
		lastTime = (float)timeGetTime();
		if (timeDelta >= 60.0f / 1000.0f)
		{
			bcUpdate();

			bcBeginRender();

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, -1.0f);

			bcDrawText(g_YellowFont, fpsText, 2, fpsRect);

			bcRender();

			bcEndRender();

			FPSTemp++;
			elapsedTime += timeDelta;
			if (elapsedTime >= 1000.0)
			{
				elapsedTime = 0;
				FPS = FPSTemp;
				FPSTemp = 0;
				wsprintf(fpsText, L"%d", FPS);
			}
		}
		else
		{
			Sleep(1);
		}
		
	}while(true != g_IsExit);

	bcDeleteFont(&g_YellowFont);
}