#include "EnigVAO.h"


EnigVAO::EnigVAO() {
}

EnigVAO::EnigVAO(float* vertices, int dimension, int* ind, int vertCount, int numShapes, int vps) {
	shapeCount = numShapes;
	indices = ind;
	vertexCount = vertCount;
	verticesPerShape = vps;

	glGenVertexArrays(1, &id);
	glBindVertexArray(id);

	EnigVBO vbo = EnigVBO(vertices, vertexCount, dimension);
	vbos = VBOList(vbo);
	glVertexAttribPointer(vbos.getSize(), vbo.getVectorSize(), GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo.getID());

	glGenBuffers(1, &iboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, verticesPerShape * sizeof(int) * shapeCount, ind, GL_STATIC_DRAW);
	
	if (verticesPerShape == 1) {
		drawingMode = GL_POINTS;
	} else if (verticesPerShape == 2) {
		drawingMode = GL_LINES;
	} else if (verticesPerShape == 3) {
		drawingMode = GL_TRIANGLES;
	}
}

EnigVAO::EnigVAO(EnigVBO * ivbos, int vboCount, int * ind, int vertCount, int numShapes, int vps) {
	shapeCount = numShapes;
	indices = ind;
	vertexCount = vertCount;
	verticesPerShape = vps;

	glGenVertexArrays(1, &id);
	glBindVertexArray(id);

	vbos = VBOList(ivbos, vboCount);

	vbos.forEachEnumerated([](EnigVBO vbobj, int index) {
		glVertexAttribPointer(index + 1, vbobj.getVectorSize(), GL_FLOAT, false, 0, 0);
		glBindBuffer(GL_ARRAY_BUFFER, vbobj.getID());
	});

	glGenBuffers(1, &iboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, verticesPerShape * sizeof(int) * shapeCount, indices, GL_STATIC_DRAW);

	if (verticesPerShape == 1) {
		drawingMode = GL_POINTS;
	}
	else if (verticesPerShape == 2) {
		drawingMode = GL_LINES;
	}
	else if (verticesPerShape == 3) {
		drawingMode = GL_TRIANGLES;
	}
}

void EnigVAO::bind() {
	glBindVertexArray(id);
}

void EnigVAO::bindNil() {
	glBindVertexArray(0);
}

void EnigVAO::fullRender(int* attributePositions, int length) {
	prepareRender(attributePositions, length);
	render();
	cleanupRender(attributePositions, length);
}

void EnigVAO::prepareRender(int* attributePositions, int length) {
	glBindVertexArray(id);
	for (int i = 0; i < length; ++i) {
		glEnableVertexAttribArray(attributePositions[i]);
	}
}

void EnigVAO::render() {
	glDrawElements(drawingMode, getIndicesLength(), GL_UNSIGNED_INT, 0);
}

void EnigVAO::cleanupRender(int * attributePositions, int length) {
	for (int i = 0; i < length; ++i) {
		glDisableVertexAttribArray(attributePositions[i]);
	}
}

void EnigVAO::customRender(int * attributePositions, int length, void(*inner)(EnigVAO *)) {
	prepareRender(attributePositions, length);
	inner(this);
	cleanupRender(attributePositions, length);
}

void EnigVAO::addVBO(EnigVBO vbo) {
	vbos.add(vbo);
	glBindVertexArray(id);
	glVertexAttribPointer(vbos.getSize(), vbo.getVectorSize(), GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo.getID());

}

void EnigVAO::addVBO(float * info, int vertexCount, short vertexSize) {
	addVBO(EnigVBO(info, vertexCount, vertexSize));
}

EnigVBO EnigVAO::operator[](int index) {
	return vbos[index];
}

GLuint EnigVAO::getID() {
	return id;
}

GLuint EnigVAO::getIBOID() {
	return iboID;
}

int * EnigVAO::getIndices() {
	return indices;
}

int EnigVAO::getIndicesLength()
{
	return shapeCount * verticesPerShape;
}

int EnigVAO::getShapeCount()
{
	return shapeCount;
}

int EnigVAO::getVertexCount()
{
	return vertexCount;
}

EnigVAO::~EnigVAO() {
	glDeleteVertexArrays(1, &id);
	glDeleteBuffers(1, &iboID);
	delete[] indices;
}