#include "EnigWindow.h"

EnigWindow::EnigWindow(const char * title, int wwidth, int wheight, bool resizable, int frames) {
	tryGLFWInit();
	glfwWindowHint(GLFW_SAMPLES, 8);
	glfwWindowHint(GLFW_VISIBLE, false);
	glfwWindowHint(GLFW_RESIZABLE, resizable);
	window = glfwCreateWindow(wwidth, wheight, title, NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	tryGlewInit();
	fps = frames;
	frameDuration = 1.0 / double(frames);
	width = wwidth;
	height = wheight;
	glfwShowWindow(window);
}

EnigWindow::EnigWindow(const char * title, bool windowed, int frames) {
	tryGLFWInit();
	glfwWindowHint(GLFW_SAMPLES, 8);
	glfwWindowHint(GLFW_VISIBLE, false);
	if (windowed) {
		glfwWindowHint(GLFW_DECORATED, false);
		glfwWindowHint(GLFW_MAXIMIZED, true);
		window = glfwCreateWindow(1, 1, title, NULL, NULL);
	} else {
		GLFWvidmode vidmode = *glfwGetVideoMode(glfwGetPrimaryMonitor());
		window = glfwCreateWindow(vidmode.width, vidmode.height, title, glfwGetPrimaryMonitor(), NULL);
	}
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	tryGlewInit();
	fps = frames;
	frameDuration = 1.0 / double(frames);
	glfwGetWindowSize(window, &width, &height);

	glfwShowWindow(window);
}

void* EnigWindow::run(EnigHandler* handler) {
	if ((*handler).setup()) {
		while ((*handler).loop() && !glfwWindowShouldClose(window)) {
			//sync fps
			double timePassed = glfwGetTime() - timeOfLastFrame;
			if (timePassed < frameDuration) {
				std::this_thread::sleep_for(std::chrono::nanoseconds(int((frameDuration - timeOfLastFrame) * 1000000000)));
			}
			timeOfLastFrame = glfwGetTime();
			//unbind everything
			glBindVertexArray(0);
			glUseProgram(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindTexture(GL_TEXTURE_2D, 0);

			//swap buffers, clear framebuffer, poll events and check if there are any errors
			glfwSwapBuffers(window);
			glClear(GL_COLOR_BUFFER_BIT);//if you use FBOs at all, don't clear the framebuffer
			glfwPollEvents();
			checkGLError();

			//sets the position variables
			glfwGetCursorPos(window, &cursorX, &cursorY);
		}
		return (*handler).cleanup();
	}
	return 0;
}

int EnigWindow::getWidth() {
	return width;
}

int EnigWindow::getHeight() {
	return height;
}

int EnigWindow::getFPS() {
	return fps;
}

double EnigWindow::getFrameDuration() {
	return frameDuration;
}

void EnigWindow::setPos(int nwidth, int nheight) {
	width = nwidth;
	height = nheight;
	glfwSetWindowSize(window, width, height);
}

int EnigWindow::getKeyState(int key) {
	return glfwGetKey(window, key);
}

float EnigWindow::getCursorGLX() {
	return 2.0f * float((cursorX)/double(width)) - 1.0f;
}

float EnigWindow::getCursorGLY() {
	return 2.0f * float((cursorY) / double(height)) - 1.0f;
}

double EnigWindow::getCursorWindowX() {
	return cursorX;
}

double EnigWindow::getCursorWindowY() {
	return cursorY;
}

EnigWindow::~EnigWindow() {
	glfwDestroyWindow(window);
	glfwTerminate();
}
