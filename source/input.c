#include"common.h"
#include"input.h"

void bcGetMousePos(long* _x, long* _y)
{
	POINT point;
	RECT clientRect;
	GetCursorPos(&point);
	GetClientRect(g_hWnd, &clientRect);


	(*_x) = point.x - clientRect.left;
	(*_y) = point.y - clientRect.top;
}