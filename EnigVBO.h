#ifndef E__VBO
#define E__VBO
#include <GL\glew.h>
#include <GLFW\glfw3.h>

class EnigVBO {
public:
	EnigVBO(float* vInfo = 0, int vertexCount = 0, short vertexSize = 3);

	void setInfo(float* nInfo, int vertexCount);

	GLuint getID();

	float* getInfo();
	int getLength();
	short getVectorSize();

	~EnigVBO();
private:
	GLuint id;

	short vectorSize;

	float* info;
	int vectorCount;
};
#endif //E__VBO