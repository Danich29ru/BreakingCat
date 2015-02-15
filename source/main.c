#include"common.h"

void main()
{
	
	if(!bcInitWnd())
		ExitProcess(EXIT_FAILURE);
	if(!bcInitGL())
		ExitProcess(EXIT_FAILURE);

	bcGLSetStartValues();

	bcGameLoop();

	bcShutdownGL();
	bcShutdownWnd();

	ExitProcess(EXIT_SUCCESS);
}