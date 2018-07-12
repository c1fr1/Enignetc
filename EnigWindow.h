#ifndef E__HANDLER_F
#define E__HANDLER_F
class EnigHandler;
#endif // !E__HANDLER_F


#ifndef E__WINDOW
#define E__WINDOW
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <thread>
#include <chrono>
#include "EnigUtils.h"
#include "EnigHandler.h"

class EnigWindow {
public:
	GLFWwindow* window;

	EnigWindow(const char* title, int wwidth, int wheight, bool resizable = true, int frames = 60);
	EnigWindow(const char* title, bool windowed = false, int frames = 60);

	void* run(EnigHandler* handler);

	int getWidth();
	int getHeight();

	int getFPS();
	double getFrameDuration();

	void setPos(int width, int height);

	//input
	int getKeyState(int key);

	float getCursorGLX();
	float getCursorGLY();

	double getCursorWindowX();
	double getCursorWindowY();

	~EnigWindow();
private:
	double cursorX;
	double cursorY;

	int width;
	int height;

	int fps;

	double frameDuration;
	double timeOfLastFrame;
};

#endif //E__WINDOW