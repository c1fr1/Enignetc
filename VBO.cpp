#include "VBO.h"

std::vector<VBO> masterVBOList = {};

VBO::VBO(float * info, int vertexCount, short vertexSize) {
	vecSize = vertexSize;
	glGenBuffers(1, &id);
	std::cout << "chicken 0" << std::endl;
	setInfo(info, vertexCount);
	std::cout << "chicken 1" << std::endl;
	masterIndex = masterVBOList.size();
	std::cout << "chicken 2" << std::endl;
	masterVBOList.emplace_back(*this);
	std::cout << "chicken 3" << std::endl;
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
	delete [] info;
}
