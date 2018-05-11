#include "Window.h"

Window::Window(int maxFrames, const char windName[], int width, int height) {
	window = glfwCreateWindow(width, height, windName, NULL, NULL);
	glfwMakeContextCurrent(window);
}
Window::Window(int maxFrames, char windName[]) {
	window = glfwCreateWindow(640, 480, windName, NULL, NULL);
	glfwMakeContextCurrent(window);
}
Window::~Window() {
	glfwDestroyWindow(window);
	delete[] name;
	delete window;
}