#pragma once

#include"common.h"

extern bool bcInitWnd();
extern bool bcInitGL();
extern void bcShutdownWnd();
extern void bcShutdownGL();
extern void bcGLSetStartValues();
extern void bcBeginRender();
extern void bcEndRender();