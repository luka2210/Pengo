#pragma once
#include "RgbImage.h"
#include "Glut.h"

class Block {
public:
	static double width, height;
	static double offsetX, offsetY;
	static GLuint texture;

	int i, j;
	double speed;
	bool moveLeft = false, moveRight = false, moveUp = false, moveDown = false;
	double distance = 0.0;
	bool destroyed = false;
	bool moving = false;

	Block(int i, int j);
	void draw();
	void move();
};

