#pragma once
class Block {
private:
	int i, j;
	const double width = 1.0, height = 1.0, speed = 0.1;
	double offsetX, offsetY;
	bool moveLeft = false, moveRight = false, moveUp = false, moveDown = false;
	double distance = 0.0;
	bool destroyed = false;
	bool moving = false;
public:
	Block(int i, int j, double offsetX, double offsetY);
	void draw();
	void move();
};

