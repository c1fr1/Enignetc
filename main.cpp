#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "EnigUtils.h"
#include "EnigWindow.h"
#include "MainHandler.h"


int main(void) {
	EnigWindow window = EnigWindow("test01", 640, 400);
	window.run(new MainHandler());
	glfwTerminate();
	
	return 0;
}