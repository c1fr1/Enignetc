#include "EnigVBO.h"

EnigVBO::EnigVBO(float* vInfo, int vertexCount, short vertexSize) {
	vectorSize = vertexSize;
	glGenBuffers(1, &id);
	setInfo(vInfo, vertexCount);
}

void EnigVBO::setInfo(float* nInfo, int vertexCount) {
	vectorCount = vertexCount;
	info = nInfo;
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, vectorCount * vectorSize * sizeof(float), nInfo, GL_STATIC_DRAW);
}

GLuint EnigVBO::getID()
{
	return id;
}

float* EnigVBO::getInfo() {
	return info;
}

int EnigVBO::getLength() {
	return vectorCount;
}

short EnigVBO::getVectorSize() {
	return vectorSize;
}

EnigVBO::~EnigVBO() {
	glDeleteBuffers(1, &id);
	if (!info) {
		delete[] info;
	}
}
