#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "Window.h"
#include "VAO.h"
#include <iostream>

int main(void) {
	if (!glfwInit()) {
		return -1;
	}

	//masterVBOList = {};

	Window mainWindow = Window(60, "hey ekker", 640, 480);

	glewExperimental = true;
	glClearColor(1, 0, 0, 1);
	std::cout << "pizza motherfucker" << std::endl;
	VAO lilBoxyWoxy = VAO(new float[6]{ 0.1f, 0, 0.1f, 0.1f, 0, 0.1f }, 2, new int[3]{ 0, 1, 2 }, 3, 3);
	while (!glfwWindowShouldClose(mainWindow.window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		//lilBoxyWoxy.render();
		/* Swap front and back buffers */
		glfwSwapBuffers(mainWindow.window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	return 0;
}
