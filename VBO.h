#ifndef E__VERTEX_BUFFER_OBJ
#define E__VERTEX_BUFFER_OBJ
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iterator>
#include <vector>
#include <iostream>

class VBO {
public:
	VBO(float * newVal, int vertexCount, short vertexSize);
	void setInfo(float * info, int vertexCount);
	int getLength();
	float * getInfo();
	int getMasterIndex();
	short getVecSize();
	GLuint getID();
	~VBO();
private:
	int length;
	float * info;
	int masterIndex;
	short vecSize;
	GLuint id;

};

extern std::vector<VBO> masterVBOList;

#endif // E__VERTEX_BUFFER_OBJ