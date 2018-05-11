#include "VBO.h"

std::vector<VBO> masterVBOList = {};

VBO::VBO(float * info, int vertexCount, short vertexSize) {
	vecSize = vertexSize;
	glGenBuffers(1, &id);
	setInfo(info, vertexCount);
	masterIndex = masterVBOList.size();
	masterVBOList.push_back(*this);
}

void VBO::setInfo(float * newVal, int vertexCount) {
	length = vertexCount;
	info = newVal;
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, length * vecSize * sizeof(float), newVal, GL_STATIC_DRAW);
}

int VBO::getLength() {
	return length;
}

float * VBO::getInfo() {
	return info;
}

int VBO::getMasterIndex() {
	return masterIndex;
}

short VBO::getVecSize() {
	return vecSize;
}

GLuint VBO::getID() {
	return id;
}

VBO::~VBO() {
	masterVBOList.erase(masterVBOList.begin() + masterIndex);
	for (int i = masterIndex; i < masterVBOList.size();++i) {
		masterVBOList[i].masterIndex -= 1;
	}
	glDeleteBuffers(1, &id);
	delete info;
}
