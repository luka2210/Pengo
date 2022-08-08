#pragma once
#include "Glut.h"


class Block {
public:
	static double width, height;
	static double offsetX, offsetY;
	static unsigned int texture, textureDiamond;

	int i, j;
	bool diamond;
	double speed = 0.05;
	bool moveLeft = false, moveRight = false, moveUp = false, moveDown = false;
	double distance = 0.0;
	bool destroyed = false;
	bool moving = false;

	Block(int i, int j, bool diamond);
	unsigned int getImage();
	void draw();
	void move();
};

