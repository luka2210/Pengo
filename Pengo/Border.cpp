#include "Border.h"
#include "Glut.h"
#include "LoadTexture.h"

Border::Border(double x, double y, double width, double height, double thickness) {
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	this->thickness = thickness;
}

void Border::draw() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//left border
	LoadTexture::file("textures/VerticalBorder.bmp");
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(x, y);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(x + thickness, y);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(x + thickness, y + height);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(x, y + height);
	glEnd();

	//right border
	LoadTexture::file("textures/VerticalBorder.bmp");
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(x + width - thickness, y);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(x + width, y);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(x + width, y + height);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(x + width - thickness, y + height);
	glEnd();


	//top border
	LoadTexture::file("textures/HorizontalBorder.bmp");
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(x, y + height);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(x, y + height - thickness);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(x + width, y + height - thickness);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(x + width, y + height);
	glEnd();
	
	//bottom border
	LoadTexture::file("textures/HorizontalBorder.bmp");
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(x, y);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(x, y + thickness);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(x + width, y + thickness);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(x + width, y);
	glEnd();
}
