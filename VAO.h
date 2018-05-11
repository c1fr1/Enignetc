#ifndef E__VERTEX_ARRAY_OBJ
#define E__VERTEX_ARRAY_OBJ
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "VBO.h"
#include <vector>
#include "EnigUtils.h"

class VAO {
public:
	VAO(float * vertices = 0, int dim = 3, int * ind = 0, int vertexCount = 0, int indl = 0, int vps = 3);
	VAO(VBO * vbos = 0, int vboCount = 0, int * ind = 0, int vertCount = 0, int indl = 0, int vps = 3);
	void render();
	void addVBO(VBO vbo);
	void addVBO(float * info, int vertexCount, short vertexSize);
	GLuint getID();
	GLuint getIBOID();
	int * getIndices();
	VBO operator [](int index);
	int getVertexCount();
	~VAO();
private: 
	GLuint id;
	GLuint iboID;
	int * indices;
	int indicesLength;
	std::vector<VBO> vbos;
	int vertexCount;
	int vertexPerShape;
	GLenum drawingMode;
};

#endif // !E__VERTEX_ARRAY_OBJ