#include"common.h"
#include"input.h"

void bcGetMousePos(long* _x, long* _y)
{
	POINT point;

	GetCursorPos(&point);
	ScreenToClient(g_hWnd, &point);

	(*_x) = point.x;
	(*_y) = point.y;
}