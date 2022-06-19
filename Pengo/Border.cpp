#include "Border.h"
#include "Glut.h"
#include "LoadTexture.h"

RgbImage Border::imageHorizontal("textures/HorizontalBorder.bmp");
RgbImage Border::imageVertical("textures/VerticalBorder.bmp");

Border::Border() {}

void Border::draw() {
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(0, 0.75);
	glVertex2f(0.5, 0.75);
	glVertex2f(0.5, 16.75);
	glVertex2f(0.0, 16.75);
	glVertex2f(13.5, 0.75);
	glVertex2f(14.0, 0.75);
	glVertex2f(14.0, 16.75);
	glVertex2f(13.5, 16.75);
	glVertex2f(0.0, 16.75);
	glVertex2f(0.0, 16.25);
	glVertex2f(14.0, 16.25);
	glVertex2f(14.0, 16.75);
	glVertex2f(0.0, 0.75);
	glVertex2f(0.0, 1.25);
	glVertex2f(14.0, 1.25);
	glVertex2f(14.0, 0.75);
	glEnd();
}
