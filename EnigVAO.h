#ifndef E__VAO
#define E__VAO
#include "EnigVBO.h"
#include "VBOList.h"
#include <iostream>
class EnigVAO {
public:
	EnigVAO();
	EnigVAO(float* vertices, int dimension, int* ind, int vertCount, int numShapes, int vps = 3);
	EnigVAO(EnigVBO* vbos, int vboCount, int* ind, int vertCount, int numShapes, int vps = 3);

	void bind();
	static void bindNil();
	
	void fullRender(int* attributePositions, int length);
	void prepareRender(int* attributePositions, int length);
	void render();
	void cleanupRender(int* attributePositions, int length);
	void customRender(int* attributePositions, int length, void (*inner)(EnigVAO*));
	
	void addVBO(EnigVBO vbo);
	void addVBO(float* info, int vertexCount, short vertexSize);

	EnigVBO operator [](int index);

	GLuint getID();
	GLuint getIBOID();
	int* getIndices();
	int getIndicesLength();
	int getShapeCount();
	int getVertexCount();

	~EnigVAO();
private:
	GLuint id;
	GLuint iboID;

	VBOList vbos;

	int* indices;
	int shapeCount;

	int vertexCount;
	int verticesPerShape;

	GLenum drawingMode;
};

#endif //E__VAO