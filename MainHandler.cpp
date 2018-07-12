#include "MainHandler.h"



MainHandler::MainHandler() {
	testObj = EnigVAO(new float[6]{ 0.1f, 0, 0.1f, 0.1f, 0, 0.1f }, 2, new int[3]{ 0, 1, 2 }, 3, 1);
}

bool MainHandler::setup() {
	testObj = EnigVAO(new float[6]{ 0.1f, 0, 0.1f, 0.1f, 0, 0.1f }, 2, new int[3]{ 0, 1, 2 }, 3, 3);
	return true;
}

bool MainHandler::loop() {
	int vaa = 0;
	testObj.fullRender(&vaa, 1);
	return true;
}

void * MainHandler::cleanup() {
	return 0;
}


MainHandler::~MainHandler() {
}
