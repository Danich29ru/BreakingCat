#include"common.h"
#include<locale.h>

void main()
{
	
	if(false == InitWnd())
		ExitProcess(EXIT_FAILURE);
	if(false == InitGL())
		ExitProcess(EXIT_FAILURE);

	GLSetStartValues();

	GameLoop();

	ShutdownGL();
	ShutdownWnd();

	ExitProcess(EXIT_SUCCESS);
}