#include "VBOList.h"

VBOList::VBOList(void) {
}

VBOList::VBOList(EnigVBO firstObject) {
	nextObj = 0;
	object = firstObject;
	firstObj = 0;
	setThis();
}

VBOList::VBOList(EnigVBO * objects, int length) {
	nextObj = 0;
	object = *objects;
	firstObj = 0;
	setThis();
	for (int i = 1; i < length; ++i) {
		add(objects[i]);
	}
}

void VBOList::add(EnigVBO other) {
	if (!nextObj) {
		nextObj = new VBOList(other, firstObj);
	} else {
		nextObj->add(other);
	}
}

EnigVBO VBOList::operator[](int index) {
	EnigVBO vbo = (*firstObj).get(index);
	return vbo;
}

EnigVBO VBOList::first() {
	return (*firstObj).object;
}

void VBOList::forEach(void(*inner)(EnigVBO)) {
	inner(object);
	if (!nextObj) {
		nextObj->forEach(inner);
	}
}

void VBOList::forEachEnumerated(void(*inner)(EnigVBO, int), int index) {
	inner(object, index);
	if (!nextObj) {
		nextObj->forEachEnumerated(inner, index + 1);
	}
}

int VBOList::getSize() {
	return firstObj->pastThis();
}

VBOList::~VBOList() {
	if (this != firstObj) {
		if (!firstObj) {
			delete firstObj;
		}
	}
	delete nextObj;
}

VBOList::VBOList(EnigVBO lobject, VBOList* first) {
	nextObj = 0;
	object = lobject;
	firstObj = first;
}

int VBOList::pastThis() {
	if (nextObj) {
		return 1 + nextObj->pastThis();
	}else {
		return 0;
	}
}

EnigVBO VBOList::get(int index, int current) {
	if (index == current) {
		return object;
	}
	return get(index, current + 1);
}

void VBOList::setThis() {
	firstObj = this;
}
