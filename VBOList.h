#ifndef VBOLIST
#define VBOLIST
#include "EnigVBO.h"
class VBOList {
public:
	VBOList(void);
	VBOList(EnigVBO firstObject);
	VBOList(EnigVBO* objects, int length);

	void add(EnigVBO other);

	EnigVBO operator [](int index);
	EnigVBO first();

	void forEach(void(*inner)(EnigVBO));
	void forEachEnumerated(void(*inner)(EnigVBO, int), int index = 0);

	int getSize();

	~VBOList();
private:
	VBOList(EnigVBO object, VBOList* first);
	int pastThis();
	EnigVBO get(int index, int current = 0);
	void setThis();

	VBOList* nextObj;
	VBOList* firstObj;
	EnigVBO object;
};

#endif //VBOLIST