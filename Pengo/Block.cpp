#include "Block.h"
#include "Glut.h"
#include "LoadTexture.h"

Block::Block(int i, int j, double offsetX, double offsetY) {
	this->i = i;
	this->j = j;
	this->offsetX = offsetX;
	this->offsetY = offsetY;
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
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	LoadTexture::file("textures/Block.bmp");

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

	glDisable(GL_TEXTURE_2D);
}

void Block::move()
{
}



