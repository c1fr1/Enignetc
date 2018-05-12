#include "VAO.h"

VAO::VAO(float * vertices, int dim, int * ind, int vertCount, int indl, int vps) {
	indicesLength = indl;
	indices = ind;
	vertexCount = vertCount;
	id = 1;
	//checkGLError();
	glGenVertexArrays(1, &id);


	std::cout << "fresh chicken flesh" << std::endl;
	checkGLError();
	glBindVertexArray(id);
	vbos = {};
	vertexPerShape = vps;

	addVBO(vertices, vertexCount, dim);

	glGenBuffers(GL_ELEMENT_ARRAY_BUFFER, &iboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertexPerShape * sizeof(int), indices, GL_STATIC_DRAW);

	if (vertexPerShape == 1) {
		drawingMode = GL_POINTS;
	}
	else if (vertexPerShape == 2) {
		drawingMode = GL_LINES;
	}
	else if (vertexPerShape == 3) {
		drawingMode = GL_TRIANGLES;
	}
}

VAO::VAO(VBO * vbos, int vboCount, int * ind, int vertCount, int indl, int vps) {
	indicesLength = indl;
	indices = ind;
	vertexCount = vertCount;
	glGenVertexArrays(1, &id);
	checkGLError();
	glBindVertexArray(id);
	vbos = {};
	vertexPerShape = vps;
	for (int i = 0; i < vboCount; ++i) {
		addVBO(vbos[i]);
	}
	glGenBuffers(GL_ELEMENT_ARRAY_BUFFER, &iboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertexPerShape * sizeof(int), indices, GL_STATIC_DRAW);
	if (vertexPerShape == 1) {
		drawingMode = GL_POINTS;
	}
	else if (vertexPerShape == 2) {
		drawingMode = GL_LINES;
	}
	else if (vertexPerShape == 3) {
		drawingMode = GL_TRIANGLES;
	}
}

void VAO::render() {
	glBindVertexArray(id);
	for (GLuint i = 0; i < vbos.size(); ++i) {
		glEnableVertexAttribArray(i);
	}
	if (vertexPerShape == 1) {
		glDrawElements(drawingMode, indicesLength, GL_UNSIGNED_INT, 0);
	}
	for (int i = 0; i < vbos.size(); ++i) {
		glDisableVertexAttribArray(i);
	}
}

void VAO::addVBO(VBO vbo) {
	vbos.emplace_back(&vbo);
	glBindVertexArray(id);
	glVertexAttribPointer(vbos.size(), vbo.getVecSize(), GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo.getID());
}

void VAO::addVBO(float * val, int vertexCount, short vertexSize) {
	VBO * vbo = new VBO(val, vertexCount, vertexSize);
	vbos.emplace_back(vbo);
	glBindVertexArray(id);
	glVertexAttribPointer(vbos.size(), vbo ->getVecSize(), GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo ->getID());
}

GLuint VAO::getID() {
	return id;
}

GLuint VAO::getIBOID() {
	return iboID;
}

int * VAO::getIndices() {
	return indices;
}

VBO VAO::operator[](int index) {
	return * vbos[index];
}

int VAO::getVertexCount() {
	return vertexCount;
}

VAO::~VAO() {
	delete [] indices;
	for (VBO * pointer : vbos) {
		delete pointer;
	}
}