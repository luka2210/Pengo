#include "Border.h"
#include "Glut.h"
#include "LoadTexture.h"

RgbImage Border::imageHorizontal("textures/HorizontalBorder.bmp");
RgbImage Border::imageVertical("textures/VerticalBorder.bmp");

Border::Border() {}

void Border::draw() {
	//glEnable(GL_TEXTURE_2D);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//LoadTexture::image(Border::imageVertical);
	glBegin(GL_QUADS);
	//glTexCoord2f(0.0, 0.0);
	glVertex2f(0, 0.75);
	//glTexCoord2f(1.0, 0.0);
	glVertex2f(0.5, 0.75);
	//glTexCoord2f(1.0, 1.0);
	glVertex2f(0.5, 16.75);
	//glTexCoord2f(0.0, 1.0);
	glVertex2f(0.0, 16.75);
	glEnd();

	//LoadTexture::image(Border::imageVertical);
	glBegin(GL_QUADS);
	glVertex2f(13.5, 0.75);
	glVertex2f(14.0, 0.75);
	glVertex2f(14.0, 16.75);
	glVertex2f(13.5, 16.75);
	glEnd();

	//LoadTexture::image(Border::imageHorizontal);
	glBegin(GL_QUADS);
	glVertex2f(0.0, 16.75);
	glVertex2f(0.0, 16.25);
	glVertex2f(14.0, 16.25);
	glVertex2f(14.0, 16.75);
	glEnd();


	//glEnable(GL_TEXTURE_2D);
	//LoadTexture::image(Border::imageHorizontal);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(0.0, 0.75);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(0.0, 1.25);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(14.0, 1.25);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(14.0, 0.75);
	glEnd();

	//glDisable(GL_TEXTURE_2D);
}
