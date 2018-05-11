#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "Window.h"
#include "VAO.h"
#include <iostream>

int main(void) {
	if (!glfwInit()) {
		return -1;
	}
	glewExperimental = GL_TRUE;
	if (!glewInit()) {
		return -1;
	}
	//masterVBOList = {};
	
	std::cout << glewExperimental << std::endl;
	VAO lilBoxyWoxy = VAO(new float[6] {1, 0, 1, 1, 0, 1}, 2, new int[3] {0, 1, 2}, 3, 3);

	/* Initialize the library */
	Window mainWindow = Window(60, "hey ekker", 640, 480);
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(mainWindow.window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		lilBoxyWoxy.render();
		/* Swap front and back buffers */
		glfwSwapBuffers(mainWindow.window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	return 0;
}
