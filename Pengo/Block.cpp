#include "Block.h"
#include "Glut.h"

RgbImage Block::image("textures/Block.bmp");
double Block::height = 1.0;
double Block::width = 1.0;
double Block::offsetX = 0.5;
double Block::offsetY = 1.25;


Block::Block(int i, int j) {
	this->i = i;
	this->j = j;
}

void Block::draw() {
	//position of the block
	double posX = j + offsetX;
	double posY = i + offsetY;
	if (moveLeft)
		posX -= distance;
	if (moveRight)
		posX += distance;
	if (moveUp)
		posY += distance;
	if (moveDown)
		posY += distance;


	//draw block
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(posX, posY);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(posX + width, posY);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(posX + width, posY + height);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(posX, posY + height);
	glEnd();
}

void Block::move()
{
}



