#include"game.h"
#include"font.h"


void __inline bcGameLoop()
{
	MSG msg;

	do
	{
		while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		
		bcBeginRender();

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -1.0f);

		bcEndRender();
		
	}while(true != g_IsExit);
}