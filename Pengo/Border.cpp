#include "Border.h"
#include "Glut.h"
#include "LoadTexture.h"

RgbImage Border::imageHorizontal("textures/HorizontalBorder.bmp");
RgbImage Border::imageVertical("textures/VerticalBorder.bmp");

Border::Border() {}

void Border::draw() {
	glEnable(GL_TEXTURE_2D);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//left border
	LoadTexture::image(imageVertical);
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
	LoadTexture::image(imageVertical);
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
	LoadTexture::image(imageHorizontal);
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
	LoadTexture::image(imageHorizontal);
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

	glDisable(GL_TEXTURE_2D);
}
