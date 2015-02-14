#include"game.h"
#include"font.h"


void __inline GameLoop()
{
	MSG msg;

	do
	{
		while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		
		BeginRender();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -1.0f);

		EndRender();
		
	}while(true != g_IsExit);
}