#include"glwnd.h"

LRESULT WINAPI bcWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_CLOSE:
		g_IsExit = true;
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

bool __inline bcInitWnd()
{
	WNDCLASS wc = { 0 };

	g_pInst = GetModuleHandle(0);

	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = NULL;
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hInstance = g_pInst;
	wc.lpfnWndProc = bcWndProc;
	wc.lpszClassName = WINDOW_NAME;
	wc.lpszMenuName = 0;
	wc.style = CS_OWNDC;

	RegisterClass(&wc);

	g_hWnd = CreateWindow(WINDOW_NAME, WINDOW_NAME, WINDOW_STYLE, 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0, g_pInst, 0);

	ShowWindow(g_hWnd, SW_NORMAL);
	UpdateWindow(g_hWnd);

	g_hDC = GetDC(g_hWnd);

	if (!g_hDC)
		return false;
	if (!g_hWnd)
		return false;

	return true;
}


bool __inline bcInitGL()
{
	int pixelFormat;
	PIXELFORMATDESCRIPTOR pfd = { 0 };
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;

	pixelFormat = ChoosePixelFormat(g_hDC, &pfd);
	SetPixelFormat(g_hDC, pixelFormat, &pfd);

	g_hGLRc = wglCreateContext(g_hDC);
	wglMakeCurrent(g_hDC, g_hGLRc);

	if (!g_hGLRc)
		return false;

	return true;
}


void __inline bcGLSetStartValues()
{
	glEnable(GL_TEXTURE_2D);

	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_EQUAL, GL_ZERO);
	

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0, -1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void __inline bcShutdownWnd()
{
	if (g_hWnd)
	{
		if (g_hDC)
			ReleaseDC(g_hWnd, g_hDC);
		DestroyWindow(g_hWnd);
	}
}


void __inline bcShutdownGL()
{
	wglMakeCurrent(0, 0);
	wglDeleteContext(g_hGLRc);
}


void __inline bcBeginRender()
{
	glClear(GL_COLOR_BUFFER_BIT);
}


void __inline bcEndRender()
{
	SwapBuffers(g_hDC);
}