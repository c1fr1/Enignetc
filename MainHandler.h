#ifndef MHANDLER
#define MHANDLER
#include "EnigHandler.h"
#include "EnigVAO.h"
class MainHandler: public EnigHandler {
public:
	MainHandler();
	bool setup();
	bool loop();
	void* cleanup();
	~MainHandler();
private:
	EnigVAO testObj;
};
#endif // !MHANDLER