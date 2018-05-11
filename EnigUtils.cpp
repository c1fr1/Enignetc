#include "EnigUtils.h"

void checkGLError() {
	GLint error;
	while (!(error = glGetError())) {
		std::cout << error;
	}
}