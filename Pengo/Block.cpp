#include "Block.h"
#include "Glut.h"

double Block::height = 1.0;
double Block::width = 1.0;
double Block::offsetX = 0.5;
double Block::offsetY = 1.25;
double Block::speed = 0.2;

unsigned int Block::texture = 0, Block::textureDiamond = 0;
unsigned int Block::textureDestroyed[] = {0, 0, 0, 0, 0, 0, 0, 0};

Block::Block(int i, int j, bool diamond) {
	this->i = i;
	this->j = j;
	this->diamond = diamond;
}

GLuint Block::getImage() {
	if (destroyed)
		return textureDestroyed[destroyedState];
	if (diamond)
		return textureDiamond;
	return texture;
}

void Block::draw() {
	//position of the block
	double posX = j + offsetX;
	double posY = i + offsetY;
	switch (orientation) {
	case 1:
		posX -= distance;
		break;
	case 2:
		posY -= distance;
		break;
	case 3:
		posX += distance;
		break;
	case 4:
		posY += distance;
		break;
	default:
		posY -= distance;
		break;
	}

	
	//draw block
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, getImage());

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



