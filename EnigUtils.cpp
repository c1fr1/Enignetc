#include "EnigUtils.h"

bool glewInited = false;

void checkGLError() {
	GLint error;
	while (error = glGetError()) {
		std::cout << error;
	}
}

bool tryGlewInit() {//0 glew init failed; 1 glew init succeeded; 2 glew init already done;
	if (glewInited) {
		return 2;
	} else {
		if (glewInit()) {
			std::cout << "the chicken flesh is not raw" << std::endl;
			exit(EXIT_FAILURE);
			return 0;
		}else {
			glewInited = true;
			return 1;
		}
	}
}