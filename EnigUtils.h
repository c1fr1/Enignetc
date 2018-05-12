#ifndef E__UTILS
#define E__UTILS
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

extern bool glewInited;
void checkGLError();
bool tryGlewInit();

#endif //E__UTILS
