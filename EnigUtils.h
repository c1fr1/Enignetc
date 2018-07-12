#ifndef E__UTILS
#define E__UTILS
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

void checkGLError();
bool tryGlewInit();
bool tryGLFWInit();

#endif
