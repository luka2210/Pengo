#include "Pengo.h"
#include "Glut.h"
#include "LoadTexture.h";

RgbImage Pengo::pengoDown1("textures/PengoDown1.bmp");
RgbImage Pengo::pengoDown2("textures/PengoDown2.bmp");
RgbImage Pengo::pengoUp1("textures/PengoUp1.bmp");
RgbImage Pengo::pengoUp2("textures/PengoUp2.bmp");
RgbImage Pengo::pengoLeft1("textures/PengoLeft1.bmp");
RgbImage Pengo::pengoLeft2("textures/PengoLeft2.bmp");
RgbImage Pengo::pengoRight1("textures/PengoRight1.bmp");
RgbImage Pengo::pengoRight2("textures/PengoRight2.bmp");
RgbImage Pengo::pengoPushDown("textures/PengoPushDown.bmp");
RgbImage Pengo::pengoPushUp("textures/PengoPushUp.bmp");
RgbImage Pengo::pengoPushLeft("textures/PengoPushLeft.bmp");
RgbImage Pengo::pengoPushRight("textures/PengoPushRight.bmp");
double Pengo::height = 1.0;
double Pengo::width = 1.0;
double Pengo::offsetX = 0.5;
double Pengo::offsetY = 1.25;


RgbImage& Pengo::pickImage() {
	switch (orientation) {
	case 1:
		if (pushing)
			return pengoPushLeft;
		if (stepPos)
			return pengoLeft1;
		return pengoLeft2;
	case 2:
		if (pushing)
			return pengoPushDown;
		if (stepPos)
			return pengoDown1;
		return pengoDown2;
	case 3:
		if (pushing)
			return pengoPushRight;
		if (stepPos)
			return pengoRight1;
		return pengoRight2;
	case 4:
		if (pushing)
			return pengoPushUp;
		if (stepPos)
			return pengoUp1;
		return pengoUp2;
	default:
		return pengoDown1;
	}
}

Pengo::Pengo(int i, int j) {
	this->i = i;
	this->j = j;
}

void Pengo::draw() {
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

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	LoadTexture::image(pickImage());

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
