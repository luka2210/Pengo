#include "Border.h"
#include "Glut.h"

Border::Border(double x, double y, double width, double height, double thickness) {
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	this->thickness = thickness;
}

void Border::draw() {
	//left border
	glColor3f(1.0, 1.0, 1.0);
	if (activatedLeft)
		glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + thickness, y);
	glVertex2f(x + thickness, y + height);
	glVertex2f(x, y + height);
	glEnd();
	//right border
	glColor3f(1.0, 1.0, 1.0);
	if (activatedRight)
		glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(x + width - thickness, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x + width - thickness, y + height);
	glEnd();
	//top border
	glColor3f(1.0, 1.0, 1.0);
	if (activatedTop)
		glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(x, y + height);
	glVertex2f(x, y + height - thickness);
	glVertex2f(x + width, y + height - thickness);
	glVertex2f(x + width, y + height);
	glEnd();
	//bottom border
	glColor3f(1.0, 1.0, 1.0);
	if (activatedTop)
		glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x, y + thickness);
	glVertex2f(x + width, y + thickness);
	glVertex2f(x + width, y);
	glEnd();
}
