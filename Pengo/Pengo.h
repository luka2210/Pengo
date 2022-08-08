#pragma once
#include "Glut.h"

class Pengo {
public:
	static GLuint pengoLeft1, pengoLeft2, pengoRight1, pengoRight2;
	static GLuint pengoUp1, pengoUp2, pengoDown1, pengoDown2;
	static GLuint pengoPushUp, pengoPushDown, pengoPushLeft, pengoPushRight;
	static double width, height;
	static double offsetX, offsetY;
	GLuint pickImage();

	int i, j;
	int orientation = 0.05;
	bool moving = false, pushing = false;
	double distance = 0;
	double speed = 0.05;
	bool stepPos = true;
	Pengo();
	Pengo(int i, int j);
	void draw();
};

