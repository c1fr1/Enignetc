#include "Window.h"
#include <iostream>


Window::Window(int maxFrames, const char windName[], int width, int height) {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	window = glfwCreateWindow(width, height, windName, NULL, NULL);
	glfwMakeContextCurrent(window);
	tryGlewInit();
}
Window::Window(int maxFrames, char windName[]) {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	window = glfwCreateWindow(640, 480, windName, NULL, NULL);
	glfwMakeContextCurrent(window);
	tryGlewInit();
}
Window::~Window() {
	glfwDestroyWindow(window);
	delete[] name;
	delete window;
}