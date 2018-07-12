#ifndef E__WINDOW_F
#define E__WINDOW_F
class EnigWindow;
#endif // !E__WINDOW_F

#ifndef E__HANDLER
#define E__HANDLER
#include "EnigWindow.h"

class EnigHandler {
public:
	EnigHandler();
	virtual bool setup();
	virtual bool loop();
	virtual void* cleanup();
	~EnigHandler();
private:
	EnigWindow* window;
};
#define E__HANDLER_F
#endif //E__HANDLER