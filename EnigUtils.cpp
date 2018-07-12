#include "EnigUtils.h"

void checkGLError() {
	GLint error;
	while (error = glGetError()) {
		std::cout << error;
	}
}

bool tryGlewInit() {//0 glew init succeeded; 1 glew init failed;
	glewExperimental = true;
	if (glewInit()) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}else {
		return 1;
	}
}

bool tryGLFWInit() {
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	else {
		return 1;
	}
}