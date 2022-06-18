#pragma once
#include "RgbImage.h"

class Block {
private:
	static RgbImage image;
	static double width, height;
	static double offsetX, offsetY;

	int i, j;
	double speed;
	bool moveLeft = false, moveRight = false, moveUp = false, moveDown = false;
	double distance = 0.0;
	bool destroyed = false;
	bool moving = false;
public:
	Block(int i, int j);
	void draw();
	void move();
	inline static RgbImage& getImage() { return image; }
};

