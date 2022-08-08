#pragma once
#include "Glut.h"

class Border {
public:
	static GLuint borderVertical, borderHorizontal;

	bool activatedLeft = false, activatedRight = false, activatedTop = false, activatedBottom = false;

	Border();
	void draw();
};

