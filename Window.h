#ifndef WINDOW
#define WINDOW
#include <GL\glew.h>
#include <GLFW\glfw3.h>
class Window {
public:
	GLFWwindow * window;
	bool fullScreen;
	int frameRate;
	char name[];
	Window(int maxFrames, const char windName[], int width, int height);
	Window(int maxFrames, char windName[]);
	~Window();
};
#endif // !WINDOW