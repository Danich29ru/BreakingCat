#pragma once

#include"common.h"

extern bool InitWnd();
extern bool InitGL();
extern void ShutdownWnd();
extern void ShutdownGL();
extern void GLSetStartValues();
extern void BeginRender();
extern void EndRender();